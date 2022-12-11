
// Problem : E. Magical Permutation
// Contest : Codeforces - Codeforces Round #558 (Div. 2)
// URL : https://codeforces.com/contest/1163/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int basis[30];
int who[30];
int arr[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	/*
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		arr[i] = n;
		for(int d = 20; d>=0; d--){
			if(n>>d&1){
				if(!basis[d]){
					basis[d] = n;
					who[d] = i;
				}
				n ^= basis[d];
			}
		}
	}
	int ans = 0;
	vector<int> v;
	for(int x = 0; x<30; x++){
		if(basis[x]){
			v.push_back(who[x]);
			ans++;
		}
		else{
			break;
		}
	}
	*/
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	int ans = -1;
	for(int x = 0; x<25; x++){
		fill(basis, basis+30, 0);
		for(int i= 1; i<=N; i++){
			if(31-__builtin_clz(arr[i]) <= x){
				int n =arr[i];
				for(int d = x; d>=0; d--){
					if(n>>d&1){
						if(!basis[d]){
							basis[d] = n;
						}
						n ^= basis[d];
					}
				}
			}
		}
		bool b = 1;
		for(int d = x; d>=0; d--){
			if(!basis[d]){
				b = 0;
			}
		}
		if(b){
			ans = x;
		}
	}
	fill(basis, basis+30, 0);
	vector<int> v;
	for(int i = 1; i<=N; i++){
		if(31-__builtin_clz(arr[i]) <= ans){
			int n = arr[i];
			for(int d = ans; d>=0; d--){
				if(n>>d&1){
					if(!basis[d]){
						basis[d] = n;
						v.push_back(i);						
					}
					n ^= basis[d];
				}
			}
		}
	}
	ans++;
	vector<int> out = {0};
	cout << ans << "\n";
	for(int x = 0; x<ans; x++){
		vector<int> temp = out;
		reverse(temp.begin(), temp.end());
		for(int n : temp){
			out.push_back(n|(1<<x));
		}
	}
	for(int m : out){
		int n = 0;
		for(int k = 0; k<ans; k++){
			if(m>>k&1){
				n ^= arr[v[k]];
			}
		}
		cout << n << " ";
	}
}