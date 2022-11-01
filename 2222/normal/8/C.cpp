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

int X0,Y0;
int n;
int x[24],y[24];

int F[1<<24];

int a[24][24];

int f(int p){
	if(p==0)return 0;
	int&res=F[p];
	if(res<0){
		int i=__builtin_ctz(p);
		p&=p-1;
		res=f(p)+a[i][i];
		for(int j=i+1;j<n;++j)
			if(p&1<<j)
				res=min(res,f(p^1<<j)+a[i][j]);
	}
	return res;
}

void g(int p){
	if(p==0)return;
	int res=f(p);
	int i=__builtin_ctz(p);
	p&=p-1;
	if(res==f(p)+a[i][i]){
		printf(" %d 0",i+1);
		g(p);
	}else {
		for(int j=i+1;j<n;++j)
			if((p&1<<j) && res==f(p^1<<j)+a[i][j]){
				printf(" %d %d 0",i+1,j+1);
				g(p^1<<j);
				return;
			}
	}
}

inline int d2(int x,int y){ return x*x+y*y; }

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>X0>>Y0>>n;
	REP(i,n){
		cin>>x[i]>>y[i];
		x[i]-=X0,y[i]-=Y0;
	}
	REP(i,n)REP(j,n)
		a[i][j]=d2(x[i],y[i])+d2(x[i]-x[j],y[i]-y[j])+d2(x[j],y[j]);
	CL(F,-1);
	cout<<f((1<<n)-1)<<endl;
	cout<<"0";
	g((1<<n)-1);
	puts("");
	return 0;
}