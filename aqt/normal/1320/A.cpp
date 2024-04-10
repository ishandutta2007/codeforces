
// Problem : A. Journey Planning
// Contest : Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL : https://codeforces.com/contest/1320/problem/A
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N;
map<int, long long> mp;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		mp[i-n] += n;
		ans = max(mp[i-n], ans);
	}
	cout << ans << endl;
}