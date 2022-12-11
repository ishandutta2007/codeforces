
// Problem : A. Cut and Paste
// Contest : Codeforces - Codeforces Round #607 (Div. 1)
// URL : https://codeforces.com/contest/1280/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		string s;
		cin >> N >> s;
		long long x = 0, len = s.size();
		for(int i = 0; i<N; i++){
			x = s[i] - '0';
			int k = s.size();
			//cout << len << " " << (len-i-1)<< "\n";
			len += (len - i - 1 + MOD) * (x-1);
			len %= MOD;
			for(int it = 0; it<x-1 && s.size() < N; it++){
				for(int j = i+1; j<k && s.size() < N; j++){
					s.push_back(s[j]);
				}
			}
		}
		cout << len << "\n";
	}
}