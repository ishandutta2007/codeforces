
// Problem : F. Simplified Nonogram
// Contest : Codeforces - Codeforces Round #298 (Div. 2)
// URL : https://codeforces.com/problemset/problem/534/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, F;
bool vis[25][32][12*12*12*12*12];
int fin[10];
int arr[25];
vector<int> trans[25];
char ans[10][25];
int pows[10];

bool dp(int n, int m, int t){
	//cout << n << " " << m << " " << t << endl;
	if(n == M && t == F){ 
		return 1;
	}
	if(vis[n][m][t]){
		return 0;
	}
	vis[n][m][t] = 1;
	for(int k : trans[n]){
		int temp = t;
		for(int i = 0; i<N; i++){
			if((k>>i&1) && !(m>>i&1)){
				temp += pows[N-i-1];
			}
		}
		if(dp(n+1, k, temp)){
			for(int i = 0; i<N; i++){
				ans[i][n] = ((k>>i&1) ? '*' : '.');
			}
			return 1;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	pows[0] = 1;
	for(int i = 0; i<N; i++){
		F *= 11;
		pows[i+1] = pows[i] * 11;
		cin >> fin[i];
		F += fin[i];
	}
	for(int i = 0; i<M; i++){
		cin >> arr[i];
		for(int m = 0; m<1<<N; m++){
			m <<= 1;
			int c = 0;
			for(int j = 0; j<N; j++){
				if((m>>j)%4 == 2){
					c++;
				}
			}
			m >>= 1;
			if(c == arr[i]){
				trans[i].push_back(m);
			}
		}
	}
	dp(0, 0, 0);
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			cout << ans[i][j];
		}
		cout << "\n";
	}
}