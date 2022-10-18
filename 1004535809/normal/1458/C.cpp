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
const int MAXN=1000;
const int MAXM=1e5;
int n,m,a[MAXN*MAXN+5][3],b[MAXN+5][MAXN+5],p[3],x[3];
char s[MAXM+5];
void inc(int &x){x++;if(x>=n) x-=n;}
void dec(int &x){x--;if(x<0) x+=n;}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		scanf("%d",&a[(i-1)*n+j][2]);
		a[(i-1)*n+j][0]=i;a[(i-1)*n+j][1]=j;
	}
	for(int i=0;i<3;i++) p[i]=i,x[i]=0;scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		if(s[i]=='U') dec(x[p[0]]);
		if(s[i]=='D') inc(x[p[0]]);
		if(s[i]=='L') dec(x[p[1]]);
		if(s[i]=='R') inc(x[p[1]]);
		if(s[i]=='I') swap(p[1],p[2]);
		if(s[i]=='C') swap(p[0],p[2]);
	}
//	for(int j=0;j<3;j++) printf("%d\n",x[j]);
	for(int i=1;i<=n*n;i++){
		for(int j=0;j<3;j++) a[i][j]=(a[i][j]-1+x[j])%n+1;
//		for(int j=0;j<3;j++) printf("%d ",a[i][j]);printf("\n");
		b[a[i][p[0]]][a[i][p[1]]]=a[i][p[2]];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%d ",b[i][j]);
		printf("\n");
	}
}
signed main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve(); 
	return 0;
}