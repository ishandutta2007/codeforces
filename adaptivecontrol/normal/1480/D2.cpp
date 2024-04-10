#include<bits/stdc++.h>
using namespace std;
int dp[100003],a[100003],n;
vector<int>v;
int mp[100003],minn=19260817;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		mp[a[i]]=19260817;
	}
	v.push_back(a[0]);
	for(int i=1;i<n;i++)
		if(a[i]!=a[i-1])
			v.push_back(a[i]);
	n=v.size();
//	for(int i=0;i<n;i++)cout<<v[i]<<' ';
	for(int i=1;i<=n;i++)dp[i]=19260817;
	mp[0]=1;minn=1;
	for(int i=2;i<=n;i++){
		//1.dp[i-1]
		int nw=min(minn+1,mp[v[i-1]]+i-2);
//		cout<<mp[v[i-1]]+i-1<<' ';
		dp[i-1]=nw;
		mp[v[i-2]]=min(mp[v[i-2]],dp[i-1]-i+1);
		minn=min(minn+1,dp[i-1]);
	}cout<<minn;
}