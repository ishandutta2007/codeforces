#include<bits/stdc++.h>
 
using namespace std;

#define int int64_t

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = 1201;
    int a[n], b[n];
    int state[n][k];
    for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		state[i][0] = s[i] == '1';
		for(int j = 1; j < k; j++) {
			if(j >= b[i] && (j - b[i]) % a[i] == 0) {
				state[i][j] = state[i][j - 1] ^ 1;
			} else {
				state[i][j] = state[i][j - 1];
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < k; i++) {
		int cur = 0;
		for(int j = 0; j < n; j++) {
			cur += state[j][i];
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
	
}