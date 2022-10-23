#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[100005],b[100005],c[100005],m;
ll sol(){
	ll ret=0;
	for(int i=1;i<=m;++i)ret+=abs(b[i]-c[i]);
	return ret;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int cnt[2]={};
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			a[i]&=1;
			++cnt[a[i]];
		}
		if(min(cnt[0],cnt[1])!=n/2){
			printf("-1\n");
			continue;
		}
		if(cnt[0]>cnt[1]){
			swap(cnt[0],cnt[1]);
			for(int i=1;i<=n;++i)a[i]^=1;
		}
		m=0;
		for(int i=1;i<=n;++i)if(a[i])b[++m]=i;
		for(int i=1;i<=m;++i)c[i]=i*2-1;
		ll ans=sol();
		if(n%2==0){
			for(int i=1;i<=m;++i)c[i]++;
			ans=min(ans,sol());
		}
		printf("%I64d\n",ans);
	}
    return 0;
}