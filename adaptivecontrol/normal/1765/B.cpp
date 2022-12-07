#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	if(n % 3 == 2){
		cout << "NO\n";
		return ;
	}
	for(int i = 0; i+1 < n; i += 3){
		if(s[i+1] != s[i+2]){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int T;
int main(){
	ios::sync_with_stdio(false);
	
	cin >> T;
	while(T--)
		solve();
	
	return 0;
}