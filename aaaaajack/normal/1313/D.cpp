#include<bits/stdc++.h>
#define N 100100
using namespace std;
int id[N],dp[256];
int main(){
	int odd[256]={};
	for(int i=1;i<256;i++) odd[i]=odd[i^(i&-i)]^1;
	int n,l,r,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<pair<int,int>> v;
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		r++;
		v.push_back(make_pair(l,i));
		v.push_back(make_pair(r,-i));
	}
	sort(v.begin(),v.end());
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	int pre=0,msk=0;
	for(int i=0;i<v.size();i++){
		int now=v[i].first;
		for(int i=0;i<256;i++) if(dp[i]>=0) dp[i]+=odd[i]*(now-pre);
		int c=abs(v[i].second);
		if(v[i].second>0){
			int in=~msk&(-~msk);
			id[c]=in;
			msk^=in;
			for(int i=0;i<256;i++){
				dp[i|in]=max(dp[i|in],dp[i]);
			}
		}
		else{
			int out=id[c];
			msk^=out;
			for(int i=0;i<256;i++){
				if(i&out) dp[i]=-1;
				else dp[i]=max(dp[i],dp[i|out]);
			}
		}
		pre=now;
	}
	printf("%d\n",dp[0]);
	return 0;
}