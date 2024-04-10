#include<bits/stdc++.h>
using namespace std;
double dp[5003],ans;
int X[5003],W[5003],C[5003],N,I[5003],K;
bool cmp(int x,int y){
	return X[x]<X[y];
}
int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>X[i]>>W[i]>>C[i],I[i]=i;
	sort(I,I+N,cmp);
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++)
			dp[i]=max(dp[i],dp[j]+(X[I[i]]-X[I[j]])*(C[I[i]]+C[I[j]])*0.005*K);
		dp[i]-=W[I[i]];
		ans=max(ans,dp[i]);
	}
	printf("%.9lf",ans);
}