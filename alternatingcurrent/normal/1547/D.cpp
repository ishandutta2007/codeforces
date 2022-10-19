#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n;
ll x[200200];

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> x[i];
		ll nowval = 0;
		rep(i, n){
			ll res = 0;
			rep(bit, 30){
				if(!(x[i] & (1 << bit)) && (nowval & (1 << bit))){
					res |= (1 << bit);
				}
			}
			cout << res << " ";
			nowval |= x[i];
		}
		cout << endl;
	}
	return 0;
}