
// Problem : E. A-Z Graph
// Contest : Codeforces - Educational Codeforces Round 105 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1494/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
map<int, char> mp[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	int cnt = 0, cnteven = 0;
	while(Q--){
		char cmd;
		cin >> cmd;
		if(cmd == '+'){
			int a, b;
			char c;
			cin >> a >> b >> c;
			mp[a][b] = c;
			if(mp[b].count(a)){
				char d= mp[b][a];
				if(c == d){
					cnt++;
				}
				else{
					cnteven++;
				}
			}
		}
		else if(cmd == '-'){
			int a, b;
			cin >> a >> b;
			char c= mp[a][b];
			if(mp[b].count(a)){
				char d = mp[b][a];
				if(c == d){
					cnt--;
				}
				else{
					cnteven--;
				}
			}
			mp[a].erase(b);
		}
		else{
			int n;
			cin >> n;
			n--;
			if(cnt){
				cout << "YES\n";
			}
			else if(cnteven && n%2 == 0){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
		//cout << cnt << " " << cnteven << "\n";
	}
}