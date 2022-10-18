#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		long long n,m,k;
		cin >> n >> m >> k;
		if(k<=1 || m>(n*(n-1)/2)){
			cout << "NO\n";
			continue;
		}
		if(n==1){
			cout << "YES\n";
			continue;
		}
		if(k==2){
			cout << "NO\n";
			continue;
		}
		if(k==3){
			if(m!=(n*(n-1)/2)){
				cout << "NO\n";
			}
			else{
				cout << "YES\n";
			}
		}
		else{
			if(m>=n-1){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
	return 0;
}