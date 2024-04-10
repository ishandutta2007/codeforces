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

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll rev(ll a, ll m) {
    if (a == 0) return 0;
    return (((1 - rev(m % a, a) * m) / a) + m) % m;
}

int MOD;
vector<int> a;

void read() {
    int n;
    scanf("%d%d", &MOD, &n);
    a.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}


pair<int,int> f(vector<int> c) {
    assert((int)c.size() < MOD);
    sort(all(c));
    int n = c.size();
    if (c.size() == 0) return mp(0, 1);
    if (c.size() == 1) {
        return mp(c[0], 1);
    }
    srand(19);  
    int v = rand() % c.size();
    int u = rand() % c.size();
    if (v == u)
        v = (v + 1) % c.size();
    int diff = (c[v] - c[u]);

    //set<int> cand;
    for (int t = 0; t < 2; t++) {
        int z = (diff + MOD) % MOD;
        for (int len = 1; len < n; len++) {
            //if (len % 1000 == 0)
                //db(len);
            ll rlen = rev(len, MOD);   
            int d = z * rlen % MOD;
            //if (cand.count(d) == 0) {
            int left = 0; 
            int right = 0;
            for (;;left++) {
                assert(left <= n);
                int x = (c[v] - (left + 1) * 1ll * d % MOD + MOD) % MOD;
                //if (find(all(c), x) == c.end())
                auto it = lower_bound(all(c), x);
                if (it == c.end() || *it != x)
                    break;
            }
            for (;; right++) {
                assert(right <= n);
                int x = (c[v] + (right + 1) * 1ll * d % MOD + MOD) % MOD;
                //if (find(all(c), x) == c.end())
                auto it = lower_bound(all(c), x);
                if (it == c.end() || *it != x)
                    break;
            }
            //db2(left, right);
            assert(left + right + 1 <= n);
            if (left + right + 1 == n) {
                return mp((c[v] - left * 1ll * d % MOD + MOD) % MOD, d);
            }
                //cand.insert(d);
            //}
        }
        diff *= -1;
    }
    //db(cand.size());
    return mp(-1, -1);
}

void printAns(pair<int,int> res) {
    assert(res.S != 0);
    if (res.S != -1) {
        sort(all(a));
        for (int i = 0; i < (int)a.size(); i++) {
            ll x = (res.F + i * 1ll * res.S) % MOD;
            auto it = lower_bound(all(a), x);
            assert(it != a.end() && *it == x);
            //if (it == c.end() || *it != x)
            //assert(find(all(a), x) != a.end());
        }
        //db("OK");

        printf("%d %d\n", res.F, res.S);
    }
    else {
        puts("-1");
    }
}

void solve() {
    int n = a.size();
    if (n * 2 > MOD) {
        vector<bool> use(MOD);
        for (auto x: a)
            use[x] = 1;
        vector<int> b;
        for (int i = 0; i < MOD; i++)
            if (!use[i])
                b.pb(i);
        auto res = f(b);
        if (res.F != -1)
            res.F = (res.F + b.size() * 1ll * res.S) % MOD;
        printAns(res);
        //db("DOP");
        //if (res.F == -1) {
            //puts("-1");
        //}
        //else {
            //printf("%d %d\n", res.F, res.S);
        //}
    }
    else {
        printAns(f(a));
    }


}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
    freopen("test.txt", "r", stdin);
#endif
    if (1) {
        read();
        solve();
        cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    }
    else {
        stress();
    }

    return 0;
}