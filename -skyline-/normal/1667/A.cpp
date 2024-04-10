#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n;
ll ans,a[5005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",a+i);
	ans=orz*1ll*orz;
	for(int i=1;i<=n;++i){
		ll k=0,res=0;
		for(int j=i-1;j;--j){
			ll o=k/a[j]+1;
			k=o*a[j];
			res+=o;
		}
		k=0;
		for(int j=i+1;j<=n;++j){
			ll o=k/a[j]+1;
			k=o*a[j];
			res+=o;
		}
		ans=min(ans,res);
	}
	printf("%I64d\n",ans);
    return 0;
}