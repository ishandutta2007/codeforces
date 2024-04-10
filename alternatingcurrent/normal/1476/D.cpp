#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmax(int a, int b){
	return (a > b) ? a : b;
}

int T;
int n;
string s;
int ans[300300];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> s;
		int l = 0, r = 0;
		while(l < n){
			while(r < n && (((r - l) % 2 == 0 && s[r] == s[l]) || ((r - l) % 2 == 1 && s[r] != s[l]))) r++;
			for(int i = l; i < r; i++) ans[i] = r - l;
			l = r;
		}
		rep(i, n+1){
			int ret = 0;
			if(i && s[i - 1] == 'L') ret = qmax(ret, ans[i-1]);
			if(i < n && s[i] == 'R') ret = qmax(ret, ans[i]);
			cout << ret+1 << " ";
		}
		cout << endl;
	}
	return 0;
}