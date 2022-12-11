
// Problem : B. Histogram Ugliness
// Contest : Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1534/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[400005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		priority_queue<pair<int, int>> pq;
		for(int i = 1; i <= N; i++){
			cin >> arr[i];
			pq.push(make_pair(arr[i], i));
		}
		arr[N+1] = 0;
		long long ans = 0;
		while(pq.size()){
			int n = pq.top().second;
			pq.pop();
			if(arr[n] > arr[n + 1] && arr[n] > arr[n - 1]){
				int mx = max(arr[n+1], arr[n-1]);
				ans += arr[n] - mx;
				arr[n] = mx;
			}
		}
		for(int i = 1; i <= N+1; i++){
			ans += abs(arr[i] - arr[i-1]);
		}
		cout << ans << "\n";
	}
}