#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y){
	if(!a){
		x = 0, y = 1;
		return b;
	}
	ll ret = exgcd(b % a, a, y, x);
	x -= y * (b / a);
	return ret;
}

int n;
int a[300300], b[300300], d[300300];
ll ans = 0;
ll presum[300300];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)
		cin >> a[i] >> b[i], d[i] = b[i] - a[i], ans += a[i];
	sort(d, d + n);
	reverse(d, d + n);
	rep(i, n)
		presum[i + 1] = presum[i] + d[i];
	int tar = n;
	rep(i, n)
		if(presum[i] >= presum[i + 1]){
			tar = i;
			break;
		}
	int q;
	cin >> q;
	while(q--){
		ll qx, qy;
		cin >> qx >> qy;
		ll qx0, qy0;
		ll g;
		if(qx <= qy)
			g = exgcd(qx, qy, qx0, qy0);
		else
			g = exgcd(qy, qx, qy0, qx0);
		if(n % g != 0){
			cout << "-1\n";
			continue;
		}
		qx0 *= (n / g), qy0 *= (n / g);
		ll k = qx / g;
		qy0 %= k; qy0 -= k;
		ll lb = (tar / qy - qy0) / k;
		auto check = [&](ll ny) -> ll {
			if(ny > n || ny < 0)
				return 0xc0c0c0c0c0c0c0c0ll;
			return presum[ny];
		};
//		cout << "res: " << qy0 << " " << k << " to " << qy << "*" << lb << endl;
		ll res = max(check((qy0 + k * lb) * qy), check((qy0 + k * (lb + 1)) * qy));
		if(res > (ll)0xc0c0c0c0c0c0c0c0ll)
			cout << res + ans << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}