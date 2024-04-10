#include<cstdio>
using namespace std;
int n,m,k,z,fa[1000039][21],lg[1000039],cnt=4,d[1000039],head,tail,lcas;
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	while(d[x]!=d[y]) x=fa[x][lg[d[x]-d[y]]-1];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
	if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline int dis(int x,int y){
	lcas=lca(x,y);//printf("%d %d %d %d\n",x,y,lcas,d[x]+d[y]-2*d[lcas]);
	return d[x]+d[y]-2*d[lcas];
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);head=2;tail=3;
	fa[2][0]=fa[3][0]=fa[4][0]=1;d[1]=1;d[2]=d[3]=d[4]=2;
	for(i=1;i<=2*n+4;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	while(n--){
		scanf("%d",&z);
		++cnt;d[cnt]=d[z]+1;fa[cnt][0]=z;
		for(i=1;i<=lg[d[cnt]];i++) fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
		if(dis(cnt,head)>dis(head,tail)){
			if(dis(cnt,head)>dis(cnt,tail)) tail=cnt;
			else head=cnt;
		}
		else if(dis(cnt,tail)>dis(head,tail)) head=cnt;
		++cnt;d[cnt]=d[z]+1;fa[cnt][0]=z;
		for(i=1;i<=lg[d[cnt]];i++) fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
		if(dis(cnt,head)>dis(head,tail)){
			if(dis(cnt,head)>dis(cnt,tail)) tail=cnt;
			else head=cnt;
		}
		else if(dis(cnt,tail)>dis(head,tail)) head=cnt;
		printf("%d\n",dis(head,tail));
	}
}