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
char s[MAXN+5];
int n,x[MAXN+5],y[MAXN+5];
void solve(){
	scanf("%s",s+1);n=strlen(s+1);
	memset(x,0,sizeof(x));memset(y,0,sizeof(y));
	for(int i=1;i<=n;i++){
		x[i]=x[i-1];y[i]=y[i-1];
		if(s[i]=='L') x[i]--;
		if(s[i]=='R') x[i]++;
		if(s[i]=='D') y[i]--;
		if(s[i]=='U') y[i]++;
	}
	map<pii,bool> vis;
	for(int i=1;i<=n;i++){
		if(vis[mp(x[i],y[i])]) continue;
		vis[mp(x[i],y[i])]=1;
		int dx=0,dy=0;
		for(int j=i;j<=n;j++){
			if(x[j]+dx==x[i]&&y[j]+dy==y[i]){
				if(s[j]=='L') dx++;
				if(s[j]=='R') dx--;
				if(s[j]=='D') dy++;
				if(s[j]=='U') dy--;
			}
		}
		if(x[n]+dx==0&&y[n]+dy==0){
			printf("%d %d\n",x[i],y[i]);return;
		}
	}
	puts("0 0");
}
signed main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}