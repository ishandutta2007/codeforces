#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
long long fen[MAXN];

void add(int x, long long k) {
    for(; x < MAXN; x |= x + 1)
        fen[x] += k;
}

long long get0(int x) {
    long long res = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1)
        res += fen[x];
    return res;
}

long long get(int l, int r) {
    return get0(r) - (l? get0(l - 1) : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        add(i, 1);
    int l = 0, r = n;
    bool inv = false;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int p;
            cin >> p;
            if(p > r - l - p) {
                p = r - l - p;
                inv = !inv;
            }
            if(inv) {
                for(int i = 0; i < p; i++)
                    add(r - 1 - (2 * p - 1 - i), get(r - 1 - i, r - 1 - i));
                r -= p;
            }
            else {
                for(int i = 0; i < p; i++)
                    add(l + 2 * p - 1 - i, get(l + i, l + i));
                l += p;
            }
        }
        else {
            int ll, rr;
            cin >> ll >> rr;
            if(inv) {
                ll = r - ll;
                rr = r - rr;
                swap(ll, rr);
                rr--;
            }
            else {
                ll += l;
                rr += l;
                rr--;
            }
            cout << get(ll, rr) << '\n';
        }
    }
    return 0;
}