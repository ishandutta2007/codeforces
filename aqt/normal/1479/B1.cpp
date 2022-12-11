
// Problem : B1. Painting the Array I
// Contest : Codeforces - Codeforces Round #700 (Div. 1)
// URL : https://codeforces.com/contest/1479/problem/B1
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
vector<int> pos[100005];

int getnxt(int k, int v){
	auto ptr = upper_bound(pos[v].begin(), pos[v].end(), k);
	if(ptr == pos[v].end()){
		return N + 1;
	}
	else{
		return *ptr;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int lst1 = 0, lst2 = 0;
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		int n;
		cin >> n;
		arr[i] = n;
		pos[n].emplace_back(i);
	}
	for(int i = 1; i <= N; i++){
		int n = arr[i];
		if(arr[lst1] == n){
			cnt += arr[lst2] != n;
			lst2 = i;
			//cout << i << "\n";
		}
		else if(arr[lst2] == n){
			cnt += arr[lst1] != n;
			lst1 = i;
		}
		else if(getnxt(i, arr[lst1]) > getnxt(i, arr[lst2])){
			cnt += arr[lst2] != n;
			lst2 = i;
			//cout << i << "\n";
		}
		else{
			cnt += arr[lst1] != n;
			lst1 = i;
		}
	}
	cout << cnt;
}