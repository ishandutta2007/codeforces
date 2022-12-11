
// Problem : C. Mixing Water
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long H, C, K;
		cin >> H >> C >> K;
		long long l = 0, r = 1e12, idx = 0;
		while(l <= r){
			long long mid = (l+r)/2;
			//cout << mid << " " << idx << endl;
			long long coe = 2*mid+1;
			if((mid*(H+C)+H) > (K*(coe))){
				l = mid + 1;
			}
			else{
				idx = mid;
				r = mid - 1;
			}
		}
		vector<pair<long double, int>> v;
		for(long long i = max(1LL, 2*idx+1-6); i<=2*idx+1+6; i+=2){
			long double d = abs(((i/2)*(H+C)+H)/(1.0*i) - K);
			//cout << d << " " << i << "\n";
			v.push_back({d, i});
		}
		long double delta3 = abs(1.0*((H+C))/2 - K);
		v.push_back({delta3, 2});
		sort(v.begin(), v.end());
		cout << v[0].second << "\n";
	}
}