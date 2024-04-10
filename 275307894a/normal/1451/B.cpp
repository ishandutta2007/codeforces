#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[100039],t,l,flag;
char s;
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			s=getchar();
			while(s<'0'||s>'9') s=getchar();
			a[i]=s-'0';
		}
		while(m--){
			scanf("%d%d",&x,&y);flag=0;
			for(i=1;i<x;i++) if(a[i]==a[x]){flag=1;break;}
			for(i=y+1;i<=n;i++) if(a[i]==a[y]){flag=1;break;}
			if(flag) printf("Yes\n");
			else printf("No\n");
		}
	}
}