#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6;
const long long INF = 1e9 + 19;

int n;
long long a[N];
int use[N];
long long mx = 0;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mx = max(mx, a[i]);
    }
}

vector < pair < long long, int > > f;

int getMex() {
    int cur = 0;
    for (; use[cur] > 0; cur++);
    assert(cur < 100);
    return cur;
}
set < pair < long long, int > > q;

void add(long long pos, int val) {
    if (pos * 1.0 * pos < 1e18)
        q.insert(mp(pos * pos, val + 1));
    long long r = pos - 1;
    if (r * 1.0 * r * r * r < 1e18)
        q.insert(mp(r * r * r * r + 1, -(f.back().sc + 1)));
    f.pb(mp(pos, val));
}

void solve() {
    f.pb(mp(0, 0));
    use[0]++;

    add(4, 1);

    while (f.back().fr <= mx) {
        assert(!q.empty());
        long long t = q.begin()->fr;         
        int type = q.begin()->sc;
        q.erase(q.begin());
        //db2(t, type);
        if (type < 0) {
            use[-type - 1]--;
            assert(use[-type - 1] >= 0);
        }
        if (type > 0) {
            use[type - 1]++;
        }
        add(t, getMex());
    }
    //for (auto x: f)
        //db2(x.fr, x.sc);

    
    int res = 0;    
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(f.begin(), f.end(), mp(a[i], (int)INF)) - f.begin();
        pos--;
        assert(pos >= 0);
        assert(f[pos].fr <= a[i]);
        if (pos + 1 < (int)f.size())
            assert(a[i] < f[pos + 1].fr);
        res ^= f[pos].sc;
    }

    //db(res);
    if (res == 0)
        puts("Rublo");
    else
        puts("Furlo");
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}