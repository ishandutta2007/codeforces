#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll maxn = 5e5 + 10;
const ll mod = 1e9 + 7;
const ll base = 13;
const ll inf = 1e18;

ll n, h, w;
string s;
ll a[maxn], b[maxn];
map<int, ll> mp;

void getarray(string p, bool address){
	mp.clear();
	int u = 0, d = 0, par = 0, minp = 0, maxp = 0;
	for (int i = 0; i < p.size(); i++){
		if (p[i] == 'U'){
			u ++;
			par --;
		}
		else{
			d ++;
			par ++;
		}
		if (!mp.count(par))
			mp[par] = i + 1;
		minp = min(minp, par);
		maxp = max(maxp, par);
	}
	minp = abs(minp);
	for (int i = 1; i <= h; i++){
		if (i <= minp){
			if (address == 0)
				a[i] = min(a[i], mp[-i]);
			else
				b[i] = min(b[i], mp[-i]);
		}
		else{
			if (u > d){
				int t = u - d;
				int lo = 0, hi = h + 1;
				while (hi - lo > 1){
					int mid = (lo + hi) >> 1;
					if (i - 1ll * mid * t <= minp)
						hi = mid;
					else
						lo = mid;
				}
				if (address == 0)
					a[i] = min(a[i], 1ll * hi * (int)p.size() + mp[-(i - 1ll * hi * t)]);
				else
					b[i] = min(b[i], 1ll * hi * (int)p.size() + mp[-(i - 1ll * hi * t)]);
			}
		}
	}
	for (int i = 1; i <= h; i++){
		if (i + maxp > h){
			if (address == 0)
				a[i] = min(a[i], mp[h - i + 1]);
			else
				b[i] = min(b[i], mp[h - i + 1]);
		}
		else{
			if (d > u){
				int t = d - u;
				int lo = 0, hi = h + 1;
				while (hi - lo > 1){
					int mid = (lo + hi) >> 1;
					if (i + 1ll * mid * t + maxp > h)
						hi = mid;
					else
						lo = mid;
				}
				if (address == 0)
					a[i] = min(a[i], 1ll * hi * (int)p.size() + mp[h - (i + 1ll * hi * t) + 1]);
				else
					b[i] = min(b[i], 1ll * hi * (int)p.size() + mp[h - (i + 1ll * hi * t) + 1]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> h >> w;
	cin >> s;
	string p;
	for (int i = 0; i < n; i++){
		if (s[i] == 'U')
			p += 'U';
		if (s[i] == 'D')
			p += 'D';
	}
	for (int i = 1; i <= h; i++)
		a[i] = inf;
	for (int i = 1; i <= w; i++)
		b[i] = inf;
	getarray(p, 0);
	vector<int> v;
	for (int i = 0; i < n; i++)
		if (s[i] == 'U' or s[i] == 'D')
			v.push_back(i + 1);
	int m = v.size();
	for (int i = 1; i <= h; i++){
		if (a[i] == inf)
			continue;
		a[i] = 1ll * ((a[i] - 1) / m) * n + v[(a[i] - 1) % m];
	}
	p.clear();
	for (int i = 0; i < n; i++){
		if (s[i] == 'L')
			p += 'U';
		if (s[i] == 'R')
			p += 'D';
	}
	swap(h, w);
	getarray(p, 1);
	v.clear();
	for (int i = 0; i < n; i++)
		if (s[i] == 'L' or s[i] == 'R')
			v.push_back(i + 1);
	m = v.size();
	for (int i = 1; i <= h; i++){
		if (b[i] == inf)
			continue;
		b[i] = 1ll * ((b[i] - 1) / m) * n + v[((b[i] - 1) % m)];
	}
	sort(a + 1, a + w + 1);
	sort(b + 1, b + h + 1);
	if (a[w] == inf and b[h] == inf)
		return cout << -1 << endl, 0;
	ll answer = 0;
/*	for (int i = 1; i <= w; i++)
		cout << a[i] << " ";
	cout << endl;
	for (int i = 1; i <= h; i++)
		cout << b[i] << " ";
	cout << endl; */
	for (int i = 1; i <= w; i++){
		int j = lower_bound(b + 1, b + h + 1, a[i]) - b;
		answer = (answer + 1ll * a[i] * (h - j + 1) % mod) % mod;
	}
	for (int i = 1; i <= h; i++){
		int j = upper_bound(a + 1, a + w + 1, b[i]) - a;
		answer = (answer + 1ll * b[i] * (w - j + 1) % mod) % mod;
	}
	cout << answer << endl;
}