#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)1e5 + 10, p = (int)1e9 + 7, q = (int)1e9 + 9;
char s[maxn];

pii st[maxn];

int my_rand() {
	if (RAND_MAX == 32767) {
		return rand() * RAND_MAX + rand();
	}

	return rand();
}

string t[maxn];
int k[maxn];
int num[maxn];

bool cmp(int a, int b) {
	return (int)t[a].size() < t[b].size();
}

pii operator +(pii a, pii b) {
	a.first += b.first;

	if (a.first >= p) {
		a.first -= p;
	}

	a.second += b.second;

	if (a.second >= q) {
		a.second -= q;
	}

	return a;
}

pii operator -(pii a, pii b) {
	a.first -= b.first;

	if (a.first < 0) {
		a.first += p;
	}

	a.second -= b.second;

	if (a.second < 0) {
		a.second += q;
	}

	return a;
}

pii operator *(pii a, pii b) {
	a.first = (ll)a.first * b.first % p;
	a.second = (ll)a.second * b.second % q;

	return a;
}

vector <int> g[maxn];

pii tab[1 << 19];
int it[1 << 19];
int gg = (1 << 19) - 1;
int iter = 0;

void add(int ps, int hs, int x) {
	ps &= gg;

	if (it[ps] != iter) {
		it[ps] = iter;
		tab[ps] = mp(hs, x);
	}
	else {
		add(ps + 1, hs, x);
	}
}

pii operator +(pii a, int x) {
    a.first += x;
    a.second += x;
    
    if (a.first >= p) {
        a.first -= p;
    }
    
    if (a.second >= q) {
        a.second -= q;
    }
    
    return a;
}

pii get_hsh(int ps) {
	pii cur = mp(0, 0);
	
	for (int i = 0; i < (int)t[ps].size(); i++) {
		cur = cur * st[1] + (t[ps][i] - 'a' + 1);
	}

	return cur;
}

int go(int ps, int hs) {
	ps &= gg;

	if (it[ps] != iter) {
		return -1;
	}

	if (tab[ps].first == hs) {
		return tab[ps].second;
	}

	return go(ps + 1, hs);
}

int ans[maxn];
pii sum[maxn];

pii get_sum(int l, int r) {
	r++;

	return sum[r] - sum[l] * st[r - l];
}

int main() {
	srand(time(NULL));

	st[0] = mp(1, 1);

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * mp(1234567, 1234567);
	}

	scanf("%s", s);
	int len = strlen(s);

	pii cur = mp(0, 0);
	sum[0] = cur;

	for (int i = 0; i < len; i++) {
		sum[i + 1] = sum[i] * st[1] + (s[i] - 'a' + 1);
	}

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		char c;
		num[i] = i;

		scanf("%d ", &k[i]);

		while (scanf("%c", &c) != EOF) {
			if (c == '\n') {
				break;
			}
				
			t[i] += c;
		}

		ans[i] = len + 1;
	}

	sort(num, num + n, cmp);

	for (int i = 0; i < n;) {
		iter++;

		int r = i;

		while (r < n && t[num[i]].size() == t[num[r]].size()) {
			r++;
		}

		for (int j = i; j < r; j++) {
			pii f = get_hsh(num[j]);

			add(f.first, f.second, num[j]);
		}

		int d = (int)t[num[i]].size();

		pii cur = mp(0, 0);

		if (d > len) {
			break;
		}

		for (int j = 0; j <= len - d; j++) {
			pii cur = get_sum(j, j + d - 1);
			int numb = go(cur.first, cur.second);

			if (numb != -1) {
				g[numb].push_back(j);
				
				if ((int)g[numb].size() >= k[numb]) {
					ans[numb] = min(ans[numb], g[numb].back() - g[numb][(int)g[numb].size() - k[numb]]);
				}
			}
		}

		i = r;
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == len + 1) {
			printf("-1\n");
		}
		else {
			printf("%d\n", ans[i] + (int)t[i].size());
		}
	}

	//system("pause");
}