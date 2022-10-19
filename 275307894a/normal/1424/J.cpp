#include<cstdio>
using namespace std;
int ans[1000039],pr[1000039],f[1000039],ph,t,n;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	for(i=2;i<=1e6;i++){
		if(!f[i]) pr[++ph]=i;
		for(j=1;j<=ph&&i*pr[j]<=1e6;j++){
			f[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
	for(i=1;i<=ph;i++) {
		if(pr[i]<=1e3)ans[pr[i]*pr[i]]--;
		ans[pr[i]]++;
	}
	ans[1]=1;
	for(i=2;i<=1e6;i++) ans[i]+=ans[i-1];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
}