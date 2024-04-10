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
pii x[111];
pii a[100100];
pll d[200100];
pll b[200200];
int used[100100];
int c[100100];
int sz = 0;
int n;
ll dist(pii a, pii b){
	return (a.f - b.f) * 1ll * (a.f - b.f) + (b.s-a.s) * 1ll * (b.s - a.s);
}

    long double mi[11];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    for(int i = 0; i < 3; i++){
    	cin >> x[i].f >> x[i].s;
    	mi[i] = 1e18;
    }
    cin >> n;
    for(int i = 0; i< n; i++){
    	cin >> a[i].f >> a[i].s;
    }
    long double ans = 0;
    long double cur = 1e18;
    for(int i = 0; i < n; i++){
    	ans += 2.0 * sqrt(dist(a[i], x[2]));
    	for(int j = 0; j < 2; j++){
    		cur = min(-sqrt(dist(a[i], x[2])) + sqrt(dist(a[i], x[j]))+ mi[j ^ 1], cur);
    	}
    	
    	for(int j = 0; j < 2; j++){
    		mi[j] = min(mi[j], (long double)(-sqrt(dist(a[i], x[2])) + sqrt(dist(a[i], x[j]))));
    		cur = min(mi[j], cur);
    	}
    }
    
    printf("%.12lf\n", (double)(ans + cur));
 

    







    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}