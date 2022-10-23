#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n;
ll a[200005],f[200005][18];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%I64d",a+i);
		if(n==1){
			printf("1\n");
			continue;
		}
		for(int i=1;i<n;++i){
			a[i]=a[i]-a[i+1];
			if(a[i]<0)a[i]=-a[i];
			f[i][0]=a[i];
		}
		--n;
		for(int k=0;k<17;++k){
			for(int i=1;i+(1<<k)<=n;++i)f[i][k+1]=__gcd(f[i][k],f[i+(1<<k)][k]);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			ll x=a[i];
			int k=i;
			for(int j=17;j>=0;--j){
				if(k+(1<<j)<=n+1){
					ll g=__gcd(x,f[k][j]);
					if(g!=1){
						x=g;
						k+=(1<<j);
					}
				}
			}
			ans=max(ans,k-i);
		}
		printf("%d\n",ans+1);
	}
					
    return 0;
}