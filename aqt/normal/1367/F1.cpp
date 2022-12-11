
// Problem : F2. Flying Sort (Hard Version)
// Contest : Codeforces - Codeforces Round #650 (Div. 3)
// URL : https://codeforces.com/contest/1367/problem/F2
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int arr[200005], lft[200005], rht[200005];
vector<int> pos[200005];
vector<int> comp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		comp.clear();
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			comp.push_back(arr[i]);
			lft[i] = rht[i] = 0;
			pos[i].clear();
		}
		pos[N+1].clear();
		int ans = 0;
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for(int i = 1; i<=N; i++){
			arr[i] = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin() + 1;
			if(!lft[arr[i]]){
				lft[arr[i]] = i;
			}
			rht[arr[i]] = i;
			pos[arr[i]].push_back(i);
		}
		int M = comp.size();
		for(int i = 1; i<=M; i++){
			int lst = i, S = pos[i].size();
			while(i < M && lft[i+1] > rht[i]){
				i++;
				S += pos[i].size();
			}
			int l = upper_bound(pos[lst-1].begin(), pos[lst-1].end(), lft[lst]) - pos[lst-1].begin();
			int r = pos[i+1].end() - upper_bound(pos[i+1].begin(), pos[i+1].end(), rht[i]);
			//cout << lst << " " << i << " " << S+l+r << "\n";
			ans = max(ans, S + l + r);
		}
		cout << N-ans << "\n";
	}
}