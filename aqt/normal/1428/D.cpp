
// Problem : D. Bouncing Boomerangs
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1428/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
int lst[100005];
int cnt[100005];
vector<pair<int, int>> ans;
set<int> st;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	int h = 0;
	for(int i = N; i; i--){
		if(arr[i] == 0){
			
		}
		else if(arr[i] == 1){
			ans.emplace_back(i, ++h);
			lst[h] = i;
			st.insert(h);
			//cnt[h]++;
		}
		else if(arr[i] == 2){
			if(st.size()){
				int k = *(--st.end());
				if(k < 0){
					cout << -1 << "\n";
					return 0;
				}
				lst[k] = i;
				ans.emplace_back(i, k);
				st.erase(k);
				st.insert(-k);
				//cnt[k]++;
			}
			else{
				cout << -1;
				return 0;
			}
		}
		else{
			if(st.size()){
				int k = *st.begin();
				ans.emplace_back(i, ++h);
				ans.emplace_back(lst[abs(k)], h);
				lst[h] = i;
				st.erase(k);
				st.insert(-h);
				//cnt[h]++;
			}
			else{
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	/*
	if(*max_element(cnt+1, cnt+1+N) > 2){
		cout << -1;
		return 0;
	}
	*/
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << N-p.second+1 << " " << p.first << "\n";
	}
}