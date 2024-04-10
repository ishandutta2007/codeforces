#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<1000;i++){
		if(n>=i*2020 && (n-i*2020)%2021 == 0){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}