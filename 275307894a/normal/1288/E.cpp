#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,g[300039],f[600039],maxn[300039],minn[300039],pus;
inline void get(int x,int y){while(x<=m+n) f[x]+=y,x+=x&-x;}
inline int find(int x){int ans=0;while(x) ans+=f[x],x-=x&-x;return  ans;}
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();
}
inline void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	read(n);read(m);
	for(i=1;i<=n;i++) g[i]=i+m,get(i+m,1),maxn[i]=minn[i]=i;
	for(i=m;i;i--){
		read(x);
		maxn[x]=1;pus=find(g[x]);minn[x]=max(minn[x],pus);
		get(g[x],-1);get(i,1);g[x]=i;
	}
	for(i=1;i<=n;i++) pus=find(g[i]),minn[i]=max(minn[i],pus);
	for(i=1;i<=n;i++) print(maxn[i]),putchar(' '),print(minn[i]),putchar('\n');
}