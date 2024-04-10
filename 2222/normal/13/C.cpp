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

int n, a[5555], s[5555];

ll F[5555], G[5555], *f = F, *g = G;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n;
	REP (i, n) cin >> a[i], s[i] = a[i];
	sort(s, s + n);
	REP (i, n) {
		g[0] = f[0] + abs(s[0] - a[i]);
		FOR (j, 1, n) 
			g[j] = min(g[j - 1], f[j] + abs(a[i] - s[j]));
		swap(f, g);
	}
	cout << *min_element(f, f + n) << endl;
	return 0;
}