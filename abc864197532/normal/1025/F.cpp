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
const int mod = 1e9 + 7, N = 2e5 + 101, logN = 18;

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

bool btw(Pt a, Pt b, Pt c) {
    // c in segment ab?
    return ((a - b) ^ (a - c)) == 0 && ((c - a) * (c - b)) <= 0;
}

long long area(Pt a, Pt b, Pt c) {
    return abs((a - b) ^ (a - c));
}

double dis(Pt a, Pt b, Pt c) {
    return double(area(a, b, c)) / sqrt((b - c).dis());
}

lli RotatingSweepLine(vector <Pt> &pt) {
    int n = pt.size();
    vector <int> id(n), pos(n);
    vector <pair <int, int>> line;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i ^ j)
        line.emplace_back(i, j);
    sort(line.begin(), line.end(), [&](pair <int, int> i, pair <int, int> j) {
        Pt a = pt[i.second] - pt[i.first], b = pt[j.second] - pt[j.first];
        return (a.pos() == b.pos() ? (a ^ b) > 0 : a.pos() < b.pos());
    });
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
        return (pt[i].y == pt[j].y ? pt[i].x < pt[j].x : pt[i].y < pt[j].y);
    });
    for (int i = 0; i < n; ++i)
        pos[id[i]] = i;
    lli ans = 0;
    for (auto [i, j] : line) {
        // point sort by the distance to line(i, j)
        int l = min(pos[i], pos[j]), r = n - l - 2;
        ans += 1ll * l * (l - 1) / 2 * r * (r - 1) / 2;
        tie(pos[i], pos[j], id[pos[i]], id[pos[j]]) = make_tuple(pos[j], pos[i], j, i);
    }
    return ans / 2;
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <Pt> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    cout << RotatingSweepLine(a) << '\n';
}