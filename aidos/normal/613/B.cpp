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

int n, cf, cm, A;
ll m;
pii a[100100];
int ans[100100];
ll sum[100100];
ll check(int pos, int su){
	int pp = upper_bound(a, a + n, mp(su, inf)) - a;
	//cout << pp << " " << su << " " << pos << endl;
	pp--;
	if(pp < pos) {
		if(pp < 0) return 0;
		ll cur = sum[0] - sum[pp+1];
		return su * 1ll * (pp +1)- cur;
	}
	ll cur = sum[0] - sum[pos+1];
	return su * 1ll * (pos+1) - cur;
}
int get(int pos, ll need){
	int l = 0, r = A-1;
	int ans = 0;
	while(l <= r){
			int mid = (l + r) >> 1;
			if(check(pos, mid) <=need ) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid-1;
			}
		}
		return ans;
}                    

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >>A >>  cf >> cm >> m;
    for(int i = 0; i < n; ++i){
    	cin  >> a[i].f;
    	a[i].s = i;
    }
	sort(a, a + n);
	for(int i = n-1; i >= 0; i--){
		sum[i] = (sum[i+1] + a[i].f);
	}
	if(A * 1ll * n - sum[0] <= m){
		cout << cm * 1ll * A + cf * 1ll * n << endl;
		for(int i = 0; i < n; i++){
			printf("%d ", A);
		}
		cout<<endl;
		return 0;
	}
	
    ll cur = get(n, m) * 1ll * cm;
	int ind = n;
	cerr << cur << endl;
	for(int i = n-1; i >= 0; i--){
		if(( n - i) * 1ll * A - sum[i]> m) break;
		int ans = get(i-1, m - ( n - i)  *1ll * A+ sum[i]);
	//	cout << m - ( n - i)  *1ll * A+ sum[i] << endl;
	//	cout << a[i].f << endl;
	//	cout << ans << endl;
		if(cur < cf * 1ll * (n - i) + ans * 1ll * cm){
			cur = cf * 1ll * (n - i) + ans * 1ll * cm;
			ind = i;
		}
	}
	m -= (n - ind) * 1ll * A - sum[ind];
	int ge = get(ind-1, m);
	for(int i=n-1; i >= ind; i--){
		ans[a[i].s] = A;
	}
	for(int i = 0; i < ind; i++){
		ans[a[i].s] = a[i].f;
		if(a[i].f > ge) continue;
		int need = ge - a[i].f;
		ans[a[i].s] = ge;
	}
	cout << cur << endl;
	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	
	
	

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}