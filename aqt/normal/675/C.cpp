
// Problem : C. Money Transfers
// Contest : Codeforces - Codeforces Round #353 (Div. 2)
// URL : https://codeforces.com/contest/675/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long pre, ans;;
map<long long, long long> mp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		pre += n;
		mp[pre]++;
		ans = max(ans, mp[pre]);
	}
	cout << N-ans;
}