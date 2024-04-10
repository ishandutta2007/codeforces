#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
string s;
int ans = 0;
int dfs(int l){
	int r = l + 1;
	while(s[r] != ')')
		r = dfs(r);
	if(r != l + 1) ans++;
	return r + 1;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> s;
		ans = 0;
		int l = 0;
		while(l < n + n) l = dfs(l);
		cout << ans + 1 << endl;
	}
	return 0;
}