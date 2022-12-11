
// Problem : C. Robot Collisions
// Contest : Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1525/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
vector<int> ans;

void solve(vector<pair<int, pair<int, char>>> arr){
	vector<pair<int, pair<int, char>>> stk;
	for(auto p : arr){
		//cout << p.first << "\n";
		if(p.second.second == ')'){
			if(stk.size() && stk.back().second.second == '('){
				int t = (stk.back().second.first + p.second.first) / 2 - stk.back().second.first;
				ans[stk.back().first] = t;
				ans[p.first] = t;
				stk.pop_back();
			}
			else{
				stk.push_back(p);
			}
		}
		else{
			stk.push_back(p);
		}
	}
	for(int i = 1; i < stk.size(); i++){
		if(stk[i].second.second == stk[i - 1].second.second && stk[i].second.second == ')'){
			int t = stk[i].second.first - (stk[i].second.first - stk[i - 1].second.first) / 2;
			ans[stk[i].first] = t;
			ans[stk[i - 1].first] = t;
			stk[i].second.second = stk[i - 1].second.second = 'x';
		}
	}
	for(int i = (int) (stk.size()) - 1; i > 0; i--){
		if(stk[i].second.second == stk[i - 1].second.second && stk[i].second.second == '('){
			int t = (2 * M - stk[i].second.first + stk[i - 1].second.first) / 2 - stk[i - 1].second.first;
			ans[stk[i].first] = t;
			ans[stk[i - 1].first] = t;
			stk[i].second.second = stk[i - 1].second.second = 'x';
		}
	}
	for(int i = 1; i < stk.size(); i++){
		if(stk[i].second.second != 'x' && stk[i - 1].second.second != 'x'){
			int t = (2 * M - stk[i].second.first - stk[i - 1].second.first) / 2 + stk[i - 1].second.first;
			ans[stk[i].first] = ans[stk[i - 1].first] = t;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		vector<pair<int, pair<int, char>>> arr;
		ans.resize(N);
		fill(ans.begin(), ans.end(), -1);
		for(int i = 1; i <= N; i++){
			int n;
			cin >> n;
			arr.emplace_back(i - 1, make_pair(n, '('));
		}
		for(int i = 1; i <= N; i++){
			char c;
			cin >> c;
			if(c == 'L'){
				arr[i - 1].second.second = ')';
			}
		}
		sort(arr.begin(), arr.end(), [](auto x, auto y){
			return x.second.first < y.second.first;
		});
		vector<pair<int, pair<int, char>>> err, orr;
		for(auto p : arr){
			if(p.second.first%2 == 0){
				err.push_back(p);
			}
			else{
				orr.push_back(p);
			}
		}
		solve(err);
		solve(orr);
		for(int n : ans){
			cout << n << " ";
		}
		cout << "\n";
		ans.clear();
	}
}