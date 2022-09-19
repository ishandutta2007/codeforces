#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int Maxn = 1e5 + 10;

ll a[13][Maxn];

bitset<4096> bt[Maxn << 1];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k, q;
	cin >> n >> k >> q;
	for(int i = 0; i < k; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	int all = (1 << k);
	for(int i = 0; i < all; i++)
		for(int j = 0; j < k; j++)
			bt[j][i] = (i >> j) & 1;
	ll t, x, y;
	ll cnt = k;
	for(int i = 0; i < q; i++){
		cin >> t >> x >> y;
		if(t == 1)
			bt[cnt ++] = bt[x - 1] | bt[y - 1];
		if(t == 2)
			bt[cnt ++] = bt[x - 1] & bt[y - 1];
		if(t == 3){
			x --;
			ll l = 0, r = 2000000000ll, mid;
			while(l + 1 < r){
				mid = (l + r) >> 1;
				ll res = 0;
				for(int j = 0; j < k; j++){
					res |= ((mid <= a[j][y]) << j);
				}
				if(bt[x][res]) l = mid;
				else r = mid;
			}
			cout << l << '\n';
		}
	}
	return 0;
}