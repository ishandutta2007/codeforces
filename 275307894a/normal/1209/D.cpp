#include<cstdio>
using namespace std;
int n,m,f[100039],tot,x,y,un,wn;
inline int find(int x){return  x==f[x]?x:f[x]=find(f[x]);}
int main(){
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) f[i]=i;
	while(m--){
		scanf("%d%d",&x,&y);
		un=find(x);wn=find(y);
		if(un==wn) tot++;
		else f[un]=wn;
	}
	printf("%d\n",tot);
}