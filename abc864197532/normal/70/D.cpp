#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 100001, logN = 20, K = 31;

struct Pt {
    lli x, y;
    Pt (lli _x = 0, lli _y = 0) : x(_x), y(_y) {}
    lli operator * (const Pt &o) {
        return x * o.x + y * o.y;
    }
    lli operator ^ (const Pt &o) {
        return x * o.y - y * o.x;
    }
    Pt operator + (const Pt &o) {
        return Pt(x + o.x, y + o.y);
    }
    Pt operator - (const Pt &o) {
        return Pt(x - o.x, y - o.y);
    }
    bool operator == (const Pt &o) const {
        return x == o.x && y == o.y;
    }
};

struct Up_cmp {
    bool operator () (const Pt a, const Pt b) {
        if (a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    }
};

struct Down_cmp {
    bool operator () (const Pt a, const Pt b) {
        if (a.x == b.x)
            return a.y > b.y;
        return a.x > b.x;
    }
};

template <typename T>
struct Hull {
    set <Pt, T> hull;
    bool chk(Pt i, Pt j, Pt k) {
        return ((k - i) ^ (j - i)) > 0;
    }
    void insert(Pt x) {
        if (inside(x))
            return;
        hull.insert(x);
        auto it = hull.lower_bound(x);
        if (next(it) != hull.end()) {
            for (auto it2 = next(it); next(it2) != hull.end(); ++it2) {
                if (chk(x, *it2, *next(it2)))
                    break;
                hull.erase(it2);
                it2 = hull.lower_bound(x);
            }
        }
        it = hull.lower_bound(x);
        if (it != hull.begin()) {
            for (auto it2 = prev(it); it2 != hull.begin(); --it2) {
                if (chk(*prev(it2), *it2, x)) 
                    break;
                hull.erase(it2);
                it2 = hull.lower_bound(x);
                if (it2 == hull.begin())
                    break;
            }
        }
    }
    bool inside(Pt x) {
        if (hull.lower_bound(x) != hull.end() && *hull.lower_bound(x) == x)
            return true;
        auto it = hull.lower_bound(x);
        bool ans = false;
        if (it != hull.begin() && it != hull.end()) {
            ans = !chk(*prev(it), x, *it);
        }
        return ans;
    }
};

Hull <Up_cmp> up;
Hull <Down_cmp> down;

void insert(Pt x) {
    up.insert(x), down.insert(x);
}

bool inside(Pt x) {
    return up.inside(x) && down.inside(x);
}

int main () {
    owo;
    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            insert(Pt(x, y));
        } else {
            cout << (inside(Pt(x, y)) ? "YES\n" : "NO\n");
        }
    }
}