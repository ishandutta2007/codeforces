
// Problem : D1. Two Hundred Twenty One (easy version)
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/D1
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, Q;
string s;
int pre[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> Q;
		cin >> s;
		for(int i = 1; i <= N; i++){
			if(i%2 == 0){
				pre[i] = pre[i-1] + (-1) * (s[i-1] -'0');
			}
			else{
				pre[i] = pre[i-1] + (s[i-1] - '0');
			}
		}
		while(Q--){
			int l, r;
			cin >> l >> r;
			if(pre[r] - pre[l-1] == 0){
				cout << 0 << "\n";
			}
			else if((r - l + 1) % 2){
				cout << 1 << "\n";
			}
			else{
				cout << 2 << "\n";
			}
		}
	}
}