#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2e5;
int n,m,k,f[MAXN+5],cnt=0;
struct edge{int u,v,w;} e[MAXN+5];
void init(){for(int i=1;i<=n;i++) f[i]=i;cnt=0;}
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
bool merge(int x,int y){
	x=find(x);y=find(y);
	if(x!=y){cnt++;f[x]=y;return 1;}
	return 0;
}
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);init();
	ll ans=1e15;int pos=0;
	for(int i=1;i<=m;i++){
		if(e[i].w>=k){pos=i;break;}merge(e[i].u,e[i].v);
		if(cnt==n-1) ans=min(ans,(ll)(k-e[i].w));
	}
	if(pos){
		ll sum=0;init();
		for(int i=1;i<=m;i++){
			if(merge(e[i].u,e[i].v)) sum+=max(e[i].w-k,0);
			if(cnt==n-1){
				if(i<pos) ans=min(ans,(ll)(e[pos].w-k));
				else ans=min(ans,sum);
				break;
			}
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}