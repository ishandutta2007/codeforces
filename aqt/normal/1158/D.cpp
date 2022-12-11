
// Problem : D. Winding polygonal line
// Contest : Codeforces - Codeforces Round #559 (Div. 1)
// URL : https://codeforces.com/contest/1158/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<long long, long long> arr[2005];
bool tkn[2005];
vector<int> ans;

long long crs(int _a, int _b, int _c){
	auto a = arr[_a];
	auto b = arr[_b];
	auto c = arr[_c];
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	int c = min_element(arr+1, arr+1+N) - arr;
	tkn[c] = 1;
	ans.emplace_back(c);
	for(int t = 2; t<N; t++){
		char cmd;
		cin >> cmd;
		int bst = 0;
		if(cmd == 'L'){
			for(int i = 1; i<=N; i++){
				if(!tkn[i] && (!bst || crs(c, bst, i) < 0)){
					bst = i;
				}
			}
		}
		else{
			for(int i = 1; i<=N; i++){
				if(!tkn[i] && (!bst || crs(c, bst, i) > 0)){
					bst = i;
				}
			}		
		}
		ans.push_back(bst);
		tkn[bst] = 1;
		c = bst;
	}
	for(int i = 1; i<=N; i++){
		if(!tkn[i]){
			ans.push_back(i);
			break;
		}
	}
	for(int n : ans){
		cout << n << " ";
	}
}