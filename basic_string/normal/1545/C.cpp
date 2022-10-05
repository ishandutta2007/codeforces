#include<bits/stdc++.h>
using namespace std;
const int P=998244353,N=509;
int cnt[N][N],a[N*2][N];
bool b[N*2],ans[N*2];
int main(){
	int T,n,i,j,k,l,o,tot,ct;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n),tot=1,memset(cnt,0,sizeof cnt),memset(b,0,sizeof b),memset(ans,0,sizeof ans),ct=n;
		for(i=1;i<=n+n;++i)for(j=1;j<=n;++j){
			scanf("%d",a[i]+j),++cnt[j][a[i][j]];
		}
		while(1){
		for(i=1;i<=n;++i){
			while(1){
				for(j=1;j<=n;++j)if(cnt[i][j]==1)break;
				if(j>n)break;
				for(k=1;k<=n+n;++k)if(!b[k]&&a[k][i]==j){
					b[k]=1,ans[k]=1,--ct;
					for(o=1;o<=n;++o)--cnt[o][a[k][o]];
					for(l=1;l<=n+n;++l)if(!b[l]){
						for(o=1;o<=n;++o)if(a[k][o]==a[l][o])goto gg;
						continue;
						gg:;
						b[l]=1;
						for(o=1;o<=n;++o)--cnt[o][a[l][o]];
					}
				}
			}
		}
		for(i=1;i<=n+n;++i)if(!b[i]){
			b[i]=1,ans[i]=1,tot=tot*2%P,--ct;
			for(o=1;o<=n;++o)--cnt[o][a[i][o]];
			for(j=i+1;j<=n+n;++j)if(!b[j]){
			for(o=1;o<=n;++o)if(a[i][o]==a[j][o])goto gg2;
			continue;
			gg2:;
			b[j]=1;
			for(o=1;o<=n;++o)--cnt[o][a[j][o]];
			}
			break;
		}
		if(!ct)break;
		}
		printf("%d\n",tot);
		for(i=1;i<=n+n;++i)if(ans[i])printf("%d ",i);puts("");
	}
	return 0;
}