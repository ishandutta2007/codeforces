#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int t,n,tot,pus,sa[200039],ans,tot1,tot2,f1[200039],f2[200039],a[200039],b[200039],head,maxn[200039];
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		//memset(f1,0,sizeof(f1));
		//memset(f2,0,sizeof(f2));
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&sa[i]),f1[i]=f2[i]=0;
		tot1=tot2=0;head=0;
		maxn[n+1]=0;
		for(i=1;i<=n;i++) f2[sa[i]]++,tot2+=f2[sa[i]]==1?1:0;
		for(i=n;i>=1;i--) maxn[i]=max(maxn[i+1],sa[i]);
		ans=0;
		for(i=1;i<n;i++){
			ans=max(ans,sa[i]);
			f1[sa[i]]++,tot1+=f1[sa[i]]==1?1:0;
			f2[sa[i]]--,tot2-=f2[sa[i]]==0?1:0;
			//printf("%d %d\n",tot1,tot2);
			if(tot1==ans&&tot1==i&&tot2==maxn[i+1]&&tot2==n-i) a[++head]=i,b[head]=n-i;
		}
		printf("%d\n",head);
		for(i=1;i<=head;i++)printf("%d %d\n",a[i],b[i]);
	}
}