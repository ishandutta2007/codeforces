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

int n,w0,h0;

struct X{
	int w,h,i;
}a[5555];
int f[5555],prev[5555];

bool operator<(const X&a, const X&b){ return a.w*ll(a.h)<b.w*ll(b.h); }

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>n>>w0>>h0;
	REP(i,n){
		cin>>a[i].w>>a[i].h; a[i].i=i;
		f[i]=-(-1u/4),prev[i]=-1;
	}
	sort(a,a+n);
	int best=0,k=-1;
	REP(i,n){
		if(w0<a[i].w && h0<a[i].h)f[i]=1;
		REP(j,i)if(f[j]+1>f[i] && a[j].w<a[i].w && a[j].h<a[i].h)
			f[i]=f[j]+1,prev[i]=j;
		if(f[i]>best)best=f[i],k=i;
	}
	if(best){
		cout<<best<<endl;
		vi res;
		for(;~k;k=prev[k])res.pb(a[k].i+1);
		reverse(all(res));
		REP(i,sz(res)){
			if(i)putchar(' ');
			cout<<res[i];
		}
		cout<<endl;
	}else puts("0");
	return 0;
}