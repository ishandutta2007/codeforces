#include <bits/stdc++.h>
using namespace std;
void solve(){
	long long a,b,k;
	cin >> a >> b >> k;
	vector<long long> v1(a), v2(b);
	for(int i=0;i<k;i++){
		int t;
		cin >> t;
		v1[t-1]++;
	}
	for(int i=0;i<k;i++){
		int t;
		cin >> t;
		v2[t-1]++;
	}
	long long ans = k*(k-1)/2;
	for(int i=0;i<a;i++) ans -= v1[i]*(v1[i]-1)/2;
	for(int i=0;i<b;i++) ans -= v2[i]*(v2[i]-1)/2;
	cout << ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}