// Problem : E. Water Taps
// Contest : Codeforces - Educational Codeforces Round 40 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/954/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, T;
int cap[200005];
int tem[200005];
vector<pair<int, int>> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	long long tot = 0;
	long double amt = 0;
	for(int i = 1; i<=N; i++){
		cin >> cap[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> tem[i];
		tem[i] -= T;
		tot += 1LL * cap[i] * tem[i];
		amt += cap[i];
		v.emplace_back(tem[i], cap[i]);
	}
	sort(v.begin(), v.end());
	if(tot > 0){
		reverse(v.begin(), v.end());
	}
	//cout << tot << "\n";
	if(tot){
		for(auto p : v){
			if(((tot - 1LL*p.first*p.second)^tot) < 0){
				amt -= 1.0*tot/p.first;
				break;
			}
			else{
				tot -= 1LL*p.first*p.second;
				amt -= p.second;
			}
			if(!tot){
				break;
			}
		}
	}
	cout << setprecision(10) << amt << "\n";
}