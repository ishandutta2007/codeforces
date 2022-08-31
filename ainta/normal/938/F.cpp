#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[5010];
int n, v[5010], MM;
vector<int>U[26];
void Do(vector<int>&V, int cur) {
	int i, j, k, ck = 0;
	if (cur == n - MM)return;
	for (i = 0; i <= n; i++)v[i] = 0;
	for (auto &tp : V) {
		int mask = MM - (tp - cur);
		if (mask + tp >= n)continue;
		for (j = mask;; j = (j - 1)&mask) {
			v[tp + j] = 1;
			if (!j)break;
		}
	}
	int Mn = 1e9;
	for (i = 0; i < n; i++) {
		if (v[i] && Mn > p[i])Mn = p[i];
	}
	printf("%c", Mn);
	vector<int>V2;
	for (i = 0; i < n; i++) {
		if (v[i] && Mn == p[i]) {
			V2.push_back(i + 1);
		}
	}
	Do(V2, cur + 1);
}
int main() {
	int i, DEBUG = 0;
	if (!DEBUG) {
		scanf("%s", p);
	}
	else {
		for (i = 0; i < 5000; i++)p[i] = 'a';
	}
	for (i = 0; p[i]; i++) {
		U[p[i] - 'a'].push_back(i);
	}
	n = i;
	int mask = 0;
	while (mask * 2 + 1 < n)mask = mask * 2 + 1;
	MM = mask;
	vector<int>V;
	V.push_back(0);
	Do(V, 0);
}