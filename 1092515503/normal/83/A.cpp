#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x,num[100001],tot,m,cnt[100001];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
	cnt[m=1]=1;
	for(int i=2;i<=n;i++){
		if(num[i]==num[i-1])cnt[m]++;
		else cnt[++m]=1;
	}
//	for(int i=1;i<=m;i++)printf("%lld\n",cnt[i]);
	for(int i=1;i<=m;i++)tot+=cnt[i]*(cnt[i]+1)/2;
	printf("%lld\n",tot); 
	return 0;
}