#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int t,n,w[100005],c[100005];
ll ans[100005],a[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",w+i),c[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			++c[x],++c[y];
		}
		ans[1]=0;
		int m=0;
		for(int i=1;i<=n;++i){
			ans[1]+=w[i];
			while(c[i]>1)--c[i],a[++m]=w[i];
		}
		sort(a+1,a+m+1);
		for(int i=m;i;--i)ans[m+2-i]=ans[m+1-i]+a[i];
		for(int i=1;i<n-1;++i)printf("%I64d ",ans[i]);
		printf("%I64d\n",ans[n-1]);
	}	
    return 0;
}