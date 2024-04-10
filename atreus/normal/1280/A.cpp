#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int x;
		string s;
		cin >> x >> s;
		int n = s.size();
		a[x] = 0;
		for (int i = 1; i <= s.size(); i++)
			a[i] = (int)(s[i - 1] - '0');
		int ep = 0;
		ll tot = n;
		ll len = n;
		for (int ii = 1; ii <= x; ii++){
			ep ++;
			len --;
			
			if (a[ep] == 1)
				continue;
			else if (a[ep] == 2){
				if (a[x] == 0)
					for (int i = ep + len + 1; i <= ep + 2 * len and i <= x; i++)
						a[i] = a[i - len];
				tot = (tot + len) % mod;
				len = 2ll * len % mod;
			}
			else{
				if (a[x] == 0)
					for (int i = ep + len + 1; i <= ep + 3 * len and i <= x; i++)
						a[i] = a[i - len];
				tot = (tot + 2ll * len) % mod;
				len = 3ll * len % mod;
			}
		}
		cout << tot << endl;
	}
}