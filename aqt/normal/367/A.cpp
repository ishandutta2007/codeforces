
// Problem : A. Sereja and Algorithm
// Contest : Codeforces - Codeforces Round #215 (Div. 1)
// URL : https://codeforces.com/contest/367/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int pre[4][100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	string s;
	cin >> s;
	N = s.size();
	for(int i = 1; i<=N; i++){
		pre[s[i-1]-'x'][i]++;
		for(int j = 0; j<3; j++){
			pre[j][i] += pre[j][i-1];
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		int l, r;
		cin >> l >> r;
		int x = pre[0][r] - pre[0][l-1];
		int y = pre[1][r] - pre[1][l-1];
		int z = pre[2][r] - pre[2][l-1];
		//cout << s.substr(l, r-l+1) << "\n";
		//cout << x << " " << y << " " << z << "\n";
		if(r -l + 1 <= 2 || abs(x-y) <= 1 && abs(y-z) <= 1 && abs(x-z) <= 1){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}