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
const int mod = 998244353, N = 2e6 + 5, logN = 20, M = 6e6;

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

vector <Pt> ConvexHull(vector <Pt> pt) {
    int n = pt.size();
    sort(pt.begin(), pt.end(), [&](Pt a, Pt b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    auto check = [&](Pt a, Pt b, Pt c) {
        return ((a - b) ^ (a - c)) <= 0;
    };
    vector <Pt> ans = {pt[0]};
    for (int t : {0, 1}) {
        int m = ans.size();
        for (int i = 1; i < n; ++i) {
            while (ans.size() > m && check(ans[ans.size() - 2], ans.back(), pt[i])) {
                ans.pop_back();
            }
            ans.push_back(pt[i]);
        }
        reverse(pt.begin(), pt.end());
    }
    ans.pop_back();
    return ans;
}

#define state array <lli, 4>

vector <int> build_fail(vector <state> &s) {  
    vector <int> f(s.size() + 1, 0);
    int k = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (k && s[k] != s[i]) 
            k = f[k];
        if (s[k] == s[i]) 
            k++;
        f[i + 1] = k;
    }
    return f;
}

int match(vector <state> &s, vector <state> &t) {
    vector <int> f = build_fail(t);
    int k = 0, ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        while (k && s[i] != t[k]) 
            k = f[k];
        if (s[i] == t[k]) 
            k++;
        if (k == t.size()) 
            ans++, k = f[k];
    }
    return ans;
}

void PolarAngleSort(vector <Pt> &pt) {
    sort(pt.begin(), pt.end(), [&](Pt a, Pt b) {
        return (a.pos() == b.pos() ? (a ^ b) > 0 : a.pos() < b.pos());
    });
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <Pt> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    for (int i = 0; i < m; ++i)
        cin >> b[i].x >> b[i].y;
    a = ConvexHull(a), b = ConvexHull(b);
    if (a.size() != b.size()) {
        cout << "NO\n";
        return 0;
    }
    n = a.size();
    if (n == 2) {
        cout << ((a[0] - a[1]).dis() == (b[0] - b[1]).dis() ? "YES\n" : "NO\n");
        return 0;
    }
    vector <state> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n, k = (i + 2) % n;
        Pt vec1 = a[j] - a[i], vec2 = a[k] - a[j];
        A[i] = {vec1 * vec2, vec1 ^ vec2, vec1.dis(), vec2.dis()};
    }
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n, k = (i + 2) % n;
        Pt vec1 = b[j] - b[i], vec2 = b[k] - b[j];
        B[i] = {vec1 * vec2, vec1 ^ vec2, vec1.dis(), vec2.dis()};
    }
    for (int i = 0; i < n; ++i)
        A.pb(A[i]);
    if (match(A, B)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}