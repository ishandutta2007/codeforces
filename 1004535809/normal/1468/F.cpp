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
const int MAXN=5e3;
const double INF=1e18;
int n;
void solve(){
	map<pair<double,int>,int> num;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2) num[mp(INF,(y1<y2))]++;
		else num[mp(1.0*(y2-y1)/(x2-x1),(x1<x2))]++;
	}
	ll ans=0;
	ffe(it,num) ans+=1ll*(it->se)*(num[mp(it->fi.fi,(it->fi.se)^1)]);
	printf("%lld\n",ans>>1);
}
signed main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}