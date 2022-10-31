#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

class Segtree {
private:
    int n;
    vector <pii> tr;
    pii neutral_tr = {1e9, 0};

    pii merge(pii a, pii b) {
        return min(a, b);
    }

    void build(const vector <int>& a) {
        forn (i, 0, n) 
            tr[i + n] = {a[i], i};
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    Segtree(const vector <int>& a) {
        n = sz(a);
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    pii get(int l, int r) {
        pii ans = neutral_tr;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                ans = merge(ans, tr[l++]);
            if (r % 2)
                ans = merge(ans, tr[--r]);
        }
        return ans;
    }
    
    void upd(int i, int x) {
        for (i += n, tr[i].fs = x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 1, 1);
    a[0] = a[1] = 1e9;
    Segtree tr(a);
    int ans = 1;
    forn (i, 2, n + 1) {
        int k = tr.get(0, n + 1).sc;
        cout << a[k] << " ";
        a[k] = 1e9;
        tr.upd(k, a[k]);
        for (int j = 2 * k; j < n + 1; j += k) {
            if (k > a[j]) {
                a[j] = k;
                tr.upd(j, a[j]);
            }
        }
    }
    return 0;
}