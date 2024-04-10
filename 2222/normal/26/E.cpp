#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, W, c[111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> W;
	int v0 = -1u/2, v1 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		v0 = min(v0, c[i]);
		v1 += c[i];
	}
	int i = min_element(c, c + n) - c;
	if (v0 <= W && W <= v1) {
		puts("Yes");
		cout << i + 1;
		for (int j = 0; j < n; ++j) if (i != j) {
			while (W < v1 && c[j] > 0) {
				--c[j];
				--v1;
				printf(" %d %d", j + 1, j + 1);
			}
		}
		printf(" %d", i + 1);
		for (--c[i]; c[i] > 0; --c[i]) 
			printf(" %d %d", i + 1, i + 1);
		for (i = 0; i < n; ++i)
			for (; c[i] > 0; --c[i]) 
				printf(" %d %d", i + 1, i + 1);
		puts("");
	} else if (n > 1 && W > 1 && W < v0) {
		puts("Yes");
		--W;
		int j = i ? 0 : 1;
		cout << j + 1;
		for (; c[i] > 1; --c[i], --v1)
			printf(" %d %d", i + 1, i + 1);
		printf(" %d %d", j + 1, i + 1);
		--c[j], --v1;
		for (int j = 0; j < n; ++j) if (i != j) {
			while (W < v1 && c[j] > 0) {
				--c[j];
				--v1;
				printf(" %d %d", j + 1, j + 1);
			}
		}
		printf(" %d", i + 1);
		for (--c[i]; c[i] > 0; --c[i]) 
			printf(" %d %d", i + 1, i + 1);
		for (i = 0; i < n; ++i)
			for (; c[i] > 0; --c[i]) 
				printf(" %d %d", i + 1, i + 1);
		puts("");
	} else puts("No");
	return 0;
}