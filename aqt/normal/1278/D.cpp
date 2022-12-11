
// Problem : D. Segment Tree
// Contest : Codeforces - Educational Codeforces Round 78 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1278/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int event[1000005];
int lft[500005], rht[500005];
set<int> st;
int par[500005];

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int C = N-1;
	for(int i = 1; i<=N; i++){
		int a, b;
		cin >> a >> b;
		event[a] = i;
		event[b] = -i;
		lft[i] = a, rht[i] = b;
		par[i] = i;
	}
	for(int i = 1; i<=2*N; i++){
		if(event[i] > 0){
			st.insert(i);
		}
		else{
			int n = -event[i];
			st.erase(lft[-event[i]]);
			for(auto it = st.lower_bound(lft[-event[i]]); it != st.end(); it++){
				int k = event[*it];
				if(getrt(k) != getrt(n)){
					C--;
					par[getrt(k)] = getrt(n);
				}
				else{
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	cout << (C ? "NO\n" : "YES");
}