#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#define double long double
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
//#define int long long
const long long INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 200100, maxT = 100010;
pair<ll, ll>give_a(vector<ll>b) {
    int n = b.size();
    vector<int>used(2 * n + 1);
    for (auto x : b)used[x] = 1;
    set<ll>t;
    for (int i = 1; i <= 2 * n; ++i) {
        if (used[i] == 0)t.insert(i);
    }
    ll min_a = 0;
    for (auto x : b) {
        auto it = t.lower_bound(x);
        if (it != t.end()) {
            min_a++;
            t.erase(it);
        }
    }
    t.clear();
    ll max_a = 0;
    t.clear();
    for (int i = 1; i <= 2 * n; ++i) {
        if (used[i] == 0)t.insert(i);
    }
    reverse(b.begin(), b.end());
    for (auto x : b) {
        auto it = t.lower_bound(x);
        if (it != t.begin()) {
            --it;
            max_a++;
            t.erase(it);
        }
    }
    max_a = n - max_a;
    return { max_a,min_a };
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(11);
#ifdef _MY
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>b(n);
        for (auto& x : b)cin >> x;
        ll min_a, max_a;
        tie(min_a, max_a) = give_a(b);
        cout << max_a - min_a + 1 << "\n";
    }
    return 0;
}