#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,k,t,a[10005],f[10005][105],cnt[10005],x[105],y[105],res;
int main(){
	scanf("%d%d",&n,&k);
	res=n;
	t=(n-1)/(k-1)+1;
	for(int i=1;i<=n*k;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)f[n*k+1][i]=n*k+1;
	for(int i=n*k;i;--i){
		for(int j=1;j<=n;++j)f[i][j]=f[i+1][j];
		f[i][a[i]]=i;
	}
	for(int i=1;i<=n*k;++i){
		if(cnt[i]==t) continue;
		while(cnt[i]<t&&res){
			int o=0;
			for(int j=1;j<=n;++j){
				if(x[j]) continue;
				assert(f[i][j]!=n*k+1);
				if(o==0||f[f[i][j]+1][j]<f[f[i][o]+1][o])o=j;
			}
			x[o]=f[i][o],y[o]=f[x[o]+1][o];
			assert(y[o]!=n*k+1);
			assert(o);
			for(int j=x[o];j<=y[o];++j)++cnt[j];
			for(int j=x[o]-1;j>=i;--j)cnt[j]=max(cnt[j],cnt[j+1]);
			--res;
		}
	}
	for(int i=1;i<=n;++i)printf("%d %d\n",x[i],y[i]);			
    return 0;
}