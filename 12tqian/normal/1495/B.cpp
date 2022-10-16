#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi a(n);
    f0r(i, n) cin >> a[i];
    vpi runs;
    int len = 0;
    int dir = -1;
    f0r(i, n) {
        if (len == 0) {
            len++;
        } else {
            if (a[i] > a[i - 1]) {
                if (dir == -1) {
                    len++;
                    dir = 1;
                } else if (dir) {
                    len++;
                } else {
                    runs.eb(len, dir);
                    len = 2;
                    dir = 1;
                }
            } else {
                if (dir == -1) {
                    len++;
                    dir = 0;
                } else if (dir) { 
                    runs.eb(len, dir);
                    len = 2;
                    dir = 0;
                } else {
                    len++;
                }  
            }
        }
    }
    runs.eb(len, dir);
    int mx = 0;
    each(x, runs) ckmax(mx, x.f);
    vi loc;
    f0r(i, sz(runs)) {
        if (runs[i].f == mx) {
            loc.pb(i);
        }
    }
    if (sz(loc) == 1) {
        cout << 0 << '\n';
    } else if (sz(loc) == 2) {
        if (loc[1] - loc[0] > 1) {
            cout << 0 << '\n';
        } else {
            int i1 = loc[0];
            int i2 = loc[1];
            if (runs[i1].s == 0) {
                cout << 0 << '\n';
            } else {
                if (mx % 2 == 1) {
                    cout << 1 << '\n';
                } else {
                    cout << 0 << '\n';
                }
            }
        }
    } else {
        cout << 0 << '\n';
    }
    return 0;
}

/**
 * YOU GO DOWN
 * THEY GO UP
 * let's say you're not on a peak/valley, you can only go one direction
 * you auto lose, they block you off
 * let's say you're on a valley, you lose cause you can't go anywhere
 * so you can only possibly win on a peak, when you have two directions
 * consider some peak 
 * if there's some other other length that's just longer than your two lengths of equal to, you're done
 * otherwise, you have the very longest, they have to try to block you off there, otherwise insta lose
 * let's say these two things are unequal
 * if the length of longer one is even, insta lose
 * now say it's odd, also insta lose
 * so they have to be equal 
 * now we're done
 * they are equal
 * 
 */