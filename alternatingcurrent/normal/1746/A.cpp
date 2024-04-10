#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int a[55];
void solve(){
	cin >> n >> k;
	
	rep(i, n)
		cin >> a[i]; 
	
	bool ok = 0;
	rep(i, n)
		ok |= a[i];
	
	cout << (ok ? "YES\n" : "NO\n");
}

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}