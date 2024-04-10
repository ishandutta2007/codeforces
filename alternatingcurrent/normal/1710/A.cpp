#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll Mod = 998244353;

int T;
ll n, m, k;
ll a[1000100];
bool calc(){
	ll res = 0;
	bool hasbig = 0;
	rep(i, k)
		if(a[i] / m >= 2){
			res += a[i] / m;
			if(a[i] / m > 2)
				hasbig = 1;
		}
	bool ret = (res >= n);
	if(!hasbig && n % 2 == 1)
		ret = 0;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		rep(i, k)
			cin >> a[i];
		int ans = calc();
		swap(n, m);
		ans |= calc();
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}