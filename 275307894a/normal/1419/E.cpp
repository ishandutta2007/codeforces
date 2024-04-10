#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,x,y,z,t,f[100039],pr[100039],ph,s[100039],sh,flag[100039],p[100039],phs,ans,tot;
int fs[39][100039],h[139];
int main(){
	//freopen("1.in","r",stdin);
	register int i,j;
	for(i=2;i<=100000;i++){
		if(!f[i]) pr[++ph]=i;
		for(j=1;i*pr[j]<=1e5&&j<=ph;j++){
			f[pr[j]*i]=1;
			if(i%pr[j]==0) break;
		}
	}
	scanf("%d",&t);
	while(t--){
		ans=tot=0;
		scanf("%d",&n);
		m=n;
		k=sqrt(n);
		for(i=1;i<=sh;i++) s[i]=0;
		sh=0;
		phs=0;
		for(i=1;i<=ph&&pr[i]<=k;i++){
			if(m%pr[i]==0){
			    s[++sh]=pr[i];
			    while(m%pr[i]==0)m/=pr[i],tot++;
			}
		}
		if(m!=1)s[++sh]=m,ans=1,tot++;
		for(i=2;i<=k;i++){
			if(n%i==0){
				p[++phs]=i;
				if(i*i!=n)p[++phs]=n/i;
			} 
		} 
		p[++phs]=n;
		for(i=1;i<=phs;i++) flag[i]=0;
		for(i=1;i<=sh;i++) h[i]=0;
		for(i=1;i<=sh;i++){
			for(j=1;j<=phs;j++){
				if(!flag[j]&&p[j]%s[i]==0) fs[i][++h[i]]=p[j],flag[j]=1;
			}
		}
		if(sh>=2){
			printf("%d ",s[1]*s[sh]);
			for(j=1;j<=h[1];j++)if(fs[1][j]!=s[1]*s[sh]&&fs[1][j]!=s[1]*s[2]) printf("%d ",fs[1][j]);
			if(sh!=2)printf("%d ",s[1]*s[2]);
		}
		else for(j=1;j<=h[1];j++)printf("%d ",fs[1][j]);
		for(i=2;i<=sh;i++){
		   	for(j=1;j<=h[i];j++) if(fs[i][j]!=s[i]*s[i+1]) printf("%d ",fs[i][j]);
		   	if(i!=sh)printf("%d ",s[i]*s[i+1]);
	    }
	    if(ans&&tot<=2) printf("\n1\n");
		else printf("\n0\n");
	}
}