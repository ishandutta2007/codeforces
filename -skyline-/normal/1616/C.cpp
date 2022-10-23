#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[105];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int ans=n-1;
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				int cnt=0;
				for(int k=1;k<=n;++k)if((a[i]-a[k])*(i-j)!=(a[i]-a[j])*(i-k))++cnt;
				ans=min(ans,cnt);
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}