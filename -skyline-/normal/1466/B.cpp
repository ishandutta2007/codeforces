#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int t,n,a[100005],f[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		int ans=0,x=a[1],y=1;
		for(int i=2;i<=n;++i){
			if(a[i]-a[i-1]<=1)++y;
			else{
				ans+=min(y,a[i-1]-x+2);
				x=a[i];
				y=1;
			}
		}
		ans+=min(y,a[n]-x+2);
		printf("%d\n",ans);
	}
    return 0;
}