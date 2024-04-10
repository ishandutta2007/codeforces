#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,x,y,z,f[439][10039],flag[10039],flags[139],fh,g[439],now,ff,ans,a[100039];
char s;
int main(){
	//freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);k=sqrt(n*30);
	for(i=1;i<=10000;i++){
		now=i;ff=0;
		while(now){
			if((now%10)!=4&&(now%10)!=7) {ff=1;break;}
			now/=10;
		}
		if(!ff) flag[i]=1,flags[++fh]=i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);f[i/k][a[i]]++;
	}
	while(m--){
		s=getchar();
		while(s<'a'||s>'z') s=getchar();
		if(s=='a'){
			s=getchar();s=getchar();
			scanf("%d%d%d",&x,&y,&z);
			if(x/k==y/k){
				for(i=x;i<=y;i++) f[i/k][a[i]]--,a[i]+=z,f[i/k][a[i]]++;
			}
			else{
				for(i=x;i<x/k*k+k;i++) f[i/k][a[i]]--,a[i]+=z,f[i/k][a[i]]++;
				for(i=x/k+1;i<y/k;i++) g[i]+=z;
				for(i=y/k*k;i<=y;i++) f[i/k][a[i]]--,a[i]+=z,f[i/k][a[i]]++;
			}
		}
		else{
			s=getchar();s=getchar();s=getchar();s=getchar();
			scanf("%d%d",&x,&y);ans=0;
			if(x/k==y/k){
				for(i=x;i<=y;i++) if(flag[a[i]+g[i/k]])ans++;
			}
			else{
				for(i=x;i<x/k*k+k;i++) if(flag[a[i]+g[i/k]])ans++;
				for(i=x/k+1;i<y/k;i++) {
					for(j=1;j<=fh;j++){
						if(flags[j]<g[i]) continue;
						ans+=f[i][flags[j]-g[i]];
					}
				}
				for(i=y/k*k;i<=y;i++) if(flag[a[i]+g[i/k]])ans++;
			}
			printf("%d\n",ans);
		}
	}
}