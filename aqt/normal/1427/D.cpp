
// Problem : D. Unshuffling a Deck
// Contest : Codeforces - Codeforces Global Round 11
// URL : https://codeforces.com/contest/1427/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[55];
int tmp[55];
vector<vector<int>> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	bool rev = 0;
	for(int i = 1; i<=N; i++){
		int idx =0;
		for(int j = 1; j<=N; j++){
			if(arr[j] == i){
				idx = j;
			}
		}
		if(!rev && idx == i){
			continue;
		}
		if(rev && idx == N-i+1){
			continue;
		}
		vector<int> v;		
		if(rev){
			if(idx-1){
				v.push_back(idx-1);
			}
			v.push_back(N-i+1 - idx+1);
			for(int j = 1; j<i; j++){
				v.push_back(1);
			}
		}
		else{
			for(int j = 1; j<i; j++){
				v.push_back(1);
			}
			v.push_back(idx - i + 1);
			if(idx != N){
				v.push_back(N-idx);
			}
		}
		int crnta = 1, crntb = N;
		for(int n : v){
			for(int j = crnta+n-1; j>=crnta; j--){
				tmp[crntb] = arr[j];
				crntb--;
			}
			crnta += n;
		}
		for(int j = 1; j<=N; j++){
			arr[j] = tmp[j];
			//cout << arr[j] << " ";
		}
		//cout << "\n";
		rev ^= 1;
		if(v.size() > 1){
			ans.push_back(v);
		}
	}
	if(rev){
		vector<int> v;
		for(int i = 1; i<=N; i++){
			v.push_back(1);
		}
		if(v.size() > 1){
			ans.push_back(v);
		}
	}
	cout << ans.size() << "\n";
	for(auto v : ans){
		cout << v.size() << " ";
		for(int n : v){
			cout << n << " ";
		}
		cout << "\n";
	}
}