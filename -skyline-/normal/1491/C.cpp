#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[5005];
ll b[5005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i),b[i]=0;
		ll ans=0;
		for(int i=1;i<=n;++i){
			b[i]+=b[i-1];
			++b[i+2],--b[min(n,i+a[i])+1];
			if(b[i]>=a[i])b[i+1]+=b[i]-a[i]+1,b[i+2]-=b[i]-a[i]+1;
			a[i]=max(a[i]-b[i],1ll);
			ans+=a[i]-1;
		}
		printf("%I64d\n",ans);
	}
    return 0;
}