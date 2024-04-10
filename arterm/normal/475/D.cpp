#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define M 100100

int t[4 * M], a[M], b[M], n;
map<int, long long> ans;

inline int gcd(int x, int y) {
    while (x) {
        y %= x;
        swap(x, y);
    }
    return x + y;
}

void upd(int v, int l, int r, int pos) {
    if (r - l == 1) {
        t[v] = b[pos];
        return;
    }
    int m = (l + r) >> 1;
    if (pos < m)
        upd(v << 1, l, m, pos);
    else
        upd((v << 1) | 1, m, r, pos);
    t[v] = gcd(t[v << 1], t[(v << 1) | 1]);
    //cerr << v << "->" << t[v] << "\n";
}

int get(int v, int l, int r, int val) {
    if (t[v] % val == 0) {
        //cout << "I'm from " << l << " to " << r << " and gcd here is " << t[v] << ".\n";
        return r;
    }
    if (r - l == 1)
        return l;
    int m = (l + r) >> 1;
    if (t[v << 1] % val == 0)
        return get((v << 1) | 1, m, r, val);
    return get(v << 1, l, m, val);
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void kill() {
    for (int i = n - 1; i >= 0; --i) {
        b[i] = a[i];
        upd(1, 0, n, i);
        int g = b[i], r = i, prev = i;
        while (r < n) {
            r = get(1, 0, n, g);
            ans[g] += (r - prev);
            //cout << "from " << prev << " to " << r << " gcd is " << g << "\n";
            prev = r;
            g = gcd(g, b[r]);
        }
    }
}

void print() {
    int q;
    cin >> q;
    for (int i = 0, x; i < q; ++i) {
        cin >> x;
        cout << ans[x] << "\n";
    }
}

int main() {
#ifdef TURTLE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    read();
    kill();
    print();

    return 0;
}