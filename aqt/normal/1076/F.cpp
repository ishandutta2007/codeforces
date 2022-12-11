
// Problem : F. Summer Practice Report
// Contest : Codeforces - Educational Codeforces Round 54 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1076/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long long mna[1000005], mnb[1000005];
long long a[1000005], b[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> a[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> b[i];
	}
	for(int i = 1; i<=N; i++){
		long long mxa = K*b[i] + K-mna[i-1];
		long long mxb = K*a[i] + K-mnb[i-1];
		//cout << " " << mxa << " " << mxb << "\n";
		if(mxa-a[i] < 0){
			cout << "NO\n";
			return 0;
		}
		if(mxb-b[i] < 0){
			cout << "NO\n";
			return 0;
		}
		mxa -= K;
		mxb -= K;
		mna[i] = max(0LL, a[i] - mxa);
		mnb[i] = max(0LL, b[i] - mxb);
		//cout << mna[i] << " " << mnb[i] << "\n";
	}
	cout << "YES\n";
}