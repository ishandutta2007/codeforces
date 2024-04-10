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

int n, m;
vi a[111];
int q[111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m;
	REP (i, m) {
		a[i].resize(5);
		a[i][1] = i;
		cin >> a[i][2] >> a[i][3] >> a[i][0] >> a[i][4];
	}
	sort(a, a + m);
	for (int i = m; i --> 0; ) 
		for (int x = a[i][2]; x <= a[i][3]; ++x) 
			q[x] = a[i][4];
	int res = 0;
	for (int x = 1; x <= n; ++x) res += q[x];
	cout << res << endl;
	return 0;
}