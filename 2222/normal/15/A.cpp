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

int x[1111], a[1111], n, t;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n >> t;
	vi S;
	REP (i, n) {
		cin >> x[i] >> a[i];
		S.pb(2 * x[i] + a[i] + t);
		S.pb(2 * x[i] - a[i] - t);
	}
	UN(S);
	int res = 0;
	REP (i, sz(S)) {
		++res;
		REP (j, n) if (abs(S[i] - 2 * x[j]) < t + a[j]) {
			--res;
			break;
		}
	}
	cout << res << endl;
	return 0;
}