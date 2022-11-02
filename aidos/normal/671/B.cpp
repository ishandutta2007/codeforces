#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;
int c[500500];
int n;
ll sum = 0;
int k;

int check1(ll x, ll k){
	ll ans = 0;
	for(int j = 0; j < n; j++){
		ans += max(0ll, c[j] * 1ll - x);
	}
	if(ans <= k) return 1;
	return 0;
}
int check2(ll x, ll k){
	ll ans = 0;
	for(int j = 0; j < n; j++){
			ans += max(0ll, x - c[j] * 1ll);
	}
	if(ans <= k) return 1;
	return 0;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i < n; i++){
    	scanf("%d", &c[i]);
    	sum += c[i];
    }
	sort(c, c + n);
	ll mx = sum/n;
	ll ans = 0;
	if(sum % n > 0) mx++;
	int l = mx, r = c[n-1], cur = c[n-1];
	while(l <= r){
		int mid = (l+r)>>1;
		if(check1(mid, k)){
			r = mid-1;
			cur = mid;
		}else l = mid+1;
	}
	ans += cur;
	ll mi = sum/n;
	l = c[0], r = mi, cur = c[0];
	while(l <= r){
		int mid = (l+r)>>1;
		if(check2(mid, k)){
			l = mid+1;
			cur = mid;
		}else r = mid-1;
	}
	cout << ans - cur << endl;
	
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}