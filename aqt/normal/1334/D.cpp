
// Problem : D. Minimum Euler Cycle
// Contest : Educational Codeforces Round 85 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1334/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		long long l, r;
		cin >> N >> l >> r;
		//l++, r++;
		for(int i = 1; i<=N; i++){
			if(l >= 2*(N-i) && i != N){
				l -= 2*(N-i);
				r -= 2*(N-i);
			}
			else{
				r++;
				int cur = N, lst = i-1;
				while(r > 0){
					if(l <= 0){
						cout << cur << " ";
					}
					if(cur == N && lst == N-1){
						lst = cur;
						cur = 1;
					}
					else if(cur == N){
						swap(lst, cur);
						cur++;
					}
					else if(lst == N){
						lst = cur;
						cur++; 
					}
					else if(lst > cur){
						swap(lst, cur);
						cur++;
					}
					else{
						swap(lst, cur);
					}
					l--, r--;
				}				
				cout << "\n";
				break;
			}
		}
	}
}