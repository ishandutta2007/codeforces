#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N, K;
char s[MAXN], a[MAXN], b[MAXN];
string prefA[MAXN], prefB[MAXN];
string invA[MAXN], invB[MAXN];

void load() {
	scanf("%d%s%s%s", &K, s, a, b);
}

void build(char *str, string *pref, string *inverse) {
	bool ok = true;
	string perm(K, '?'), inv(K, '?');
	for (int i = 0; i < N; i++) {
		if (perm[s[i] - 'a'] == '?') {
			if (inv[str[i] - 'a'] != '?')
				ok = false;
			else {
				perm[s[i] - 'a'] = str[i];
				inv[str[i] - 'a'] = s[i];
			}
		}
		else if (perm[s[i] - 'a'] != str[i])
			ok = false;
		if (!ok)
			perm = inv = string(K, '!');
		pref[i] = perm;
		inverse[i] = inv;
	}
}

bool check(string perm) {
	string t = "";
	for (int i = 0; i < N; i++)
		t += perm[s[i] - 'a'];
	return t >= a && t <= b;
}

void finish(string perm) {
	vector <bool> bio(K, false);
	for (int i = 0; i < K; i++)
		if (perm[i] != '?')
			bio[perm[i] - 'a'] = true;
	
	vector <int> unmapped;
	for (int i = 0; i < K; i++)
		if (!bio[i])
			unmapped.push_back(i);
	
	for (int i = 0; i < K; i++)
		if (perm[i] == '?') {
			perm[i] = unmapped.back() + 'a';
			unmapped.pop_back();
		}
	
	assert(check(perm));
	printf("YES\n%s\n", perm.c_str());
}

void solve() {
	N = strlen(s);
	
	build(a, prefA, invA);
	build(b, prefB, invB);
	
	int lcp = 0;
	for (int i = 0; i < N && a[i] == b[i]; i++)
		lcp++;	
	
	if (lcp == N) {
		if (prefA[N - 1][0] != '!')
			finish(prefA[N - 1]);
		else
			puts("NO");
		return;
	}
	
	if (lcp) {
		char &ref = prefA[lcp - 1][s[lcp] - 'a'];
		if (ref == '?') {
			for (int i = a[lcp] - 'a' + 1; i < b[lcp] - 'a'; i++)
				if (invA[lcp - 1][i] == '?') {
					ref = i + 'a';
					finish(prefA[lcp - 1]);
					return;
				}
		}
		else if (ref > a[lcp] && ref < b[lcp]) {
			finish(prefA[lcp - 1]);
			return;
		}
	}
	else if (b[0] - a[0] > 1) {
		string tmp(K, '?');
		tmp[s[0] - 'a'] = a[0] + 1;
		finish(tmp);
		return;
	}
	
	for (int i = lcp; i < N && prefB[i][0] != '!'; i++) {
		if (i == N - 1) {
			finish(prefB[i]);
			return;
		}
		char &ref = prefB[i][s[i + 1] - 'a'];
		if (ref == '?') {
			for (int j = 0; j < b[i + 1] - 'a'; j++)
				if (invB[i][j] == '?') {
					ref = j + 'a';
					finish(prefB[i]);
					return;
				}
		}
		else if (ref < b[i + 1]) {
			finish(prefB[i]);
			return;
		}
	}
	
	for (int i = lcp; i < N && prefA[i][0] != '!'; i++) {
		if (i == N - 1) {
			finish(prefA[i]);
			return;
		}
		char &ref = prefA[i][s[i + 1] - 'a'];
		if (ref == '?') {
			for (int j = a[i + 1] - 'a' + 1; j < K; j++)
				if (invA[i][j] == '?') {
					ref = j + 'a';
					finish(prefA[i]);
					return;
				}
		}
		else if (ref > a[i + 1]) {
			finish(prefA[i]);
			return;
		}
	}
	
	puts("NO");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}