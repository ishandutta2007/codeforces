//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

const int N = 101'000;
int n, com;
int siz[100];
vector <int> zli[100];
vector <int> st;
char s[N];
char t[N];

void ins(int x) {
	x += com;
	while (x) {
		++st[x];
		x >>= 1;
	}
}

int zap(int a, int b) {
	a += com;
	b += com;
	int ret = 0;
	while (a <= b) {
		if (a & 1) {
			ret += st[a++];
		}
		if (!(b & 1)) {
			ret += st[b--];
		}
		a >>= 1;
		b >>= 1;
	}
	return ret;
}

void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for (int i = 0; i < 26; ++i) {
		siz[i] = 0;
		zli[i].clear();
	}
	st.resize(0);
	com = 1;
	while (com < n) {
		com <<= 1;
	}
	st.resize(com << 1);
	--com;
	long long odp = 1e18, ans = 0;
	for (int i = 1; i <= n; ++i) {
		zli[s[i] - 'a'].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		long long w = 1e18;
		for (int j = 0; j < t[i] - 'a'; ++j) {
			if (siz[j] == (int)zli[j].size()) {
				continue;
			}
			int poz = zli[j][siz[j]] + zap(zli[j][siz[j]], n);
			//~ printf("POZ = %d\n", poz);
			w = min(w, max(0ll, (long long)poz - i));
		}
		odp = min(odp, ans + w);
		if (siz[t[i] - 'a'] == (int)zli[t[i] - 'a'].size()) {
			break;
		}
		int p = zli[t[i] - 'a'][siz[t[i] - 'a']] + zap(zli[t[i] - 'a'][siz[t[i] - 'a']], n);
		//~ printf("%d\n", zap(zli[t[i] - 'a'][siz[t[i] - 'a']], n));
		//~ printf("P = %d\n", p);
		ans += max(0, p - i);
		ins(zli[t[i] - 'a'][siz[t[i] - 'a']]);
		++siz[t[i] - 'a'];
	}
	if(odp > 1e15) {
		printf("-1\n");
		return;
	}
	printf("%lld\n", odp);
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}