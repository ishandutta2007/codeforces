
// Problem : A. Oleg and shares
// Contest : Codeforces - Tinkoff Challenge - Elimination Round
// URL : https://codeforces.com/contest/793/problem/A
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
	set<int> st;
	vector<int> v;
	int mini = INT_MAX;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		v.push_back(n);
		st.insert(n%K);
		mini = min(mini, n);
	}
	if(st.size() >= 2){
		cout << -1 << "\n";
		return 0;
	}
	long long ans = 0;
	for(int i = 0; i<N; i++){
		ans += (v[i]-mini)/K;
	}
	cout << ans;
}