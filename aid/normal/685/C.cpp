#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
const long long INF = 3000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
long long a[MAXN][4], l[4], r[4], aa[4];

bool check(int n, long long d) {
    for(int it = 0; it < 2; it++) {
        bool bad = false;
        for(int i = 0; i < 4; i++) {
            l[i] = a[0][i] - d + it;
            r[i] = a[0][i] + d + it;
            if(l[i] & 1)
                l[i]++;
            if(r[i] & 1)
                r[i]--;
            l[i] /= 2;
            r[i] /= 2;
            if(l[i] > r[i])
                bad = true;
        }
        for(int i = 1; i < n; i++)
            for(int j = 0; j < 4; j++) {
                long long ll = a[i][j] - d + it, rr = a[i][j] + d + it;
                if(ll & 1)
                    ll++;
                if(rr & 1)
                    rr--;
                ll /= 2;
                rr /= 2;
                l[j] = max(l[j], ll);
                r[j] = min(r[j], rr);
                if(l[j] > r[j])
                    bad = true;
            }
        if(bad)
            continue;
        long long lad = l[0] + l[3], rad = r[0] + r[3],
            lbc = l[1] + l[2], rbc = r[1] + r[2];
        if(max(lad, lbc) > min(rad, rbc))
            continue;
        long long x = max(lad, lbc);
        if(x <= r[0] + l[3]) {
            aa[0] = l[0] + (x - l[0] - l[3]);
            aa[3] = l[3];
        }
        else {
            aa[0] = r[0];
            aa[3] = l[3] + (x - r[0] - l[3]);
        }
        if(x <= r[1] + l[2]) {
            aa[1] = l[1] + (x - l[1] - l[2]);
            aa[2] = l[2];
        }
        else {
            aa[1] = r[1];
            aa[2] = l[2] + (x - r[1] - l[2]);
        }
        for(int i = 0; i < 4; i++)
            aa[i] = aa[i] * 2 - it;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            long long x, y, z;
            cin >> x >> y >> z;
            a[i][0] = x + y + z;
            a[i][1] = x + y - z;
            a[i][2] = x - y + z;
            a[i][3] = x - y - z;
        }
        long long ll = -1, rr = INF;
        while(ll < rr - 1) {
            long long mm = (ll + rr) / 2;
            if(check(n, mm))
                rr = mm;
            else
                ll = mm;
        }
        check(n, rr);
        cout << (aa[0] + aa[3]) / 2 << ' '
             << (aa[0] - aa[2]) / 2 << ' '
             << (aa[0] - aa[1]) / 2 << '\n';
    }
    return 0;
}