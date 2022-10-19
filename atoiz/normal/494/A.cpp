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

void kill() { cout << -1; exit(0); }

VI ans;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    ans.reserve(SZ(str));

    int last = SZ(str) - 1;
    while (str[last] != '#') --last;

    int su_l = 0;
    for (int i = 0; i < last; ++i) {
        if (str[i] == '(') ++su_l;
		else if (str[i] == ')') --su_l;
		else if (str[i] == '#') {
			--su_l;
			ans.pb(1);
		}

		if (su_l < 0) kill();
    }

	int su_r = 0, min_r = 0;
    for (int i = last + 1; i < SZ(str); ++i) {
        if (str[i] == '(') ++su_r;
        else --su_r;
        min_r = min(su_r, min_r);
    }
    if (min_r < su_r) kill();

    int tmp = su_l + su_r;
    if (tmp < 1) kill();
    ans.pb(tmp);

    for (int x : ans) cout << x << '\n';
}