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

int a[512],b[512];
int n,m;

short f[512][512];

int setmax(int x,int y,short v){
	for(;x<=n;x+=x&-x){
		short*fx=f[x];
		for(int j=y;j<=m && v>fx[j];j+=j&-j)
			fx[j]=v;
	}
}

short getmax(int x,int y){
  	short res=0;
	for(;x;x&=x-1){
		short*fx=f[x];
		for(int j=y;j>0;j&=j-1)
			res=max(res,fx[j]);
	}
	return res;
}

map<int,vi> A,B;

vector<pii> R[512];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	scanf("%d",&n);
	REP(i,n)scanf("%d",a+i);
	scanf("%d",&m);
	REP(i,m)scanf("%d",b+i);
	for(int i=n-1;i>=0;--i) A[a[i]].pb(i+1);
	for(int i=m-1;i>=0;--i) B[b[i]].pb(i+1);
	for(map<int,vi>::iterator k=A.begin();k!=A.end();++k)
		if(B.count(k->X)){
			vi &va=k->second, &vb=B[k->X];
			for(vi::iterator i=va.begin();i!=va.end();++i)
				for(vi::iterator j=vb.begin();j!=vb.end();++j){
					int c=getmax(*i,*j)+1;
					R[c].pb(pii(*i,*j));
					setmax(*i,*j,c);
				}
		}
	R[0].pb(pii());
	for(int k=n;;--k)if(sz(R[k])){
		cout<<k<<endl;
		vi res;
		pii l(n+1,m+1);
		for(;k>0;--k){
			for(vector<pii>::iterator i=R[k].begin();i!=R[k].end();++i)
				if(i->X<l.X && i->Y<l.Y){
					l=*i;
					res.pb(a[l.X-1]);
					break;
				}
		}
		reverse(all(res));
		for(int i=0;i<sz(res);++i){
			if(i)putchar(' ');
			printf("%d",res[i]);
		}
		puts("");
		return 0;
	}
}