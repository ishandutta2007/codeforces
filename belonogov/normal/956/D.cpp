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
typedef long double dbl;
const int INF = 1.01e9;
const dbl eps = 1e-11;

bool eq(dbl a, dbl b) {
    return abs(a - b) < eps;
}

struct Fen {
    vector<int> data;
    int n;

    Fen(int sz) {
        n = sz;
        data.resize(n + 1);
    }

    void add(int p, int x) {
        for (; p < n; p |= (p + 1)) {
            data[p + 1] += x;
        }
    }

    int get(int r) {
        int sum = 0;
        for (; r > 0; r &= (r - 1)) {
            sum += data[r];
        }
        return sum;
    }

    int get(int l, int r) {
        return get(r) - get(l);
    }
};


int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK
                   ".in", "r", stdin));
#endif
    int n, w;
    scanf("%d%d", &n, &w);
    struct Flight {
        int x, v;
    };
    vector<Flight> f(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &f[i].x, &f[i].v);
    }
    vector<Flight> pos;
    vector<Flight> neg;
    for (auto A: f) {
        if (A.x < 0) {
            neg.pb(A);
        } else {
            pos.pb(A);
        }
    }
    ll answer = 0;
    auto solve = [&](vector<Flight> who) {
        //vector<pair<dbl, dbl>> t;
        vector<dbl> tt;
        for (auto A: who) {
            dbl x = abs(A.x);
            dbl v = abs(A.v);
            dbl t1 = x / (v + w);
            dbl t2 = x / (v - w);
//            db2(t1, t2);
            tt.pb(t1);
            tt.pb(t2);
        }
        sort(all(tt));
        //dbv(tt);
        //db(eq(tt[0], tt[1]));
        tt.resize(unique(all(tt), eq) - tt.begin());
        //dbv(tt);
        vector<pair<int, int>> event;
        for (auto A: who) {
            dbl x = abs(A.x);
            dbl v = abs(A.v);
            dbl t1 = x / (v + w);
            dbl t2 = x / (v - w);
            int v1 = lower_bound(all(tt), t1 - eps) - tt.begin();
            int v2 = lower_bound(all(tt), t2 - eps) - tt.begin();
            event.pb({v1, v2});
        }
        sort(all(event), [](pair<int, int> A, pair<int, int> B) {
            return A.F > B.F || (A.F == B.F && A.S < B.S);
        });
        Fen fen(tt.size());
        ll res = 0;
//        db(tt.size());
        for (auto E: event) {
//            db(E.S);
            res += fen.get(E.S + 1);
            fen.add(E.S, 1);
        }
        return res;
    };


    auto solve2 = [&](vector<Flight> who1, vector<Flight> who2) {
        //vector<pair<dbl, dbl>> t;
        vector<dbl> tt;
        for (auto A: who1) {
            dbl x = abs(A.x);
            dbl v = abs(A.v);
            dbl t1 = x / (v + w);
            dbl t2 = x / (v - w);
            tt.pb(t1);
            tt.pb(t2);
        }

        for (auto A: who2) {
            dbl x = abs(A.x);
            dbl v = abs(A.v);
            dbl t1 = x / (v + w);
            dbl t2 = x / (v - w);
            tt.pb(t1);
            tt.pb(t2);
        }


        sort(all(tt));
        tt.resize(unique(all(tt), eq) - tt.begin());
        ll res = 0;
        for (int gg = 0; gg < 2; gg++) {
            struct Event {
                int x, type;
            };
            vector<Event> event;
            for (auto A: who1) {
                dbl x = abs(A.x);
                dbl v = abs(A.v);
                dbl t1 = x / (v + w);
                dbl t2 = x / (v - w);
                int v1 = lower_bound(all(tt), t1 - eps) - tt.begin();
                int v2 = lower_bound(all(tt), t2 - eps) - tt.begin();
                assert(v1 <= v2);
                event.pb({v2, 1});
            }

            for (auto A: who2) {
                dbl x = abs(A.x);
                dbl v = abs(A.v);
                dbl t1 = x / (v + w);
                dbl t2 = x / (v - w);
                int v1 = lower_bound(all(tt), t1 - eps) - tt.begin();
                int v2 = lower_bound(all(tt), t2 - eps) - tt.begin();
                assert(v1 <= v2);
                event.pb({v1, 2});
            }

            sort(all(event), [](Event A, Event B) {
                if (A.x != B.x) {
                    return A.x < B.x;
                }
                if (A.type != B.type) {
                    return A.type > B.type;
                }
                return false;
            });
            int cntOne = 0;
            for (auto E: event) {
                if (E.type == 1) cntOne++;
                else res += cntOne;
            }
            swap(who1, who2);
        }

        ll total = who1.size() * 1ll * who2.size();
        db(res);
        assert(res <= total);
        return total - res;
    };


    answer += solve(pos);
//    db(answer);
    answer += solve(neg);
//    db(answer);
    answer += solve2(pos, neg);
//    db(answer);


    cout << answer << endl;


    return 0;
}