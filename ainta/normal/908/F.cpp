#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[301000];
int X[301000];
int n;
int main() {
	int i, j;
	scanf("%d", &n);
	vector<int>P;
	for (i = 1; i <= n; i++) {
		scanf("%d", &X[i]);
		scanf("%s", p + i);
		if (p[i] == 'G')P.push_back(i);
	}
	long long res = 0;
	if (P.empty()) {
		int ck = 0;
		int Mn = 1e9;
		res = X[n] - X[1];
		int b1 = 1e9, e1 = 0, b2 = 1e9, e2 = 0;
		for (i = 1; i < n; i++) {
			if (p[i] != p[i + 1]) {
				ck = 1;
				Mn = min(Mn, X[i + 1] - X[i]);
			}
		}
		for (i = 1; i <= n; i++) {
			if (p[i] == 'B')b1 = min(b1, X[i]), e1 = max(e1, X[i]);
			if (p[i] == 'R')b2 = min(b2, X[i]), e2 = max(e2, X[i]);
		}
		if (ck) {
			res = e1 + e2 - b1 - b2;
		//	res += Mn;
		}
		printf("%lld\n", res);
		return 0;
	}
	for (int ii = 0; ii < P.size() - 1; ii++) {
		int b = P[ii], e = P[ii + 1];
		vector<int>X1, X2;
		for (j = b + 1; j < e; j++) {
			if (p[j] == 'R')X1.push_back(X[j]);
			if (p[j] == 'B')X2.push_back(X[j]);
		}
		long long s1 = 0, s2 = 0, M;
		if (!X1.empty())s1 = min(X[e] - X1[0], X1.back() - X[b]);
		if (!X2.empty())s2 = min(X[e] - X2[0], X2.back() - X[b]);
		for (i = 0; i+1 < X2.size(); i++)s2 = min(s2, 0ll + X[e] - X[b] - (X2[i + 1] - X2[i]));
		for (i = 0; i+1 < X1.size(); i++)s1 = min(s1, 0ll + X[e] - X[b] - (X1[i + 1] - X1[i]));
		M = min((X[e] - X[b]) * 2 + 0ll, s1 + s2 + X[e] - X[b]);
		res += M;
	}
	int b1 = X[P[0]], b2 = X[P[0]];
	for (i = P[0] - 1; i >= 1; i--) {
		if (p[i] == 'R')b1 = X[i];
		if (p[i] == 'B')b2 = X[i];
	}
	res += X[P[0]] * 2 - b1 - b2;
	b1 = b2 = X[P.back()];
	for (i = P.back() + 1; i <= n; i++) {
		if (p[i] == 'R')b1 = X[i];
		if (p[i] == 'B')b2 = X[i];
	}
	res += b1 + b2 - X[P.back()] * 2;
	printf("%lld\n", res);
}