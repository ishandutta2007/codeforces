
// Problem : E. Yurii Can Do Everything
// Contest : Codeforces - Codeforces Round #682 (Div. 2)
// URL : https://codeforces.com/contest/1438/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
set<pair<long long, int>> st;
long long pre[200005];
long long arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		pre[i] = pre[i-1] + arr[i];
		for(auto p : st){
			if(p.first > arr[i] - pre[i-1]){
				break;
			}
			ans += (p.second != i-1 && (arr[i] ^ arr[p.second]) == (pre[i-1] - pre[p.second]));
		}
		st.insert(make_pair(-arr[i] - pre[i], i));
	}
	cout << ans;
}