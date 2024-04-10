#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, m;
string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m >> s >> t;
		if(m > 1 && s.substr(n - m + 1, m - 1) != t.substr(1, m - 1)){
			cout << "NO" << endl;
			continue;
		} else {
			int mn = 1, mx = 0;
			for(int i = 0; i <= n - m; i++)
				mn = min(mn, s[i] - '0'), mx = max(mx, s[i] - '0');
			if(t[0] - '0' < mn || t[0] - '0' > mx)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}