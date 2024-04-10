#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ld EPS = 1e-8;
const int M = 1e2 + 12;
const int MAX = 1e3 + 1;
const int N = (1<<17) + 1;

int t[4][11][2 * N][10];

string s;

int f(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'G') return 2;
    if (c == 'C') return 3;

}

void upd(int ch, int len, int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[ch][len][v][tl % len] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        upd(ch, len, 2 * v, tl, tm, pos, val);
    else
        upd(ch, len, 2 * v + 1, tm + 1, tr, pos, val);

    t[ch][len][v][pos % len] = t[ch][len][2 * v][pos % len] + t[ch][len][2 * v + 1][pos % len];
}

int get(int ch, int len, int ost, int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) return 0;
    if (l <= tl && tr <= r) return t[ch][len][v][ost];
    int tm = (tl + tr) / 2;
    return get(ch, len, ost, 2 * v, tl, tm, l, r) +
        get(ch, len, ost, 2 * v + 1, tm + 1, tr, l, r);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    //frab(i, 1, 11)
    //    build(i, 1, 0, n - 1);
    fr(i, n)
        frab(len, 1, 11)
            upd(f(s[i]), len, 1, 0, n - 1, i, 1);
    fr(i1, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            cin >> pos;
            pos--;
            char ch;
            cin >> ch;
            char was = s[pos];
            s[pos] = ch;
            int c = f(ch);
            int c2 = f(was);
            frab(len, 1, 11)
                upd(c, len, 1, 0, n - 1, pos, 1);
            frab(len, 1, 11)
                upd(c2, len, 1, 0, n - 1, pos, -1);
        }
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            string t;
            cin >> t;
            int ans = 0;
            int len = t.size();
            fr(i, len)
                ans += get(f(t[i]), len, (i + l - 1) % len, 1, 0, n - 1, l - 1, r - 1);
            cout << ans << endl;
        }
    }




}