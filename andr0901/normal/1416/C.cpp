//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

/*
int ans = 0;

long long solve(int bit, vector <int> a) {
    if (bit == -1 || a.empty())
        return 0;
    cerr << a << "\n";
    int n = sz(a);
    vector <int> b0(n), b1(n);
    forn (i, 0, n) {
        b0[i] = ((a[i] >> bit) & 1);
        b1[i] = (1 - b1[i]);
    }
    long long inv0 = 0, inv1 = 0;
    int cnt0 = 0, cnt1 = 0;
    forn (i, 0, n) {
        cnt0 += (b0[i] == 1);
        cnt1 += (b1[i] == 1);
        if (b0[i] == 0)
            inv0 += cnt0;
        if (b1[i] == 0)
            inv1 += cnt1;
    }
    vector <int> zero, one;
    if (inv1 < inv0) {
        forn (i, 0, n) {
            if (b1[i] == 0)
                zero.pb(a[i]);
            else
                one.pb(a[i]);
        }
        ans |= (1 << bit);
        return inv1 + solve(bit - 1, zero) + solve(bit - 1, one);
    } else {
        forn (i, 0, n) {
            if (b0[i] == 0)
                zero.pb(a[i]);
            else
                one.pb(a[i]);
        }
        return inv0 + solve(bit - 1, zero) + solve(bit - 1, one);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    cout << solve(30, a) << " " << ans;
    return 0;
}*/

template <typename T>
class Segtree {
private:
    int n;
    vector <T> tr;
    T neutral_tr = 0;

    T merge(T a, T b) {
        return a + b;
    }

    template <typename U>
    void build(const vector <U>& a) {
        forn (i, 0, n) 
            tr[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    template <typename U>
    Segtree(const vector <U>& a) : n(sz(a)) {
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    Segtree(int _n) : n(_n) {
        tr.resize(2 * n, neutral_tr);
    }

    T get(int l, int r) {
        T ans = neutral_tr;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                ans = merge(ans, tr[l++]);
            if (r % 2)
                ans = merge(ans, tr[--r]);
        }
        return ans;
    }
    
    void upd(int i, int x) {
        for (i += n, tr[i] += x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

long long count(vector <int>& x) {
    auto sorted = x;
    sort(all(sorted)), sorted.erase(unique(all(sorted)), sorted.end());
    map <int, int> get;
    forn (i, 0, sz(sorted))
        get[sorted[i]] = i;
    forn (i, 0, sz(x))
        x[i] = get[x[i]];
    long long ans = 0;
    Segtree <int> tr(sz(x));
    forn (i, 0, sz(x)) {
        ans += tr.get(x[i] + 1, sz(x));
        tr.upd(x[i], 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <vector <int>> c;
    vector <int> tmp(n);
    iota(all(tmp), 0);
    c.pb(tmp);
    int x = 0;
    for (int bit = 30; bit >= 0; --bit) {
        vector <int> b0(n), b1(n);
        forn (i, 0, n) {
            b0[i] = ((a[i] >> bit) & 1);
            b1[i] = (1 - b0[i]);
        }
        cerr << b0 << "\n" << b1 << "\n\n";
        long long inv0 = 0, inv1 = 0;
        for (auto& v : c) {
            int cnt0 = 0, cnt1 = 0;
            for (int i : v) {
                cnt0 += (b0[i] == 1);
                cnt1 += (b1[i] == 1);
                if (b0[i] == 0)
                    inv0 += cnt0;
                if (b1[i] == 0)
                    inv1 += cnt1;
            }
        }
        vector <vector <int>> new_c;
        if (inv1 < inv0) {
            x |= (1 << bit);
            for (auto& v : c) {
                vector <int> zero, one;
                for (int i : v) {
                    if (b1[i] == 0)
                        zero.pb(i);
                    else
                        one.pb(i);
                }
                if (!zero.empty())
                    new_c.pb(zero);
                if (!one.empty())
                    new_c.pb(one);
            }
        } else {
            for (auto& v : c) {
                vector <int> zero, one;
                for (int i : v) {
                    if (b0[i] == 0)
                        zero.pb(i);
                    else
                        one.pb(i);
                }
                if (!zero.empty())
                    new_c.pb(zero);
                if (!one.empty())
                    new_c.pb(one);
            }
        }
        c = new_c;
        if (bit < 3) {
            cerr << bit << " " << inv0 << " " << inv1 << " " << c.size() << "\n";
            for (auto v : c)
                cerr << v << "\n";
            cerr << "\n--\n";
        }
    }
    vector <int> b(n);
    forn (i, 0, n)
        b[i] = (a[i] ^ x);
    cerr << b << "\n";
    cout << count(b) << " " << x;
    return 0;
}