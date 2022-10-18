#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=30;
const ll INF=1e18;
int n,m,r,a[MAXN+5],b[MAXN+5],p[MAXN+5],k[MAXN+5];
ll ans=-INF;
void dfs(int x,bool pre){
	if(x>m) return;
	if((x&1)==(m&1)){
		ll sum=0;
		for(int i=1;i<=n;i++) sum+=1ll*a[i]*k[i];
		chkmax(ans,sum);
	}
	vector<int> tmp(n+1);
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	for(int i=1;i<=n;i++) a[i]=tmp[p[i]]+r;
	dfs(x+1,0);
	for(int i=1;i<=n;i++) a[i]=tmp[i];
	if(!pre){
		for(int i=1;i<=n;i++) a[i]^=b[i];
		dfs(x+1,1);
		for(int i=1;i<=n;i++) a[i]=tmp[i];
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&k[i]);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	dfs(0,0);printf("%lld\n",ans);
	return 0;
}