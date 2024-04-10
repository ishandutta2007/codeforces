# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
const long long MOD = 1e9+7;
long long int a[xn], b[xn], dp[xn], dps[xn];

int main(){
	long long int n, k, s;
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i] >> b[i];
	long long int mx = 0;
	/*
	for (int i=0; i<n; i++){
		if (a[i] > mx) mx = a[i];
		if (b[i] > mx) mx = b[i];
	}
	*/
	for (int i=0; i<k; i++) dp[i] = 1, dps[i] = i;
	for (int i=k; i<=xn; i++) dp[i] = dp[i-1]+dp[i-k], dp[i] %= MOD, dps[i] = dps[i-1]+dp[i];//, dps[i] %= MOD;
	for (int i=0; i<n; i++) cout << (dps[b[i]]-dps[a[i]-1])%MOD << endl;
	//for (int i=0; i<n; i++) cout << dps[a[i]] << ' ' << dps[b[i]] << endl;
}