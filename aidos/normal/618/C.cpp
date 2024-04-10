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

pair < pii, int> a[100100];
int n;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
    	pii x;
    	cin >> x.f >> x.s;
    	a[i] = mp(x, i + 1);
    }
    sort(a, a + n);
    pii p1 = a[0].f;
    pii p2 = a[1].f;
    ll deg = inf * 5ll * inf;
    unsigned ll ans =  (ll) 1e18;
    ans *= 17;
    int ind = 0;
    vector < pll > v;
    for(int i = 2; i < n; i++){
    	unsigned ll x = (a[i].f.f - p1.f) * 1ll * (a[i].f.f - p1.f);
    	x +=  (a[i].f.s - p1.s) * 1ll * (a[i].f.s - p1.s);
    	unsigned ll y =(a[i].f.f - p2.f) * 1ll * (a[i].f.f - p2.f) ;
    	y+= (a[i].f.s - p2.s) * 1ll * (a[i].f.s - p2.s);
    	unsigned ll z = (p1.f - p2.f) * 1ll * (p1.f - p2.f);
    	z+= (p1.s - p2.s) * 1ll * (p1.s - p2.s);
    	ll cur = (a[i].f.f - p1.f) * 1ll * (p2.s - p1.s) - (a[i].f.s - p1.s) * 1ll * (p2.f - p1.f);
    	
    	if(cur < 0) cur = -cur;
    	if(cur==0) continue;
    	if( cur < ans){
    		ans = cur;
    		ind = i;
    	}
    }
    cout << a[0].s <<  " " << a[1].s <<  " "<< a[ind].s << endl;

    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}