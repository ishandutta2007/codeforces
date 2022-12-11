
// Problem : C. Instant Noodles
// Contest : Codeforces - Codeforces Round #626 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL : https://codeforces.com/contest/1322/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
vector<int> graph[500005];
map<vector<int>, long long> mp;
long long arr[500005];

long long mygcd(long long a, long long b){
	if(!b){
		return a;
	}
	return mygcd(b, a%b);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		for(int i = 1; i<=M; i++){
			int a, b;
			cin >> a >> b;
			graph[b].emplace_back(a);
		}
		for(int i = 1; i<=N; i++){
			sort(graph[i].begin(), graph[i].end());
			if(graph[i].size()){
				mp[graph[i]] += arr[i];
				graph[i].clear();
			}
		}
		long long gcd = 0;
		for(auto p : mp){
			gcd = mygcd(gcd, p.second);
		}
		mp.clear();
		cout << gcd << "\n";
	}
}