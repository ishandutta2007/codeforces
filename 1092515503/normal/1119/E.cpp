#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[300100],cnt,ans;
signed main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++)scanf("%lld",&num[i]);
	for(int i=0;i<n;i++){
		int tmp=min(cnt,num[i]/2);
		ans+=tmp;
		cnt-=tmp;
		num[i]-=tmp*2;
		ans+=num[i]/3;
		num[i]%=3;
		cnt+=num[i];
	}
	printf("%lld\n",ans);
	return 0;
}