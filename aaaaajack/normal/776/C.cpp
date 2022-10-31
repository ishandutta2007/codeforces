#include<bits/stdc++.h>
using namespace std;
int main(){
	map<long long,int> cnt;
	int n,x,k;
	long long mx=1LL<<50;
	scanf("%d%d",&n,&k);
	long long sum=0,ans=0;
	cnt[0]++;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		sum+=x;
		if(abs(k)==1){
			ans+=cnt[sum-1];
			if(k<0) ans+=cnt[sum+1];
		}
		else{
			for(long long j=1;abs(j)<mx;j*=k){
				ans+=cnt[sum-j];
			}
		}
		cnt[sum]++;
	}
	printf("%I64d\n",ans);
	return 0;
}