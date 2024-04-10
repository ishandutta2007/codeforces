#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
long long n;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		if(n % 2050LL != 0) cout << "-1" << endl;
		else{
			n /= 2050LL;
			long long ans = 0LL;
			while(n){
				ans += n % 10LL;
				n /= 10LL;
			}
			cout << ans << endl;
		} 
	}
	return 0;
}