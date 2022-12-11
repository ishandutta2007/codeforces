
// Problem : A. Peaceful Rooks
// Contest : Codeforces - Codeforces Round #692 (Div. 1, based on Technocup 2021 Elimination Round 3)
// URL : https://codeforces.com/contest/1464/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, K;
int dsu[200005];
bool cyc[200005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> K;
		iota(dsu+1, dsu+1+N, 1);
		fill(cyc+1, cyc+1+N, 1);
		int ans = K;
		while(K--){
			int a, b;
			cin >> a >> b;
			if(a == b){
				ans--;
				continue;
			}
			if(getrt(a) == getrt(b)){
				cyc[getrt(a)] = 1;
				ans++;
			}
			else{
				dsu[getrt(a)] = getrt(b);
			}
		}
		cout << ans << "\n";
	}
}