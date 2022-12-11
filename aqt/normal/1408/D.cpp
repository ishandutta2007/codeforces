
// Problem : D. Searchlights
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> arr[2005];
pair<int, int> brr[2005];
set<pair<int, int>> st;
vector<pair<int, int>> upd[1000005];
int pre[2005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first >> arr[i].second;
		pre[i] = -1;
	}
	for(int i = 1; i<=M; i++){
		cin >> brr[i].first >> brr[i].second;
	}
	sort(brr+1, brr+1+M);
	vector<int> stk;
	for(int i = 1; i<=M; i++){
		while(stk.size() && brr[stk.back()].second <= brr[i].second){
			stk.pop_back();
		}
		stk.push_back(i);
	}
	for(int i = 1; i<=N; i++){
		for(int j = 0; j<stk.size(); j++){
			int idx = stk[j];
			if(brr[idx].first >= arr[i].first && brr[idx].second >= arr[i].second){
				if(j){
					int lst = stk[j-1];
					if(brr[lst].first >= arr[i].first && brr[lst].second >= arr[i].second){
						upd[brr[lst].first - arr[i].first + 1].emplace_back(brr[idx].second - arr[i].second + 1, i);
					}
				}
				/*
				if(!done){
					upd[0].push_back(brr[idx].second - arr[i].second + 1);
				}
				*/
			}
		}
	}
	for(int i = 1; i<=N; i++){
		int mx = arr[i].second - 1;
		for(int j = 0; j<stk.size(); j++){
			int idx = stk[j];
			if(brr[idx].first >= arr[i].first){
				mx = max(brr[idx].second, mx);
			}
		}
		upd[0].emplace_back(mx - arr[i].second + 1, i);
	}
	for(int i = 1; i<=N; i++){
		int mx = arr[i].first - 1;
		for(int j = 0; j<stk.size(); j++){
			int idx = stk[j];
			if(brr[idx].second >= arr[i].second){
				mx = max(mx, brr[idx].first);
			}
		}
		upd[mx - arr[i].first + 1].emplace_back(0, i);
	}
	int ans = 1e7;
	set<pair<int, int>> st;
	for(int k = 0; k<=1000000; k++){
		for(auto n : upd[k]){
			if(pre[n.second] != -1){
				st.erase(make_pair(pre[n.second], n.second));
			}
			pre[n.second] = n.first;
			st.insert(n);
		}
		if(st.empty()){
			ans = min(ans, k);
		}
		else{
			ans = min(ans, k + (*(st.rbegin())).first);
		}
	}
	cout << ans;
}