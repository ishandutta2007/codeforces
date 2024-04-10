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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
const int mod = 998244353, N = 100100, logC = 30, K = 450;

struct cell {
    int x, y, c;
    bool operator < (const cell &o) {
        return x < o.x;
    }
} a[N];

int ans, n;

void solve(vector <int> p) {
    // p[0] | p[1] | p[2]
    vector <int> pre(N, 0);
    {
        auto ask = [&](int x) {
            int l = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                l = a[i].x;
                if (a[i].c == p[0]) {
                    cnt++;
                }
                if (cnt == x)
                    break;
            }
            cnt = 0;
            int r = 0;
            for (int i = 0; i < n; ++i) {
                r = a[i].x;
                if (a[i].c == p[1] && l < a[i].x)
                    cnt++;
                if (cnt == x)
                    break;
            }
            if (cnt < x)
                return false;
            cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i].c == p[2] && r < a[i].x) {
                    cnt++;
                }
                if (cnt == x)
                    break;
            }
            return cnt == x;
        };
        int l = 0, r = n / 3 + 1;
        while (r - l > 1) {
            (ask(l + r >> 1) ? l : r) = l + r >> 1;
        }
        ans = max(ans, l);
    }
    {
        auto ask = [&](int x) {
            int l = 0, r = N, cnt = 0;
            for (int i = 0; i < n; ++i) {
                l = a[i].x;
                if (a[i].c == p[0]) {
                    cnt++;
                }
                if (cnt == x)
                    break;
            }
            vector <int> A(N, 0), B(N, 0);
            for (int i = 0; i < n; ++i) {
                if (a[i].c == p[1] && l < a[i].x)
                    A[a[i].y]++;
                if (a[i].c == p[2] && l < a[i].x) 
                    B[a[i].y]++;
            }
            if (accumulate(all(A), 0) < x || accumulate(all(B), 0) < x)
                return false;
            cnt = 0;
            for (int i = 0; i < N; ++i) {
                cnt += A[i];
                l = i;
                if (cnt >= x)
                    break;
            }
            cnt = 0;
            for (int i = N - 1; ~i; --i) {
                cnt += B[i];
                r = i;
                if (cnt >= x)
                    break;
            }
            return l < r;
        };
        int l = 0, r = n / 3 + 1;
        while (r - l > 1) {
            (ask(l + r >> 1) ? l : r) = l + r >> 1;
        }
        ans = max(ans, l);
    }
}

int main () {
    owo;
    cin >> n;
    vector <int> Ax, Ay;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].c, --a[i].c;
        Ax.pb(a[i].x), Ay.pb(a[i].y);
    }
    sort(all(Ax)), sort(all(Ay));
    Ax.resize(unique(all(Ax)) - Ax.begin());
    Ay.resize(unique(all(Ay)) - Ay.begin());
    for (int i = 0; i < n; ++i) {
        a[i].x = lower_bound(all(Ax), a[i].x) - Ax.begin();
        a[i].y = lower_bound(all(Ay), a[i].y) - Ay.begin();
    }
    vector <int> p = {0, 1, 2};
    sort(a, a + n);
    do {
        solve(p);
    } while (next_permutation(all(p)));
    for (int i = 0; i < n; ++i)
        swap(a[i].x, a[i].y);
    sort(a, a + n);
    do {
        solve(p);
    } while (next_permutation(all(p)));
    for (int i = 0; i < n; ++i) 
        swap(a[i].x, a[i].y), a[i].x = Ax.size() - a[i].x - 1, a[i].y = Ay.size() - a[i].y - 1;
    sort(a, a + n);
    do {
        solve(p);
    } while (next_permutation(all(p)));
    for (int i = 0; i < n; ++i)
        swap(a[i].x, a[i].y);
    sort(a, a + n);
    do {
        solve(p);
    } while (next_permutation(all(p)));
    cout << ans * 3 << endl;
}