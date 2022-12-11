
// Problem : C. Nastya and Unexpected Guest
// Contest : Codeforces - Codeforces Round #637 (Div. 1) - Thanks, Ivan Belonogov!
// URL : https://codeforces.com/problemset/problem/1340/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[10005];
long long dist[10005][1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int X, N;
	cin >> X >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N);
	int R, G;
	cin >> G >> R;
	for(int i = 1; i<=N; i++){
		for(int g = 0; g<=G; g++){
			dist[i][g] = INT_MAX>>1;
		}
	}
	dist[1][0] = 0;
	deque<pair<int, int>> qu;
	qu.push_back({1, 0});
	while(qu.size()){
		auto p = qu.front();
		qu.pop_front();
		if(p.second == G){
			if(dist[p.first][0] > dist[p.first][G] + 1){
				dist[p.first][0] = dist[p.first][G] + 1;
				qu.push_back(make_pair(p.first, 0));
			}
		}		
		else{
			int n = p.first;
			if(n!=1 && p.second + arr[n] - arr[n-1] <= G && dist[n-1][p.second+arr[n]-arr[n-1]] > dist[n][p.second]){
				dist[n-1][p.second+arr[n]-arr[n-1]] = dist[n][p.second];
				qu.push_front(make_pair(n-1, p.second+arr[n]-arr[n-1]));
			}
			if(n != N && p.second + arr[n+1] - arr[n] <= G && dist[n+1][p.second+arr[n+1]-arr[n]] > dist[n][p.second]){
				dist[n+1][p.second+arr[n+1]-arr[n]] = dist[n][p.second];
				qu.push_front(make_pair(n+1, p.second+arr[n+1]-arr[n]));
			}
		}
	}
	long long ans = LLONG_MAX>>1;
	for(int g = 0; g<=G; g++){
		if(dist[N][g] != INT_MAX>>1){
			ans = min(ans, dist[N][g] * (R+G) + g);
		}
	}
	cout << (ans == LLONG_MAX>>1 ? -1 : ans) << "\n";
}