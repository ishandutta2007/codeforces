
// Problem : B. Subway Pursuit
// Contest : Codeforces - Codeforces Round #507 (Div. 1, based on Olympiad of Metropolises)
// URL : https://codeforces.com/contest/1039/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

mt19937 sd (chrono::steady_clock::now().time_since_epoch().count());
long long N, K;

bool query(long long l, long long r){
	cout << l << " " << r << endl;
	string s;
	cin >> s;
	assert(s != "Bad");
	if(l == r && s == "Yes"){
		exit(0);
	}
	return s =="Yes";
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	long long l = 1, r = N;
	while(1){
		long long mid = l+r>>1;
		if(r - l + 1 <= 4*K+1){
			long long idx = uniform_int_distribution<long long> (l, r) (sd);
			query(idx, idx);
		}
		else{
			if(query(l, mid)){
				r = mid;
			}
			else{
				l = mid+1;
			}
		}
		l = max(1LL, l-K);
		r = min(N, r+K);
	}
}