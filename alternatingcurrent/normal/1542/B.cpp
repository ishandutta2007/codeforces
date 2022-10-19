#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
ll n, a, b;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> a >> b;
		bool ok = (bool)((n % b) == (1 % b));
		if(a != 1){
			ll nowval = a;
			while(nowval <= n){
				ok |= (bool)((n % b) == (nowval % b));
				nowval *= a;
			}
		}
		if(ok)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	return 0;
}