// Problem : C. Table Compression
// Contest : Codeforces - Codeforces Round #345 (Div. 1)
// URL : https://codeforces.com/contest/650/problem/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr[1000005];
map<int, vector<pair<int, int>>> mp;
int mxr[1000005], mxc[1000005];
int dsu[2000005], mx[1000005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		arr[i].resize(M+1);
		for(int j = 1; j<=M; j++){
			cin >> arr[i][j];
			mp[arr[i][j]].emplace_back(i, j);
		}
	}
	for(auto p : mp){
		for(auto k : p.second){
			dsu[k.first] = k.first;
			dsu[k.second+N] = k.second + N;
			mx[k.first] = mx[k.second+N] = max(mxr[k.first], mxc[k.second]);
		}
		for(auto k : p.second){
			if(getrt(dsu[k.first]) != getrt(dsu[k.second+N])){
				mx[getrt(k.first)] = max(mx[getrt(k.first)], mx[getrt(k.second+N)]);
				dsu[getrt(k.second+N)] = getrt(k.first);
			}
		}
		for(auto k : p.second){
			arr[k.first][k.second] = mx[getrt(k.first)] + 1;
			mxc[k.second] = mxr[k.first] = arr[k.first][k.second];
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}