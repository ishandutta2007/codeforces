
// Problem : C. Latin Square
// Contest : Codeforces - Codeforces Round #691 (Div. 1)
// URL : https://codeforces.com/contest/1458/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1005][1005];
int out[1005][1005];
int tmp[1005][1005];

void upd(){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			arr[i][j] = tmp[i][j];
		}
	}
}

void rowshift(int k){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			tmp[i][(j+k)%N] = arr[i][j];
		}
	}
	upd();
}

void colshift(int k){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			tmp[(i+k)%N][j] = arr[i][j];
		}
	}
	upd();
}

void rowinv(){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			tmp[i][arr[i][j]] = j;
		}
	}
	upd();
}

void colinv(){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			tmp[arr[i][j]][j] = i;
		}
	}
	upd();
}

void bf(){
	cin >> N >> M;
	for(int i = 0; i<N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
			arr[i][j]--;
		}
	}
	while(M--){
		char c;
		cin >> c;
		if(c == 'R'){
			rowshift(1);
		}
		else if(c == 'L'){
			rowshift(N-1);
		}
		else if(c == 'D'){
			colshift(1);
		}
		else if(c == 'U'){
			colshift(N-1);
		}
		else if(c == 'I'){
			rowinv();
		}
		else{
			colinv();
		}
	}
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cout << arr[i][j]+1 << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void sol(){
	cin >> N >> M;
	for(int i = 0; i<N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
			arr[i][j]--;
		}
	}
	vector<int> perm = {0, 1, 2};
	vector<int> del = {0, 0, 0};
	while(M--){
		char c;
		cin >> c;
		if(c == 'R'){
			del[perm[1]]++;
		}
		else if(c == 'L'){
			del[perm[1]] += N-1;
		}
		else if(c == 'U'){
			del[perm[0]] += N-1;
		}
		else if(c == 'D'){
			del[perm[0]]++;
		}
		else if(c == 'I'){
			swap(perm[1], perm[2]);
		}
		else{
			swap(perm[0], perm[2]);
		}
	}
	//cout << del[0] << " " << del[1] << " " << del[2] << "\n";
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			vector<int> v = {i, j, arr[i][j]};
			int ni = (v[perm[0]] + del[perm[0]])%N;
			int nj = (v[perm[1]] + del[perm[1]])%N;
			int nk = (v[perm[2]] + del[perm[2]])%N;
			//cout << ni << " " << nj << " " << nk << "\n";
			out[ni][nj] = nk;
		}
	}
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cout << out[i][j]+1 << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		sol();
	}
}