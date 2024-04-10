#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 1e5 + 10;
const int INF = 1.01e9;
typedef vector<int> vi;

struct Building {
    ll b, p;
};


//vector<pair<int,int>> t;
//int m;


//void build() {
    //for (int i = m - 1; i > 0; i--) {
        //t[i] = min(t[i * 2], t[i * 2 + 1]);
    //}
//}

//pair<int,int> getMin(int l, int r) {
    //l += m;
    //r += m;
    //pair<int,int> res = {INF, INF};
    //for (; l < r; l /= 2, r /= 2) {
        //if (l & 1) res = min(res, t[l++]);
        //if (r & 1) res = min(res, t[--r]);
    //}
    //return res;
//}

//void modify(int p, pair<int,int> val) {
    //p += m;
    //t[p] = val;
    //for (; p > 1; p /= 2) {
        //t[p / 2] = min(t[p], t[p ^ 1]);
    //}
//}


struct Fen {
    int sz;
    vector<ll> fen;
    void init(int n) {
        sz = n;
        fen.resize(sz + 1);
    }
    void add(int pos, ll val) {
        for (; pos < sz; pos |= (pos + 1)) {
            fen[pos + 1] += val;
        }
    }
    ll get(int r) {
        ll sum = 0;
        for (; r > 0; r &= (r - 1))  {
            sum += fen[r];
        }
        return sum;
    }
    ll get(int l, int r) {
        return get(r) - get(l);
    }
};

struct Node {
    ll x, sum; 
    int id;
    bool operator < (Node other) const {
        return x < other.x;
    }
};


ll fast(vector<ll> a, vector<Building> g) {
    //int n = a.size();
    //int m = g.size();
    vector<pair<ll,ll>> stA;
    for (auto x: a) {
        ll sum = x;
        for (;!stA.empty() && stA.back().F <= x;) {
            sum += stA.back().S;
            stA.pop_back();
        }
        stA.pb({x, sum});
    }
    reverse(all(stA));
    Fen f;
    f.init(sz(stA));

    set<Node> q;
    for (int i = 0; i < sz(stA); i++) {
        q.insert({stA[i].F, stA[i].S, i});
        f.add(i, stA[i].S);
    }


    sort(all(g), [](Building A, Building B) {
                return A.p < B.p;
            });
    //for (auto x: stA) {
        //db2(x.F, x.S);
    //}

    int answer = 0;
    //cerr << endl;
    for (auto x: g) {
        //db2(x.b, x.p);
        int pos = lower_bound(all(stA), make_pair(x.b, -1ll)) - stA.begin();
        //db(pos);
        //db(f.get(pos, sz(stA)));
        if (f.get(pos, sz(stA)) >= x.p) {
            ll cost = x.p;
            answer++; 
            for (;cost > 0;) {
                auto it = q.lower_bound((Node){x.b, -1, -1});     
                assert(it != q.end());
                auto tmp = *it;
                ll X = min(cost, tmp.sum);
                q.erase(it);
                tmp.sum -= X;
                cost -= X;
                f.add(tmp.id, -X);
                //db2(tmp.id, -X);
                if (tmp.sum > 0) {
                    q.insert(tmp);
                }
            }
            assert(cost == 0);
        }
    }
    return answer;
}


ll slow(vector<ll> a, vector<Building> g) {
    int n = a.size();
    int m = g.size();
    vector<vector<int>> dp(n + 1, vector<int> (pw(m)));
    
    dp[0][0] = 1;  
    ll pref = 0;
    for (int i = 0; i < n; i++) {
        pref += a[i];
        for (int mask = 0; mask < pw(m); mask++) {
            if (dp[i][mask] == 0) continue;
            for (int mask2 = 0; mask2 < pw(m); mask2++) {
                if (mask & mask2) continue;
                ll newMask = mask | mask2;
                ll sum = 0;
                bool ok = 1;
                for (int j = 0; j < m; j++) {
                    if (newMask & pw(j)) {
                        sum += g[j].p;
                    }  
                    if (mask2 & pw(j)) {
                        ok &= g[j].b <= a[i];
                    }
                }

                if (sum <= pref && ok) {
                    dp[i + 1][newMask] = 1;
                }
            }
        }
    }
    int answer = 0;
    for (int mask = 0; mask < pw(m); mask++) {
        if (dp[n][mask]) {
            answer = max(answer, __builtin_popcount(mask));
        }
    }
    return answer;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    if (1) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        vector<Building> g(m);
        for (int i = 0; i < m; i++) {
            scanf("%lld", &g[i].b);
        }
        for (int i = 0; i < m; i++) {
            scanf("%lld", &g[i].p);
        }
        cout << fast(a, g) << endl;
        //cout << slow(a, g) << endl;
    }
    else {
        for (int tt = 0; ; tt++) {
            db(tt);
            int C = 8;
            int n = rand() % C + 1;
            int m = rand() % C + 1;
            vector<ll> a(n);
            for (int i = 0; i < n; i++) {
                a[i] = rand() % C + 1;
            }
            vector<Building> g(m);
            for (int i = 0; i < m; i++) {
                g[i] = {rand() % C + 1, rand() % C + 1};
            }
            auto r1 = fast(a, g);
            auto r2 = slow(a, g);
            cerr << n << " " << m << endl;
            for (int i = 0; i < n; i++)
                cerr << a[i] << " ";
            cerr << endl;
            for (int i = 0; i < m; i++) {
                cerr << g[i].b << " ";
            }
            cerr << endl;
            for (int i = 0; i < m; i++) {
                cerr << g[i].p << " ";
            }
            cerr << endl;
            db2(r1, r2);
            assert(r1 == r2);
        }

    }
   
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}