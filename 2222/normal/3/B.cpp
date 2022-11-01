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

vector<pii> a[2];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	int n,v;
	cin>>n>>v;
	REP(i,n){
		int t,p;
		scanf("%d%d",&t,&p);
		a[t-1].pb(pii(p,i));
	}
	REP(k,2){
		sort(a[k].rbegin(),a[k].rend());
		FOR(i,1,sz(a[k]))a[k][i].X+=a[k][i-1].X;
	}
	int best=0,k1=0,k2=0;
	REP(i,1+sz(a[1]))if(i*2<=v){
		int j=min(v-i*2,sz(a[0]));
		int s=(j?a[0][j-1].X:0)+(i?a[1][i-1].X:0);
		if(s>best)best=s,k1=j,k2=i;
	}
	cout<<best<<endl;
	REP(i,k1)printf("%d ",a[0][i].Y+1);
	REP(i,k2)printf("%d ",a[1][i].Y+1);
	cout<<endl;
	return 0;
}