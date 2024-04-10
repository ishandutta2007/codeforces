#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int ans = 0;
		rep(i, (int)s.size()){
			ans = max(ans, s[i] - '0');
		} 
		cout << ans << endl;
	} 
	return 0;
}