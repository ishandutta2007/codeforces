#include <iostream>

using namespace std;

const int MAXN = 500 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
char c[MAXN];
int l[MAXN], r[MAXN], u[MAXN], d[MAXN], n;

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

long long getT(int x, int dx, int bx, int t[]) {
    if(dx <= 0) {
        if(x >= bx)
            return INF;
        return t[x + 1] + 1;
    }
    int k = (x < bx? 0 : (x - bx) / dx + 1);
    x -= k * dx;
    return (long long)k * n + t[x + 1] + 1;
}

int solve(int h, int w) {
    l[0] = -1;
    r[0] = -1;
    u[0] = -1;
    d[0] = -1;
    int x = 0, y = 0, minx = 0, maxx = 0, miny = 0, maxy = 0;
    for(int i = 0; i < n; i++) {
        if(c[i] == 'U')
            x--;
        else if(c[i] == 'D')
            x++;
        else if(c[i] == 'L')
            y--;
        else if(c[i] == 'R')
            y++;
        if(x < minx) {
            u[-x] = i;
            minx = x;
        }
        if(x > maxx) {
            d[x] = i;
            maxx = x;
        }
        if(y < miny) {
            l[-y] = i;
            miny = y;
        }
        if(y > maxy) {
            r[y] = i;
            maxy = y;
        }
    }
    int res = 0;
    for(int i = 0; i < h; i++) {
        int ll = -1, rr = w - 1;
        while(ll < rr - 1) {
            int mm = (ll + rr) / 2;
            long long tl = getT(mm, -y, -miny, l), tr = getT(w - mm - 1, y, maxy, r),
                tu = getT(i, -x, -minx, u), td = getT(h - i - 1, x, maxx, d);
            if(tl == INF && tr == INF && tu == INF && td == INF)
                return -1;
            if(tl < min(tr, min(tu, td)))
                ll = mm;
            else
                rr = mm;
        }
        int lll = rr;
        long long tl = getT(lll, -y, -miny, l), tr = getT(w - lll - 1, y, maxy, r),
            tu = getT(i, -x, -minx, u), td = getT(h - i - 1, x, maxx, d);
        if(min(tu, td) < INF && min(tu, td) < min(tl, tr)) {
            ll = 0;
            rr = w;
            while(ll < rr - 1) {
                int mm = (ll + rr) / 2;
                long long ttl = getT(mm, -y, -miny, l),
                    ttr = getT(w - mm - 1, y, maxy, r),
                    ttu = getT(i, -x, -minx, u),
                    ttd = getT(h - i - 1, x, maxx, d);
                if(ttl == INF && ttr == INF && ttu == INF && ttd == INF)
                    return -1;
                if(ttr < min(ttl, min(ttu, ttd)))
                    rr = mm;
                else
                    ll = mm;
            }
            int rrr = ll;
            add(res, (long long)(rrr - lll + 1) * (min(tu, td) % MOD) % MOD);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> n >> h >> w;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    int ans = solve(h, w);
    if(ans == -1) {
        cout << ans << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++)
        if(c[i] == 'U')
            c[i] = 'L';
        else if(c[i] == 'D')
            c[i] = 'R';
        else if(c[i] == 'L')
            c[i] = 'U';
        else if(c[i] == 'R')
            c[i] = 'D';
    swap(h, w);
    int ans0 = solve(h, w);
    if(ans0 == -1) {
        cout << ans0 << '\n';
        return 0;
    }
    add(ans, ans0);
    cout << ans << '\n';
    return 0;
}