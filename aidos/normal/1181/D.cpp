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
int n, q, m;
pii c[500500];
int ans[500500];
pll g[500500];

int get(vector<int> &a, vector<int> &b, ll k) {
    k %= (a.size() + b.size());
    k += 1;
    int r = min((int)k, (int)a.size());
    int l = min((int)k, (int)b.size());
    while(l + r > k) {
        if(a[r-1] > b[l-1]) r-=1;
        else l-=1;
    }
    if(l == 0)
        return a[r-1];
    if(r == 0)
        return b[l-1];
    return max(a[r-1], b[l-1]);
}
vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c;
    int j = 0;
    for(int i = 0; i <= a.size(); i++) {
        while(j < b.size() && (i == a.size() || a[i] >= b[j])) {
            c.pb(b[j]);
            j++;
        }
        if(i != a.size())
            c.pb(a[i]);
    }
    return c;
}
void solve(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < m; i++) c[i].s = i+1;
	for(int i = 0; i < n; i++){
	    int x;
	    scanf("%d", &x);
	    c[x-1].f++;
	}
	sort(c, c+m);
	vector<int> a, b;
	for(int i = 0; i < q; i++) {
	    scanf("%lld", &g[i].f);
	    g[i].s = i;
	    g[i].f -= n;
	}
	sort(g, g + q);
	int t = 0;
	ll y = 0;
	for(int i = 0; i < m; ) {
	    int j = i;
	    vector<int> cc;
	    while(i < m && c[i].f == c[j].f) {
	        cc.pb(c[i].s);
	        i++;
	    }
	    b = merge(b, cc);
	    if(i == m) break;
	    if(b.size() > 50) {
	        a = merge(a, b);
	        b.clear();
	    }
	    ll ny = y + (c[i].f - c[j].f) * 1ll * i;
	    while(t < q && g[t].f <= ny) {
	        ans[g[t].s] = get(a, b, g[t].f-y-1);
	        t += 1;
	    }
	    y = ny;
	}
	for(int i = t; i < q; i++) ans[g[i].s] = (g[i].f-y-1) % m + 1;
	for(int i = 0; i < q; i++) {
	    printf("%d\n", ans[i]);
	}
	
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