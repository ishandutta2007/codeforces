
// Problem : D. Cut and Stick
// Contest : Codeforces - Codeforces Round #716 (Div. 2)
// URL : https://codeforces.com/contest/1514/problem/D
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
vector<int> pos[300005];
int arr[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		pos[n].push_back(i);
		arr[i] = n;
	}
	while(Q--){
		int l, r;
		cin >> l >> r;
		int T = 50;
		bool maj = 0;
		while(T--){
			int idx = uniform_int_distribution<int> (l, r) (rando);
			int rng = upper_bound(pos[arr[idx]].begin(), pos[arr[idx]].end(), r) - lower_bound(pos[arr[idx]].begin(), pos[arr[idx]].end(), l);
			if(rng > (r - l + 2)/2){
				maj = 1;
				cout << 2*rng - (r-l+1) << "\n";
				break;
			}
		}
		if(!maj){
			cout << 1 << "\n";
		}
	}
}