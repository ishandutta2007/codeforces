#include<cstdio>
#include<cstring>
using namespace std;
int x,y,z,n,m,k,t,f[100039],sum[100039],ans;
char s;
inline int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main(){
	//freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&t);
	while(t--){
		memset(sum,0,sizeof(sum));ans=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n*m;i++) f[i]=i;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				s=getchar();
				while(s<'A'||s>'Z') s=getchar();
				if(s=='D'){
					if(i!=n) f[i*m+j-m]=i*m+j;
				}
				if(s=='R'){
					if(j!=m) f[i*m+j-m]=i*m+j-m+1;
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) sum[find(i*m+j-m)]++;
		}
		for(i=1;i<=n*m;i++) if(sum[i]) ans++;
		printf("%d\n",ans-1);
	}
}