#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
// head

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	ll n, k, x;
	cin >> n >> k >> x;
	bool can0 = false;
	vector<ll> a(n);
	ll c = 0, lo = -1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] % x == 0 && abs(a[i]) / x <= k)
			can0 = true;
		if(a[i] < 0)
			c++;
		if(lo == -1 || abs(a[i]) < abs(a[lo]))
			lo = i;
	}
	if(c % 2 == 1 || abs(a[lo]) / x + 1 <= k) { // < 0
		if(c % 2 == 0) {
			ll w = abs(a[lo]);
			while(w >= 0) {
				w -= x;
				k--;
			}
			if(a[lo] < 0)
				a[lo] = -w;
			else
				a[lo] = w;
		}
		priority_queue<pii> q;
		for(int i = 0; i < n; i++)
			q.push(mp(-abs(a[i]), i));
		for(int i = 0; i < k; i++) {
			pii o = q.top();
			q.pop();
			q.push(mp(o.ff-x, o.ss));
		}
		while(!q.empty()) {
			pii o = q.top();
			q.pop();
			if(a[o.ss] < 0)
				a[o.ss] = o.ff;
			else
				a[o.ss] = -o.ff;
		}
		for(int i = 0; i < n; i++)
			cout << a[i] << ' ';
	} else if(can0) { // = 0
		for(int i = 0; i < n; i++) {
			if(can0 && a[i] % x == 0 && abs(a[i]) / x <= k) {
				a[i] = 0;
				can0 = false;
			}
			cout << a[i] << ' ';
		}
		return 0;
	} else { // > 0
		ll w = abs(a[lo]) - x*k;
		if(a[lo] < 0)
			a[lo] = -w;
		else
			a[lo] = w;
		for(int i = 0; i < n; i++)
			cout << a[i] << ' ';
	}
}