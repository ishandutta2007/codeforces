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

int n;
int p[1111111], q[1111111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) {
		int x;
		scanf("%d", &x);
		q[x - 1] = i;
	}
	REP (i, n) {
		int x;
		scanf("%d", &x);
		p[n - i - 1] = q[x - 1];
	}
	fill(q, q + n, -1u/2);
	REP (i, n) 
		*lower_bound(q, q + n, p[i]) = p[i];
	int r = 0;
	for (; r < n && q[r] != -1u/2; ++r);
	cout << r << endl;
	return 0;
}