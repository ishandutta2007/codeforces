#include<bits/stdc++.h>
using namespace std;

map<int,long long> cnt;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		cnt[x-i]+=x;
	}
	long long ans=0;
	for(auto v:cnt)ans=max(ans,v.second);
	printf("%lld\n",ans);
	return 0;
}