#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	const int mod=1000000007;
	vector<int> f(200005);
	f[0]=1;
	for(int i=1;i<200005;i++){
		f[i]=(1ll*f[i-1]*i)%mod;
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << (1ll*f[2*n]*500000004)%mod << "\n";
	}
	return 0;
}