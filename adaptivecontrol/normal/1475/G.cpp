#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003],dp[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<200003;i++)
			dp[i]=0;
		sort(a,a+n);
		dp[1]=0;int ans=0;
		for(int i=0;i<n;i++){
			int QAQ=0;
			for(int j=1;j<=sqrt(a[i]);j++){
				if(a[i]%j)continue;
				QAQ=max(dp[j],QAQ);
				QAQ=max(dp[a[i]/j],QAQ);
			}dp[a[i]]=max(dp[a[i]],QAQ+1);
			ans=max(ans,dp[a[i]]);
		}cout<<n-ans<<endl;
	}
}