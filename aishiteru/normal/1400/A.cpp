#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db 
const int N=100005;
int T,n,o[N];
multiset<ll> S;
ll del[N];
char s[N];
int main(){ 
	scanf("%d",&T);it i,j;
	while(T--){
		scanf("%d%s",&n,s+1);//ct nn=n<<1;
		for(i=1;i<=n;++i){
			rll x=0,now=0;
			for(j=i;j<=i+n-1;++now,++j) s[j]=='1'?x|=1ll<<now:0;
			S.insert(x);
		}
		for(i=0;i<n;++i){
			it c1=0,c0=0,cdel=0;
			for(const auto &p : S)
				p>>i&1?++c1:++c0;
			c1>c0?o[i]=1:o[i]=0;
			//printf("%d %d %d\n",c0,c1,o[i]);
			for(const auto &p : S)
				if((p>>i&1)==o[i]) del[++cdel]=p;
			for(j=1;j<=cdel;++j) S.erase(S.find(del[j]));
		}
		if(S.size()){puts("-1");continue;}
		for(i=0;i<n;++i) printf("%d",o[i]);puts("");
	}
	return 0;
}