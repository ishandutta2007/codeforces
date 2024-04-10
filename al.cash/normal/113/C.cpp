#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INFLL = 1000000000000000000LL;

const int h = 300000000;
int l, r;
int pr[(h>>6)+1];

int main() {
#ifdef LocalHost
//	freopen("x.in", "r", stdin);
//	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &l, &r);
	int res = 0;
	int r2 = (r-1)/2;
	pr[0] |= 1;
	FOR(i, 1, (sqrt(2.0*r2+1)+1)/2) if((~pr[i>>5]) & (1<<(i&31)))
		for(int i2=2*i+1, v=i*(i+1)<<1; v<=r2; v+=i2)
			pr[v>>5] |= 1<<(v&31);
	if(l<=2 && 2<=r) ++res;
	for(int v=2; v<=r2; v+=2) if(l<=2*v+1 && (~pr[v>>5]) & (1<<(v&31))) ++res;
	printf("%d\n", res);
#ifdef LocalHost
	cout << endl << "Time: " << clock() << endl;
#endif
//	system("PAUSE");
	return 0;
}