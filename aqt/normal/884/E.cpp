//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("no-stack-protector")
// Problem : E. Binary Matrix
// Contest : Codeforces - Educational Codeforces Round 31
// URL : https://codeforces.com/problemset/problem/884/E
// Memory Limit : 16 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> dsu[2][1<<15];
bool arr[2][1<<15];

inline pair<int, int> getrt(int n, int m){
	return dsu[n][m] = (dsu[n][m] == dsu[dsu[n][m].first&1][dsu[n][m].second] ?
	 dsu[n][m] : getrt(dsu[n][m].first&1, dsu[n][m].second));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int C = 0;
	for(int i = 1; i<=N; i++){
		for(int j = 0; j<M; j++){
			dsu[i&1][j] = make_pair(i, j);
		}
		for(int j = 0; j<M; j+=4){
			char c;
			cin >> c;
			int v = c-'0';
			if(c >= 'A' && c <= 'Z'){
				v = c-'A'+10;
			}
			arr[i&1][j+3] = v&1;
			arr[i&1][j+2] = v>>1&1;
			arr[i&1][j+1] = v>>2&1;
			arr[i&1][j] = v>>3&1;
		}
		for(int j = 0; j<M; j++){
			if(arr[i&1][j]){
				C++;
				if(j && arr[i&1][j-1]){
					auto q = getrt(i&1, j-1);
					dsu[q.first&1][q.second] = make_pair(i, j);
					C--;
				}
				if(arr[i&1^1][j]){
					auto q = getrt(i&1^1, j);
					if(make_pair(i, j) != q){
						dsu[q.first&1][q.second] = make_pair(i, j);
						C--;
					}
				}
			}
		}
	}
	cout << C;
}