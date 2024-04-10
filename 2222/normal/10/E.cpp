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

int n,res=-1u/2,a[444];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>n;
	REP(i,n)cin>>a[i];
	FOR(i,1,n)FOR(j,i,n){
		int t=1,w=a[i-1]-1;
		REP(k,j+1)t+=w/a[k],w%=a[k];
		w=a[j]+a[i-1]-1-w;
		int v=w;
		REP(k,n)t-=w/a[k],w%=a[k];
		if(t<0)res=min(res,v);
	}
	if(res==-1u/2)res=-1;
	cout<<res<<endl;
	return 0;
}