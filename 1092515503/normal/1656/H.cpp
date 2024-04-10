#include<bits/stdc++.h>
using namespace std;
typedef __int128 ii;
int T,n,m,sa,sb;
struct SegTree{
ii gcd[4010];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
void build(int x,int l,int r,ii a,ii*b){
	if(l==r)gcd[x]=a/__gcd(b[l],a);
	else build(lson,l,mid,a,b),build(rson,mid+1,r,a,b),gcd[x]=__gcd(gcd[lson],gcd[rson]);
}
void kill(int x,int l,int r,int P){
	if(l==r)gcd[x]=0;
	else P<=mid?kill(lson,l,mid,P):kill(rson,mid+1,r,P),gcd[x]=__gcd(gcd[lson],gcd[rson]);
}
}A[1010],B[1010];
ii a[1010],b[1010];
namespace FIFO{
char buf[1<<23],*p1=buf,*p2=buf;
#ifndef Troverld
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#else
#define gc() getchar()
#endif
template<typename T>void read(T&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
template<typename T>void print(T x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
bool ea[1010],eb[1010];
void mina(){
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]),ea[i]=false;
	for(int i=1;i<=m;i++)read(b[i]),eb[i]=false;
	for(int i=1;i<=n;i++)A[i].build(1,1,m,a[i],b);
	for(int i=1;i<=m;i++)B[i].build(1,1,n,b[i],a);
	while(true){
		bool era=false;
		for(int i=1;i<=n;i++)if(A[i].gcd[1]!=1&&!ea[i]){
//			printf("AKILL%d\n",i);
			era=ea[i]=true;
			for(int j=1;j<=m;j++)B[j].kill(1,1,n,i);
		}
		for(int i=1;i<=m;i++)if(B[i].gcd[1]!=1&&!eb[i]){
//			printf("BKILL%d\n",i);
			era=eb[i]=true;
			for(int j=1;j<=n;j++)A[j].kill(1,1,m,i);
		}
		if(!era)break;
	}
	sa=sb=0;
	for(int i=1;i<=n;i++)if(!ea[i])sa++;
	for(int i=1;i<=m;i++)if(!eb[i])sb++;
	if(!sa&&!sb){puts("NO");return;}
	puts("YES");
	printf("%d %d\n",sa,sb);
	for(int i=1;i<=n;i++)if(!ea[i])print(a[i]),putchar(' ');puts("");
	for(int i=1;i<=m;i++)if(!eb[i])print(b[i]),putchar(' ');puts("");
}
int main(){
	read(T);
	while(T--)mina();
	return 0;
}