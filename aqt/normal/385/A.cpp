
// Problem : A. Bear and Raspberry
// Contest : Codeforces - Codeforces Round #226 (Div. 2)
// URL : https://codeforces.com/contest/385/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	int mx = 0;
	vector<int> v;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		v.push_back(n);
	}
	for(int i = 1; i<N; i++){
		mx = max(mx, v[i-1] - v[i] - K);
	}
	cout << mx << "\n";
}