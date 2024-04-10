
// Problem : B. Lipshitz Sequence
// Contest : Codeforces - Codeforces Round #333 (Div. 1)
// URL : https://codeforces.com/contest/601/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long arr[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	while(Q--){
		int l, r;
		cin >> l >> r;
		stack<int> stk;
		stk.push(l);
		long long tot = 0;
		long long ans = 0;
		for(int i = l+1; i<=r; i++){
			while(stk.size() > 1 && abs(arr[stk.top()] - arr[stk.top()-1]) <= abs(arr[i] - arr[i-1])){
				int n = stk.top();
				stk.pop();
				tot -= (n-stk.top()) * abs((arr[n] - arr[n-1]));
			}
			tot += (i-stk.top()) * abs(arr[i] - arr[i-1]);
			stk.push(i);
			ans += tot;
		}
		cout << ans << "\n";
	}
}