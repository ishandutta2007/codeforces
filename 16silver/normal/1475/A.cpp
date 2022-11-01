#include <bits/stdc++.h>
using namespace std;
void solve(){
	long long x;
	cin >> x;
	for(long long i=0;i<60;i++){
		if(x == (1LL<<i)){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}