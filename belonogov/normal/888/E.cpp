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
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;

int mod;

vector<int> build(vector<int> a, int l, int r) {
    int n = r - l;
    vector<int> res;
    for (int mask = 0; mask < pw(n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & pw(i)) {
                sum += a[i + l];
            }
        }
        res.pb(sum % mod);
    }
    sort(all(res));
    res.resize(unique(all(res)) - res.begin());
    return res;
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d%d", &n, &mod);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    auto r1 = build(a, 0, n / 2);
    auto r2 = build(a, n / 2, n);
    //dbv(r1);
    //dbv(r2);
    int answer = 0;
    for (auto x: r1) {
        int id = lower_bound(all(r2), mod - x) - r2.begin(); 
        //db2(x, id);
        for (int t = -1; t <= 1; t++) {
            int h = (t + id + r2.size() * 2) % r2.size();
            int sum = (x + r2[h]) % mod;
            answer = max(sum, answer);
        }
    }
    cout << answer << endl;


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}