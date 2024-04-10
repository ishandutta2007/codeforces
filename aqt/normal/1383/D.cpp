
// Problem : D. Rearrange
// Contest : Codeforces - Codeforces Round #659 (Div. 1)
// URL : https://codeforces.com/contest/1383/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[255][255];
int rmx[255], myrmx[255];
int cmx[255], mycmx[255];
int ans[255][255];
bool tkn[255*255];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cin >> arr[i][j];
			rmx[i] = max(arr[i][j], rmx[i]);
			cmx[j] = max(arr[i][j], cmx[j]);
		}
	}
	sort(rmx+1, rmx+1+N, greater<int>());
	sort(cmx+1, cmx+1+M, greater<int>());
	int r = 0, c = 0;
	vector<pair<int, int>> v;
	while(r < N || c < M){
		if(rmx[r+1] == cmx[c+1]){
			r++;
			c++;
			ans[r][c] = rmx[r];
		}
		else if(rmx[r+1] > cmx[c+1]){
			r++;
			ans[r][c] = rmx[r];
		}
		else{
			c++;
			ans[r][c] = cmx[c];
		}
		tkn[ans[r][c]] = 1;
		if(!ans[r-1][c]){
			for(int k = r-1; k; k--){
				v.emplace_back(k, c);
			}
		}
		if(!ans[r][c-1]){
			for(int k = c-1; k; k--){
				v.emplace_back(r, k);
			}
		}
		//cout << rmx[r] << " " << cmx[c] << " " << ans[r][c] << "\n";
	}
	int idx = 0;
	for(int n = N*M; n; n--){
		if(!tkn[n]){
			//cout << n << " " << v[idx].first << " " << v[idx].second << "\n";
			ans[v[idx].first][v[idx].second] = n;
			idx++;
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			myrmx[i] = max(myrmx[i], ans[i][j]);
			mycmx[j] = max(mycmx[j], ans[i][j]);
		}
	}
	for(int i = 1; i<=N; i++){
		//cout << "row: " << i << " " << myrmx[i] << " " << rmx[i] << "\n";
		//assert(myrmx[i] == rmx[i]);
	}
	for(int j = 1; j<=M; j++){
		//cout << "col: " << j << " " << mycmx[j] << " " << cmx[j]<< "\n";
		//assert(mycmx[j] == cmx[j]);
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}