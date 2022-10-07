#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

struct pt {
    ll x, y;

    pt() {}

    pt(ll xx, ll yy) : x(xx), y(yy) {}

    pt operator+(pt A) {
        return pt(x + A.x, y + A.y);
    }

    pt operator-(pt A) {
        return pt(x - A.x, y - A.y);
    }

    pt operator*(ll k) {
        return pt(x * k, y * k);
    }

    pt operator/(ll k) {
        assert(x % k == 0 && y % k == 0);
        return pt(x / k, y / k);
    }

    ll operator*(pt A) {
        return x * A.y - y * A.x;
    }

    ll operator%(pt A) {
        return x * A.x + y * A.y;
    }

    bool operator==(pt A) {
        return x == A.x && y == A.y;
    }

    bool operator!=(pt A) {
        return x != A.x && y != A.y;
    }

    pt rotate() {
        return pt(-y, x);
    }

    ll len2() {
        return x * x + y * y;
    }

    dbl len() {
        return sqrt(x * x + y * y);
    }

    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

vector<pt> convexHull(vector<pt> p) {
    sort(all(p), [](pt A, pt B) {
        return A.x < B.x || (A.x == B.x && A.y < B.y);
    });
    vector<pt> st;
    for (int tt = 0; tt < 2; tt++) {
        int cur = st.size();
        for (auto A: p) {
            for (; (int)st.size() >= cur + 2 && (st.back() - st[st.size() - 2]) * (A - st.back()) <= 0; st.pop_back());
            st.pb(A);
        }
        st.pop_back();
        reverse(all(p));
    }
    return st;
}

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK
                   ".in", "r", stdin));
#endif
    int F = 1e3;
    int n, r;
    scanf("%d%d", &n, &r);
    r *= F;
    vector<pt> p(n);
    for (int i = 0; i < n; i++) {
        dbl x, y;
        scanf("%lf%lf", &x, &y);
        p[i] = pt(round(x * F), round(y * F));
    }

    auto ch = convexHull(p);
    int m = ch.size();
    vector<int> nxt(m);
    vector<int> prv(m);
    vector<dbl> val(m);
    for (int i = 0; i < m; i++) {
        nxt[i] = (i + 1) % m;
        prv[i] = (i + m - 1) % m;
    }
    db(m);
    set<pair<dbl,int>> event;
    auto getR = [&](int id) {
//        db3(prv[id], id, nxt[id]);
        pt A = ch[prv[id]];
        pt B = ch[id];
        pt C = ch[nxt[id]];
        if (prv[id] == nxt[id]) {
            assert(prv[id] != id);
            return (A - B).len() / 2;
        }
        pt v = (A - B);
        pt u = (C - B);
        if (v % u > 0) {
            return 0.0;
        }
//        dbl tmpAng = atan2(u * v, v % u);
//        assert(tmpAng > 0);
//        if (tmpAng < acos(-1) / 3) {
//            return 0.0;
//        }
        dbl a = (A - B).len();
        dbl b = (B - C).len();
        dbl c = (A - C).len();
        ///db3(a, b, c);
        dbl pp = (a + b + c) / 2;
        return a * b * c / (4 * sqrt(pp * (pp - a) * (pp - b) * (pp - c)));
    };

    vector<int> alive(ch.size(), 1);
    auto kill = [&](int id) {
        assert(alive[id] == 1);
        alive[id] = 0;
        int v = prv[id];
        int u = nxt[id];
        assert(alive[v] == 1);
        assert(alive[u] == 1);
        event.erase({val[v], v});
        event.erase({val[u], u});
        nxt[v] = u;
        prv[u] = v;
        val[v] = getR(v);
        val[u] = getR(u);
        event.insert({val[v], v});
        event.insert({val[u], u});
    };
    if (m <= 1) {
        puts("0.0");
        return 0;
    }
    if (m > 2) {

        for (int i = 0; i < m; i++) {
            val[i] = getR(i);
            event.insert({val[i], i});
        }
        while (true) {
            while (event.empty());
            assert(!event.empty());
//            for (auto x: event) {
//                db2(x.F, x.S);
//            }
            if (event.rbegin()->F <= r + 1e-9) {
                break;
            }
            auto id = event.rbegin()->S;
//            db(id);
            event.erase(*event.rbegin());
            kill(id);
        }
    }

    int gg = -1;
    for (int i = 0; i < sz(ch); i++) {
        if (alive[i]){
            gg = i;
            break;
        }
    }

    vector<pt> res;
    for (;alive[gg]; gg = nxt[gg]) {
        alive[gg] = 0;
        res.pb(ch[gg]);
    }

//    db(res.size());
//    for (auto A: res) {
//        db2(A.x, A.y);
//    }
    dbl answer = 0;
    for (int i = 0; i < sz(res); i++) {
        answer += res[i] * res[(i + 1) % sz(res)] / 2.0;
    }
//    db(answer / F / F);

    for (int i = 0; i < sz(res); i++) {
        dbl len = (res[i] - res[(i + 1) % sz(res)]).len();
        dbl c = len / 2;
        dbl h = sqrt(max((dbl)0, r * 1.0 * r - c * c));
        dbl ang = asin(min((dbl)1, c / r)) * 2;
        dbl add = ang * r * 1.0 * r / 2 - c * h;
//        db3(len, r, add / F / F);
        answer += add;
    }

    printf("%.17f\n", answer / F / F);





















    return 0;
}