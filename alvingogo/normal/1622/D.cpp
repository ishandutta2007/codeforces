#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int mod=998244353;
vector<int> fra;
int inv(int x){
	if(x==1){
		return 1;
	}	
	return 1ll*(mod-mod/x)*inv(mod%x)%mod;
}
int conb(int n,int k){
	if(n<k || k<0 || n<0){
		return 0;
	}
	return 1ll*fra[n]*(1ll*inv(fra[k])*inv(fra[n-k])%mod)%mod;
}
int main(){
	AquA;
	fra.resize(5005);
	fra[0]=1;
	for(int i=1;i<5005;i++){
		fra[i]=1ll*fra[i-1]*i%mod;
	}
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> v;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			v.push_back(i);
		}
	}
	long long ans=1;
	if(v.size()<k || k==0){
		cout << ans << "\n";
		return 0;
	}
	v.push_back(n);
	ans+=conb(v[k],k)-1;
	for(int i=k;i<v.size()-1;i++){
		ans+=conb(v[i+1]-v[i-k]-1,k)-conb(v[i]-v[i-k]-1,k-1);
		ans%=mod;
		if(ans<0){
			ans+=mod;
		}
	}
	cout << ans << "\n";
	return 0;
}