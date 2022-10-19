#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,pre[maxn][26],q;
char s[maxn];
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	for(ri i=1;i<=n;++i){
		for(ri j=1;j<=26;++j)pre[i][j]=pre[i-1][j];
		++pre[i][s[i]-'a'+1];
	}
	while(q--){
		ri l,r;
		scanf("%d%d",&l,&r);
		ll ans=0;
		for(ri i=1;i<=26;++i)ans+=(pre[r][i]-pre[l-1][i])*i;
		printf("%lld\n",ans);
	}
	return 0;
}