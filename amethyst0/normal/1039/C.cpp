#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <time.h>
#define ll long long
#define mp make_pair
#define pii pair <int, int>

using namespace std;

const int maxn = (int)5e5 + 10, mod = (int)1e9 + 7;
ll c[maxn];

ll st[maxn];

vector <int> vert;
int cn;

int p[maxn];

int getp(int x) {
    return p[x] = (p[x] == x ? x : getp(p[x]));
}

void merg(int x, int y) {
    vert.push_back(x);
    vert.push_back(y);
    x = getp(x);
    y = getp(y);
    
    if (x != y) {
        cn++;
        p[x] = y;
    }
}

int main() {
    st[0] = 1;
    for (int i = 1; i < maxn; i++) {
        st[i] = st[i - 1] << 1;
        if (st[i] >= mod) {
            st[i] -= mod;
        }
    }
    
    int n, m, k;
    
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &c[i]);
    }

    vector <pair <ll, pii> > g;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        ll z = c[x] ^ c[y];
        g.push_back(mp(z, mp(x, y)));
    }
    
    sort(g.begin(), g.end());
    
    ll cnt = st[k];
    
    ll ans = 0;
    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    
    for (int i = 0; i < (int)g.size(); ) {
        int r = i;
        
        vert.clear();
        cn = 0;
        
        cnt--;
        if (cnt < 0) {
            cnt += mod;
        }
        
        while (r < (int)g.size() && g[r].first == g[i].first) {
            merg(g[r].second.first, g[r].second.second);
            r++;
        }
        
        ans = (ans + (ll)st[n - cn]) % mod;
        
        for (int j = 0; j < (int)vert.size(); j++) {
            p[vert[j]] = vert[j];
        }
        
        i = r;
    }
    
    ans = (ans + (ll)cnt * st[n]) % mod;
    
    cout << ans << endl;
    
    return 0;
}