
// Problem : A. Learning Languages
// Contest : Codeforces - Codeforces Round #170 (Div. 1)
// URL : https://codeforces.com/contest/277/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int dsu[1005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N+M; i++){
		dsu[i] = i;
	}
	bool allzero = 1;
	for(int i = 1; i<=N; i++){
		int k;
		cin >> k;
		allzero &= (k == 0);
		while(k--){
			int n;
			cin >> n;
			if(getrt(n+N) != getrt(i)){
				dsu[getrt(n+N)] = getrt(i);
			}
		}
	}
	if(allzero){
		cout << N << "\n";
		return 0;
	}
	set<int> st;
	for(int i = 1; i<=N; i++){
		st.insert(getrt(i));
	}
	cout << st.size()-1;
}