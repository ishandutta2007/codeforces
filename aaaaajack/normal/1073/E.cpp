#include<bits/stdc++.h>
#define Q 998244353
using namespace std;
long long dp[20][1024],cnt[20][1024];
bool vis[20];
int get_dig(long long x){
	int r=0;
	while(x>0){
		r|=(1<<x%10);
		x/=10;
	}
	return r;
}
void solve(long long l,long long r,int now){
	if(vis[now]) return;
	vis[now]=true;
	if(l>r) return;
	if(l/10==r/10){
		for(long long i=l;i<=r;i++){
			int tmp=get_dig(i);
			dp[now][tmp]+=i;
			dp[now][tmp]%=Q;
			cnt[now][tmp]++;
			cnt[now][tmp]%=Q;
		}
		return;
	}
	for(long long i=l;i<l/10*10+10;i++){
		int tmp=get_dig(i);
		dp[now][tmp]+=i;
		dp[now][tmp]%=Q;
		cnt[now][tmp]++;
		cnt[now][tmp]%=Q;
	}
	for(long long i=r/10*10;i<=r;i++){
		int tmp=get_dig(i);
		dp[now][tmp]+=i;
		dp[now][tmp]%=Q;
		cnt[now][tmp]++;
		cnt[now][tmp]%=Q;
	}
	solve(l/10+1,r/10-1,now+1);
	for(int k=0;k<1024;k++){
		for(int i=0;i<10;i++){
			dp[now][k|(1<<i)]+=dp[now+1][k]*10+cnt[now+1][k]*i;
			dp[now][k|(1<<i)]%=Q;
			cnt[now][k|(1<<i)]+=cnt[now+1][k];
			cnt[now][k|(1<<i)]%=Q;
		}
	}	
}
inline int cnt_bit(int x){
	int r=0;
	while(x){
		r++;
		x-=x&-x;
	}
	return r;
}
int main(){
	long long l,r;
	long long ans=0;
	int k;
	cin>>l>>r>>k;
	solve(l,r,0);
	for(int i=0;i<1024;i++){
		if(cnt_bit(i)<=k) ans=(ans+dp[0][i])%Q;
	}
	cout<<ans<<endl;
	return 0;
}