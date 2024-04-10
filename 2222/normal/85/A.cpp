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

char a[4][111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	if (n == 1) {
		puts("a");
		puts("a");
		puts("b");
		puts("b");
	} else if (n == 2) {
		puts("aa");
		puts("bb");
		puts("aa");
		puts("bb");
	} else {
		a[0][0] = 'x';
		a[1][0] = 'x';
		int k = 0;
		REP (i, n - 1) {
			if (a[0][i] == 0) {
				a[0][i] = 'a' + k;
				a[0][i + 1] = 'a' + k;
				k = (k + 1) % 8;
				a[1][i] = 'a' + k;
				a[1][i + 1] = 'a' + k;
				k = (k + 1) % 8;
			} else if (a[2][i] == 0) {
				a[2][i] = 'a' + k;
				a[2][i + 1] = 'a' + k;
				k = (k + 1) % 8;
				a[3][i] = 'a' + k;
				a[3][i + 1] = 'a' + k;
				k = (k + 1) % 8;
			}
		}
		REP (i, 4) {
			if (a[i][n - 1] == 0) a[i][n - 1] = 'y';
			puts(a[i]);
		}
	}
	return 0;
}