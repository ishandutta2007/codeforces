#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int u, v;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> u >> v;
		if(v < u){
			cout << "NO" << endl;
			continue;
		}
		int both = u & v;
		u ^= both, v ^= both;
		int cntnow = 0;
		bool ok = 1;
		for(int i = 0; i <= 30; i++){
			cntnow += (u >> i) & 1;
			cntnow -= (v >> i) & 1;
			if(cntnow < 0){
				ok = 0;
				break;
			}
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}