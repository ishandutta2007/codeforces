#include <iostream>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);
using namespace std;

int mod=998244353;
int n;
vector<int> nl,nr;

int cal(int m){
	if(m<0){
		return 0;
	}
	for(int i=0;i<n;i++){
		if(nr[i]<0){
			return 0;
		}
	}
	vector<vector<int> > dp(n);
	for(int i=0;i<n;i++){
		dp[i].resize(m+1);
	}
	for(int i=0;i<=nr[0] && i<=m;i++){
		dp[0][i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=dp[i][(j-1)*(j>0)]+dp[i-1][j];
			dp[i][j]%=mod;
			if(j-nr[i]-1>=0){
				dp[i][j]-=dp[i-1][j-nr[i]-1];
				dp[i][j]+=mod;
				dp[i][j]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++){
		ans+=dp[n-1][i];
		ans%=mod;
	}
	return ans;
}

int main(){
	fastio;
	int nn=100005;
	vector<int> mu(nn+1),vis(nn+1),pr(nn+1);
	int cnt=0;
	mu[1]=1;
	for(int i=2;i<=nn;i++){
		if(vis[i]==0){
			pr[cnt]=i;
			cnt++;
			mu[i]=-1;
		}
		for(int j=0;j<cnt && pr[j]*i<=nn;j++){
			vis[i*pr[j]]=1;
			if(i%pr[j]==0){
				break;
			}
			mu[pr[j]*i]=-mu[i];
		}
	}
	int m;
	cin >> n >> m;
	vector<int> l(n),r(n);
	for(int i=0;i<n;i++){
		cin >> l[i] >> r[i];
	}
	nl.resize(n);
	nr.resize(n);
	int ansz=0;
	int z=0;
	for(int i=1;i<m;i++){
		int y=m/i;
		for(int j=0;j<n;j++){
			nl[j]=(l[j]-1)/i+1;
			nr[j]=r[j]/i;
			nr[j]-=nl[j];
			y-=nl[j];
		}
		z=cal(y);
		ansz+=mu[i]*z;
		ansz%=mod;
		ansz+=mod;
		ansz%=mod;
	}
	cout << ansz << endl;
	return 0;
}