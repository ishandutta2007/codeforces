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

bool a[128][128];
int s[128][128];
int f[128];
int n,m,k,xc,yc;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>n>>k;
	xc=(k+1)/2,yc=(k+1)/2;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=k;++j)
			s[i][j]=s[i][j-1]+abs(i-xc)+abs(j-yc);
	REP(kk,n){
		cin>>m;
		int rx=-1,ryl,ryr,best=-1u/2;
		for(int x=1;x<=k;++x){
			for(int y=1;y<=k;++y)
				f[y]=f[y-1]+a[x][y];
			for(int yl=0,yr=m;yr<=k;++yl,++yr)	
				if(f[yl]==f[yr]){
					int dd=s[x][yr]-s[x][yl];
					if(dd<best){
						best=dd;
						rx=x,ryl=yl,ryr=yr;
					}
				}
		}
		if(~rx){
			cout<<rx<<' '<<ryl+1<<' '<<ryr<<endl;
			for(;ryr>ryl;--ryr)a[rx][ryr]=true;
		}else puts("-1");
	}
	return 0;
}