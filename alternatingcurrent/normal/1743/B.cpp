#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin >> n;
	
	cout << "1 ";
	cout << n << " ";
	for(int i = 2; i <= n-1; ++i)
		cout << i << " ";
	cout << endl;
	
}

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	rep(i, T)
		solve();
	
	return 0;
}