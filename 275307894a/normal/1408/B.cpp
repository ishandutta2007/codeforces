#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,x,y,z,t,a[10039],b[1039],s[1039],ans,flag,tot;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(s,0,sizeof(s));
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=2;i<=n;i++) if(a[i]==a[i-1]) s[i]=1;
		ans=0;
		for(i=1;i<=n;i++) if(!s[i])ans++;
		if(ans<=m) printf("1\n");
		else{
			if(m==1) printf("-1\n");
			else {
				if((ans-m)%(m-1)==0)printf("%d\n",(ans-m)/(m-1)+1);
				else printf("%d\n",(ans-m)/(m-1)+2);
			} 
		}
	}
}