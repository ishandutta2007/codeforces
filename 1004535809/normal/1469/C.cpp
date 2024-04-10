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
int n,k,a[MAXN+5];
pii inter(pii x,pii y){return mp(max(x.fi,y.fi),min(x.se,y.se));}
void solve(){
	scanf("%d%d",&n,&k);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	pii cur=mp(a[1],a[1]);
	for(int i=2;i<=n;i++){
		if(i!=n) cur=inter(mp(cur.fi-k+1,cur.se+k-1),mp(a[i],a[i]+k-1));
		else cur=inter(mp(cur.fi-k+1,cur.se+k-1),mp(a[i],a[i]));
		if(cur.fi>cur.se){puts("NO");return;}
	} puts("YES");
}
signed main(){
	int qu;scanf("%d",&qu);while(qu--) solve();
	return 0;
}