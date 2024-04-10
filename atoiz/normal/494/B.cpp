#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <random>
#include <chrono>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FO0(i,n) for (int i = 0; i < n; ++i)
#define FOB(i,a,b) for (int i = a; i > b; --i)
#define FOA(i,x) for (auto i : x)
#define SZ(a) ((int)a.size())
#define ALL(a) begin(a),end(a)
#define SORT(a) sort(begin(a), end(a))
#define LB(a,x) (lower_bound(ALL(a), x) - begin(a))
#define UB(a,x) (upper_bound(ALL(a), x) - begin(a))

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;

const int MOD = 1000000007;
const LL INF = 1e18;

const int MAX = 300100;
string s, t, str;
int Z[MAX], f[MAX], g[MAX], h[MAX];

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	str = t + s + "-----";

    // Z
    Z[0] = SZ(str); Z[1] = 0;
    while (str[Z[1]] == str[1 + Z[1]]) ++Z[1];
    int L = 1, R = Z[1];
    for (int i = 2; i < SZ(str); ++i) {
        if (i <= R) Z[i] = min(Z[i-L], R-i+1);
        while (i + Z[i] < SZ(str) && str[Z[i]] == str[i + Z[i]]) ++Z[i];
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    f[SZ(s)] = MAX - 3;
	g[SZ(s)] = h[SZ(s)] = 1;
    for (int i = SZ(s) - 1; i >= 0; --i) {
        if (Z[SZ(t) + i] >= SZ(t)) f[i] = i + SZ(t);
        else f[i] = f[i+1];
        g[i] = (g[i+1] + h[f[i]]) % MOD;
        h[i] = (g[i] + h[i+1]) % MOD;
    }

//    FOR(i,0,SZ(s)) cerr << f[i] << ' '; cerr << endl;
//    FOR(i,0,SZ(s)) cerr << g[i] << ' '; cerr << endl;
//    FOR(i,0,SZ(s)) cerr << h[i] << ' '; cerr << endl;

    cout << (g[0] + MOD - 1) % MOD;
}