
// Problem : C. Circle of Monsters
// Contest : Educational Codeforces Round 85 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1334/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		vector<long long> a, b;
		int N;
		cin >> N;
		for(int i = 1; i<=N; i++){
			long long ta, tb;
			cin >> ta >> tb;
			a.push_back(ta);
			b.push_back(tb);
		}
		long long sum = 0, mn = LLONG_MAX;
		for(int i = 0; i<N; i++){
			sum += a[i];
			sum -= min(b[i], a[(i+1)%N]);
			mn = min(mn, min(b[i], a[(i+1)%N]));
		}
		sum += mn;
		cout << sum << "\n";
	}
}