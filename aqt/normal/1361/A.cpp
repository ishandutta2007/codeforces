
// Problem : A. Johnny and Contribution
// Contest : Codeforces - Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL : https://codeforces.com/contest/1361/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[500005];
vector<int> graph[500005];
pair<int, int> srt[500005];
int ans[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		srt[i] = {arr[i], i};
	}
	sort(srt+1, srt+1+N);
	for(int i = 1; i<=N; i++){
		if(srt[i].first > i || (int) (graph[srt[i].second].size())+1 < srt[i].first){
			cout << -1 << "\n";
			return 0;
		}
		set<int> st;
		for(int k = 1; k<=srt[i].first; k++){
			st.insert(k);
		}
		for(int e : graph[srt[i].second]){
			if(ans[e]){
				if(st.count(ans[e])){
					st.erase(ans[e]);
				}
			}
		}
		if(st.size() == 1 && *st.begin() == srt[i].first){
			ans[srt[i].second] = *st.begin();
		}
		else{
			cout << -1 << "\n";
			return 0;
		}
	}
	for(int i = 1; i<=N; i++){
		cout << srt[i].second << " ";
	}
}