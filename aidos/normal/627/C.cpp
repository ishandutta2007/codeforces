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


int n, d, m;
ll ans[200200];
pii x[200200];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d", &d, &n, &m);
    m++;
    for(int i = 1; i < m; i++){
    	scanf("%d %d", &x[i].f, &x[i].s);
    }
    x[0] = mp(0, 0);
    x[m] = mp(d, 0);
    m++;
    sort(x, x + m);
    if(d == n) {
    	cout << 0 << endl;
    	return 0;
    }
    ans[0] = 0;
    deque < int > o;
    deque < ll > summ1;
    o.pb(0);
    summ1.pb(n);
    ll su = 0;
    
    for(int i = 1; i < m; i++){
    	if(x[i].f - x[i-1].f > n){
    		cout << -1 << endl;
    		return 0;
    	}
    	int need = x[i].f - x[i-1].f;
    	while(o.size() > 0 && need > 0){
    		ll ne = min(need + 0ll, summ1.front()-su);
    		need -= ne;
    		su += ne;
    		ans[0] += ne * 1ll * x[o.front()].s;
    		if(summ1.front() == su){
    			o.pop_front();
    			summ1.pop_front();
    		}
    	}
    	while(o.size() > 0){
    		if(x[o.back()].s > x[i].s){
    			o.pop_back();
    			summ1.pop_back();
    		} else break;
    	}
    	o.pb(i);
    	summ1.pb(su+n);
    }
    cout << ans[0] << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}