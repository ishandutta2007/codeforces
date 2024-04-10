#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[500010],s,sum,occ[500010],ans;
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&num[i]),s+=num[i];
	if(s%3){puts("0");return 0;}
	s/=3;
	for(int i=1;i<=n;i++){
		sum+=num[i],occ[i]+=occ[i-1];
		if(sum==s)occ[i+2]++;
	}
	sum=0;
	for(int i=n;i;i--){
		sum+=num[i];
		if(sum==s)ans+=occ[i];
	}
	printf("%I64d\n",ans);
	return 0;
}