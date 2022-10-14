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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300005, logN = 20, M = 6e6;

struct Pt {
    long long x, y;
    Pt (long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
    long long operator * (const Pt &o) {
        return x * o.x + y * o.y;
    }
    long long operator ^ (const Pt &o) {
        return x * o.y - y * o.x;
    }
    Pt operator + (const Pt &o) {
        return Pt(x + o.x, y + o.y);
    }
    Pt operator - (const Pt &o) {
        return Pt(x - o.x, y - o.y);
    }
    bool pos() {
        return (y == 0 ? x < 0 : y < 0);
    }
    long long dis() {
        return x * x + y * y;
    }
};

void PolarAngleSort(vector <Pt> &pt) {
    sort(pt.begin(), pt.end(), [&](Pt a, Pt b) {
        return (a.pos() == b.pos() ? (a ^ b) > 0 : a.pos() < b.pos());
    });
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <Pt> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    lli ans = 0;
    for (int st = 0; st < n; ++st) {
        vector <Pt> b;
        for (int i = 0; i < n; ++i) if (st ^ i)
            b.pb(a[i] - a[st]);
        PolarAngleSort(b);
        ans += 1ll * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
        for (int i = 0, j = 1; i < n - 1; ++i) {
            while ((b[i] ^ b[j]) > 0)
                j = (j + 1) % (n - 1);
            int cnt = j - i;
            if (cnt <= 0)
                cnt += n - 1;
            ans -= 1ll * (cnt - 1) * (cnt - 2) * (cnt - 3) / 6;
        }
    }
    cout << ans << endl;
}