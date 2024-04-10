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
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2e5;
int n;
pair<int,int> p[MAXN+5];
int key[MAXN*2+5],hs[MAXN*2+5],cnt=0,num=0,sl[MAXN*2+5],sr[MAXN*2+5];
signed main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&p[i].fi,&p[i].se);
		cnt=num=0;
		for(int i=1;i<=n;i++) key[++cnt]=p[i].fi,key[++cnt]=p[i].se;
		sort(key+1,key+cnt+1);
		for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
		for(int i=1;i<=n;i++) p[i].fi=lower_bound(hs+1,hs+num+1,p[i].fi)-hs;
		for(int i=1;i<=n;i++) p[i].se=lower_bound(hs+1,hs+num+1,p[i].se)-hs;
		for(int i=1;i<=num+1;i++) sl[i]=sr[i]=0;
		for(int i=1;i<=n;i++) sl[p[i].fi]++,sr[p[i].se]++;
		for(int i=num;i;i--) sl[i]+=sl[i+1];
		for(int i=1;i<=num;i++) sr[i]+=sr[i-1];
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++) ans=min(ans,sr[p[i].fi-1]+sl[p[i].se+1]);
		printf("%d\n",ans);
	}
	return 0;
}