#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[10039],t;
long long ans,tot,f[10039],q[10039];
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++){
			memset(q,0,sizeof(q));
			memset(f,0,sizeof(f));
			for(j=i+2;j<=n;j++) q[a[j]]++;
			tot=0;
			for(j=i+2;j<n;j++){
				f[a[j-1]]++;
				tot+=q[a[j-1]];
				q[a[j]]--;
				tot-=f[a[j]];
				if(a[j]==a[i])ans+=tot;
			}
		}
		printf("%lld\n",ans);
	}
}