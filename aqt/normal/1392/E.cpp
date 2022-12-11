
// Problem : E. Omkar and Duck
// Contest : Codeforces - Codeforces Global Round 10
// URL : https://codeforces.com/contest/1392/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[30][30];
set<long long> st;

void solve(int n, int m, long long v){
	v += arr[n][m];
	if(n == N && m == N){
		cout << v << "\n";
		st.insert(v);
		return;
	}
	if(n != N){
		solve(n+1, m, v);
	}
	if(m != N){
		solve(n, m+1, v);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			if(i%2 == 1){
				arr[i][j] = 0;
			}			
			else{
				arr[i][j] = (1LL<<(i+j-3));
			}
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout.flush();
	int Q;
	cin >> Q;
	while(Q--){
		long long n;
		cin >> n;
		int crntx = 1, crnty = 1;
		int nxt = 0;
		while(crntx != N || crnty != N){
			cout << crntx << " " << crnty << "\n";
			if(crntx < N && (n&(1LL<<nxt)) == arr[crntx+1][crnty]){
				crntx++;
			}
			else{
				crnty++;
			}
			nxt++;
		}
		cout << N << " " << N << endl;
	}
}