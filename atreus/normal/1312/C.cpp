#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
const int maxn = 500 + 5;
const int inf = 1e9;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll mxm = *max_element(a.begin(), a.end());
		ll x = 1;
		while (x < mxm)
			x *= k;
		while (x > 0){
			for (int i = 0; i < n; i++){
				if (a[i] >= x){
					a[i] -= x;
					break;
				}
			}
			x /= k;
		}
		bool flag = 1;
		for (int i = 0; i < n; i++)
			if (a[i] != 0)
				flag = 0;
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}