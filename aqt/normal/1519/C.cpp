
// Problem : C. Berland Regional
// Contest : Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1519/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int uni[200005];
long long val[200005];
long long tot[200005];
vector<long long> unival[200005];
vector<long long> pre[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		fill(tot, tot+1+N, 0);
		for(int i= 1; i<=N; i++){
			unival[i].clear();
			pre[i].clear();
		}
		for(int i =1 ; i<=N; i++){
			cin >> uni[i];
		}
		for(int j = 1; j<=N; j++){
			cin >> val[j];
			tot[uni[j]] += val[j];
			unival[uni[j]].emplace_back(val[j]);
		}
		set<pair<int, int>> st;
		for(int i= 1; i <= N; i++){
			sort(unival[i].begin(), unival[i].end());
			pre[i].emplace_back(0);
			for(long long n : unival[i]){
				pre[i].emplace_back(pre[i].back() + n);
			}
			if(tot[i]){
				st.insert(make_pair(unival[i].size(), i));
			}
		}
		for(int i = 1; i <= N; i++){
			while(st.size() && (*st.begin()).first < i){
				st.erase(st.begin());
			}
			long long out = 0;
			for(auto p : st){
				out += tot[p.second];
				int r = p.first % i;
				out -= pre[p.second][r];
			}
			cout << out << " ";
		}
		cout << "\n";
	}
}