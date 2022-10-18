#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquAb cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int mod=998244353;
int inv(int x){
	if(x==1){
		return 1;
	}
	return 1ll*(mod-mod/x)*inv(mod%x)%mod;
}
vector<int> fra;
int conb(int n,int k){
	if(n<k || k<0 || n<0){
		return 0;
	}
	if(k==0 || k==n){
		return 1;
	}
	return 1ll*fra[n]*(1ll*inv(fra[k])*inv(fra[n-k])%mod)%mod;
}
int main(){
	AquAb;
	int n;
	cin >> n;
	fra.resize(n+1);
	fra[0]=1;
	for(int i=1;i<=n;i++){
		fra[i]=1ll*fra[i-1]*i%mod;
	}
	vector<string> v(n);
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
	for(int i=0;i<n;i++){
		cin >> v[i];
		if(v[i][1]=='B'){
			v[i][1]='W';
		}
		else if(v[i][1]=='W'){
			v[i][1]='B';
		}
		if(v[i][0]=='B'){
			a++;
		}
		if(v[i][1]=='B'){
			b++;
		}
		if(v[i]=="BB"){
			c++;
		}
		if(v[i]=="??"){
			d++;
		}
		if(v[i][0]=='?'){
			e++;
		}
		if(v[i][1]=='?'){
			f++;
		}
		if(v[i]=="BW" || v[i]=="WB"){
			g++;
		}
	}
	int ans=0;
	for(int k=0;k<=n;k++){
		if(k>=a && k>=b){
			ans+=1ll*conb(e,k-a)*conb(f,k-b)%mod;
			ans%=mod;
			if(k!=0 && k!=n && g==0){
				ans-=conb(d,k-a+b-c);
				ans+=mod;
				ans%=mod;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}