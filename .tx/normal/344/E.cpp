#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <time.h>
#include <math.h>
#include <cmath>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(stt) for (int i = 0; i < stt; ++i)
#define foj(stt) for (int j = 0; j < stt; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

// File names!!!

int main() {
    // openfiles("test");
    int n, m;
    scii(n, m);
    vell p(n);
    set<ll> hs;
    foi(n) {
        ll x;
        cin >> x;
        p[i] = x;
    }
    foi(m) {
        ll x;
        cin >> x;
        hs.insert(x);
    }
    foi(n) {
        hs.erase(p[i]);
    }
    vell h(all(hs));
    m = sz(h);

    vei cp(n, m);
    int xx = 0;
    int yy = 0;
    while (xx < m) {
        while (yy < n && (p[yy] < h[xx])) {
            cp[yy] = xx;
            yy++;
        }
        xx++;
    }

    // for (auto i : cp) cerr << i << endl;

    ll l = -1, r = 1e13, mid;
    while (r - l > 1) {
        mid = (l + r) >> 1;
        int last = 0;
        foi(n) {
            int j = last;
            for (; j < m; j++) {
                ll t1 = abs(p[i] - h[j]);
                ll t2 = abs(p[i] - h[last]);
                ll t3 = min(t1, t2) + h[j] - h[last];
                if (t3 > mid) break;
            }
            last = j;
        }
        if (last == m) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;

    return 0;
}