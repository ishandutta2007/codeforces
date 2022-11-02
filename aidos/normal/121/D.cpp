#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <bitset>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
ll k;
pll a[100100];
ll b[100100];
ll lim = 2 * (ll)(1e18) + 1;
ll M = lim;
vector<ll> d, c;
ll L[2000100], R[2000100];

void precalcleft(){
	for(int i = 0 ; i < n; i++) {
		b[i] = a[i].f;
	}
	sort(b, b + n);
	int r = n-1;
	for(int i = 0; i < c.size(); i++) {
		L[i] = k+1;
	}
	ll s = 0;
	for(int i = (int)c.size()-1; i >= 0 && s <= k; i--) {
		
		if(i + 1 < c.size() && n != r+1) {
			ll a = n-r-1;
			ll b = c[i+1] - c[i];
			if((k+1)/b >= a) {
				s += a*b;
			}
			else s = k+1;
		}
		while(s <= k && r>=0 && c[i]<b[r]) {
			s += b[r] - c[i];
			r--;
		}
		L[i] = min(s, k+1);
	}
}
void precalcright(){
	for(int i = 0 ; i < n; i++) {
		b[i] = a[i].s;
	}
	sort(b, b + n);
	int r = 0;
	for(int i = 0; i < c.size(); i++) {
		R[i] = k+1;
	}
	ll s = 0;
	for(int i = 0; i < c.size(); i++){
		
		if(i > 0 && r>0) {
			ll a = r;
			ll b = c[i] - c[i-1];
			if((k+1)/b >= a) {
				s += a*b;
			}
			else s = k+1;
		}
		while(s <= k && r<n && c[i]>b[r]) {
			s += c[i] - b[r];
			r++;
		}
		R[i] = min(s, k+1);
	}
}
bool can(int l) {
	for(int i = l-1; i < c.size(); i++) {
		if(c[i] - c[i-l+1] > M) continue;
		if(L[i-l+1] + R[i] <= k) {
			//cout << c[i-l+1] << " "<< c[i] << "\n";
			return 1;
		}
	}
	return 0;
}
void solve(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i].f >> a[i].s;
		M = min(a[i].s - a[i].f, M);
	}
	d.pb(4);
	d.pb(7);
	while(d.size() > 0){
		vector<ll> dd;
		for(int i = 0; i < d.size(); i++) {
			c.pb(d[i]);
			if( (lim-4)/10 >= d[i] && d[i]*10 + 4 <= lim) dd.pb(d[i] * 10 + 4);
			if( (lim-7)/10 >= d[i] && d[i]*10 + 7 <= lim) dd.pb(d[i] * 10 + 7);
		}
		d = dd;
	}	
	precalcleft();
	precalcright();
	int l = 1, r = c.size();
	int res = 0;
	while(l <= r) {
		int mid = (l+r)>>1;
		if(can(mid)) {
			res = mid;
			l = mid+1;
		}else r = mid-1;
	}
	cout << res << "\n";
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}