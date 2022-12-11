
// Problem : D. Huge Strings
// Contest : Codeforces - Codeforces Round #438 by Sberbank and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL : https://codeforces.com/contest/868/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
bitset<1024> bs[10][205];
string pre[205], suf[205];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int idx = 1; idx<=N; idx++){
		string s;
		cin >> s;
		pre[idx] = s;
		suf[idx] = s;
		for(int b = 0; b<10; b++){
			for(int i = 0; i+b<s.size(); i++){
				int x = 0;
				for(int j = i; j<=i+b; j++){
					x <<= 1;
					x += s[j]-'0';
				}
				bs[b][idx].set(x);
				//cout << b << " " << x << "\n";
			}
		}
		//cout << " " << i << " " << bs[0][i][0] << "\n";
	}
	int Q;
	cin >> Q;
	while(Q--){
		N++;
		int x, y;
		cin >> x >> y;
		string t = suf[x] + pre[y];
		for(int b = 0; b<10; b++){
			bs[b][N] = bs[b][x] | bs[b][y];
			for(int i = 0; i+b<t.size(); i++){
				int x = 0;
				for(int j = i; j<=i+b; j++){
					x <<= 1;
					x += t[j] - '0';
				}
				bs[b][N].set(x);
			}
		}
		pre[N] = pre[x] + pre[y];
		if(pre[N].size() > 100){
			pre[N] = pre[N].substr(0, 100);
		}
		suf[N] = suf[x] + suf[y];
		if(suf[N].size() > 100){
			suf[N] = suf[N].substr(suf[N].size()-100, 100);
		}
		int ans = 0;
		for(int b = 0; b<10; b++){
			if(bs[b][N].count() == (1<<(b+1))){
				ans = b+1;
			}
		}
		//cout << bs[2][N].to_string() << "\n";
		cout << ans << "\n";
	}
}