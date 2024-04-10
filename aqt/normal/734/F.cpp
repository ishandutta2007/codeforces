
// Problem : F. Anton and School
// Contest : Codeforces - Codeforces Round #379 (Div. 2)
// URL : https://codeforces.com/problemset/problem/734/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long b[200005];
long long c[200005];
long long a[200005];
long long bits[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long S = 0;
	for(int i = 1; i<=N; i++){
		cin >> b[i];
		S += b[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> c[i];
		S += c[i];
	}
	if(S%(2*N)){
		cout << -1;
		return 0;
	}
	S /= 2*N;
	for(int i = 1; i<=N; i++){
		if((b[i]+c[i]-S)%N){
			cout << -1;
			return 0;
		}
		a[i] = (b[i]+c[i]-S)/N;
		for(int k = 0; k<30; k++){
			bits[k] += ((a[i]>>k)&1)<<k;
		}
	}
	for(int i = 1; i<=N; i++){
		long long bval = 0, cval = 0;
		for(int k = 0; k<30; k++){
			if(a[i]>>k&1){
				bval += bits[k];
				cval += N*(1LL<<k);
			}
			else{
				cval += bits[k];
			}
		}
		//cout << a[i] << " " << bval << " " << cval << "\n";
		if(bval != b[i] || cval != c[i]){
			cout << -1;
			return 0;
		}
	}
	for(int i = 1; i<=N; i++){
		cout << a[i] << " ";
	}
}