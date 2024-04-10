#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 1000
#define M 200000
#define W (1<<20)
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int T,fl[N+5],now1,now2,ans,n=10;char s[N+5];
I void calc(){
	re int i;now1=now2=0;for(i=1;i<=n;i++){
		if(i&1)now1+=(s[i]=='1');else now2+=(s[i]=='1');
		if((now1>now2&&(n-i+1)/2<now1-now2)||(now1<now2&&(n-i)/2<now2-now1)) {ans=min(ans,i);return;}
	}
}
I void dfs(int x){
	if(x==n+1) return calc();if(fl[x]) s[x]='0',dfs(x+1),s[x]='1',dfs(x+1);else dfs(x+1);
}
I void solve(){
	re int i;scanf("%s",s+1);for(i=1;i<=n;i++) fl[i]=(s[i]=='?');ans=10;dfs(1);printf("%d\n",ans);
}
int main(){
// 	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) solve();
}