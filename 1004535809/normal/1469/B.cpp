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
const int MAXN=100;
int n,m,a[MAXN+5],b[MAXN+5];
void solve(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
	scanf("%d",&m);for(int i=1;i<=m;i++) scanf("%d",&b[i]),b[i]+=b[i-1];
	int ans=0;for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) chkmax(ans,a[i]+b[j]);
	printf("%d\n",ans);
}
signed main(){
	int qu;scanf("%d",&qu);while(qu--) solve();
	return 0;
}