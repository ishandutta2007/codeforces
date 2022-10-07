#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
int read(){
	int x=0,f=1,ch=getchar();
	for (;!isdigit(ch)&&ch!=EOF;ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^'0');
	return x*f;
}
const int N=400005;
int n,m,p[N],h[3],t[3],vis[N];
struct node{
	int c,p,id;
	bool operator <(const node&b)const{return p<b.p;}
}a[3][N];
int main(){
	n=read();
	for (register int i=1;i<=n;++i) p[i]=read();
	for (register int i=1,x;i<=n;++i) x=read()-1,a[x][++t[x]]=(node){x,p[i],i};
	for (register int i=1,x;i<=n;++i) x=read()-1,a[x][++t[x]]=(node){x,p[i],i};
	for (register int i=0;i<=2;++i) h[i]=1,sort(a[i]+1,a[i]+1+t[i]);
	m=read();
	while (m--){
		int x=read()-1;
		while (h[x]<=t[x]&&vis[a[x][h[x]].id]) ++h[x];
		if (h[x]>t[x]) printf("-1 ");
		else printf("%d ",a[x][h[x]].p),vis[a[x][h[x]].id]=1,++h[x];
	}
}