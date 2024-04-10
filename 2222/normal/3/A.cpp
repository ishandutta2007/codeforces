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

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	string a,b;
	cin>>a>>b;
	vector<string> res;
	for(;;){
		int dx=b[0]-a[0],dy=b[1]-a[1];
		dx=(dx>0)-(dx<0);
		dy=(dy>0)-(dy<0);
		string s;
		if(dx>0)s+='R';
		if(dx<0)s+='L';
		if(dy>0)s+='U';
		if(dy<0)s+='D';
		if(sz(s)==0) break;
		res.pb(s);
		a[0]+=dx;
		a[1]+=dy;
	}
	cout<<sz(res)<<endl;
	REP(i,sz(res))cout<<res[i]<<endl;
	return 0;
}