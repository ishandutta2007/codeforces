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

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n, q[1024];
vector <pii> a[1024];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n;
	REP (i, n) cin >> q[i];
	int m;
	for (cin >> m; m --> 0; ) {
		int x, y, c;
		cin >> x >> y >> c;
		a[y - 1].pb(pii(x - 1, c));
	}
	int k = 0;
	REP (i, n) if (sz(a[i]) == 0) ++k;
	if (k != 1) puts("-1");
	else {
		long long res = 0;
		REP (i, n) {
			int cc = -1u/4;
			for (vector <pii> :: iterator j = a[i].begin(); j != a[i].end(); ++j) 
				cc = min(cc, j->Y);
			if (a[i].size()) res += cc;
		}
		cout << res << endl;
	}
	return 0;
}