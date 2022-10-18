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
int n,m,a,b,x[MAXN+5];
bool check(int mid){
	for(int i=mid;i;i--) if(mid-i+1+x[i]>b-1) return 0;
	return 1;
}
void solve(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(a>b) a=n-a+1,b=n-b+1;
	for(int i=1;i<=m;i++) scanf("%d",&x[i]);
	sort(x+1,x+m+1);int l=0,r=min(b-a-1,m),ans=0;
	while(l<=r){int mid=(l+r)>>1;if(check(mid)) ans=mid,l=mid+1;else r=mid-1;}
	printf("%d\n",ans);
}
signed main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}