#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int mod = 1009;

struct vt {
    ld x, y;

    vt() {
        x = y = 0;
    }

    vt(ld x, ld y): x(x), y(y) {

    }
};

vt operator - (vt a, vt b) {
    a.x -= b.x;
    a.y -= b.y;

    return a;
}

vt operator +(vt a, vt b) {
    a.x += b.x;
    a.y += b.y;

    return a;
}

vt operator *(vt a, vt b) {
    return vt(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

int rev(int x, int st) {
    int y = 0;

    for (int i = 0; i < st; i++) {
        y <<= 1;
        y += x & 1;
        x >>= 1;
    }

    return y;
}

const ld pi = acos(-1.0);

void fft(vector <vt> &a, int st, bool fl) {
    int n = (1 << st);

    for (int i = 0; i < n; i++) {
        int x = rev(i, st);

        if (x < i) {
            swap(a[x], a[i]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        ld ang = 2 * pi / len;

        if (fl) {
            ang = -ang;
        }

        vt wlen = vt(cos(ang), sin(ang));

        for (int i = 0; i < n; i += len) {
            vt w = vt(1, 0);

            for (int j = i; j < i + len / 2; j++) {
                vt x = a[j];
                vt y = a[j + len / 2] * w;

                a[j] = x + y;
                a[j + len / 2] = x - y;
                w = w * wlen;
            }
        }
    }

    if (fl) {
        for (int i = 0; i < n; i++) {
            a[i].x /= n;
            a[i].y /= n;
        }
    }
}

vector<vector<vt> > a;

void mult(int x, int y) {
    int r = 0;
    while ((1 << r) < sz(a[x]) || (1 << r) < sz(a[y])) {
        ++r;
    }
    ++r;
    while (sz(a[x]) < (1 << r)) {
        a[x].pb(vt());
    }
    while (sz(a[y]) < (1 << r)) {
        a[y].pb(vt());
    }
    fft(a[x], r, false);
    fft(a[y], r, false);
    for (int i = 0; i < (1 << r); ++i) {
        a[x][i] = a[x][i] * a[y][i];
    }
    fft(a[x], r, true);
    for (int i = 0; i < (1 << r); ++i) {
        ll z = round(a[x][i].x);
        a[x][i] = {ld(z % mod), 0};
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    /*vector <vt> v;

    for (int i = 0; i < 4; i++) {
        v.push_back(vt(i, 0));
    }

    fft(v, 2, false);
    fft(v, 2, true);

    for (int i = 0; i < 4; i++) {
        cout << v[i].y << ' ';
    }*/

    int n, m, k;
    /*n = 200;
    m = n;
    k = n - 1;*/
    cin >> n >> m >> k;
    vector<int> cnt(m);
    for (int i = 0; i < n; ++i) {
        int x;
        //x = i + 1;
        cin >> x;
        --x;
        ++cnt[x];
    }

    a.resize(m);
    for (int i = 0; i < m; ++i) {
        a[i].pb({1, 0});
        for (int j = 0; j < cnt[i]; ++j) {
            a[i].pb({1, 0});
        }
    }

    set<pii> setik;
    for (int i = 0; i < m; ++i) {
        setik.insert({sz(a[i]), i});
    }

    while (sz(setik) > 1) {
        pii x = *setik.begin();
        //cout << x.first << " " << x.second << endl;
        setik.erase(setik.begin());
        pii y = *setik.begin();
        //cout << y.first << " " << y.second << endl;
        setik.erase(setik.begin());
        mult(x.second, y.second);
        //cout << "D" << endl;
        setik.insert({sz(a[x.second]), x.second});
        //cout << "Q" << endl;
    }

    pii p = *setik.begin();
    //cout << p.first << " " << p.second << " " << k << endl;
    vt ans = a[p.second][k];
    cout << int(round(ans.x)) << "\n";

}