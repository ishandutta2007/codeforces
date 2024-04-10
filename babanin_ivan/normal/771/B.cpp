#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;


int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<bool> f(n  - k + 1);
    forn (i, n - k + 1) {
        string s;
        cin >> s;
        f[i] = !(s == "YES");
    }
    vector<string> names;
    forn (i, 26 * 26) {
        string name(2, 'a');
        name[0] = 'A' + i / 26;
        name[1] = 'a' + i % 26;
        names.pb(name);
    }
    int p = 0;
    vector<string> ans(n);
    forn (i, k - 1) {
        ans[i] = names[p++];
    }
    for (int i = k - 1, j = 0; i < n; i++, j++) {
        if (f[j]) {
            set<string> was; bool u = false;
            forn (z, k - 1) {
                if (was.count(ans[i - 1 - z])) {
                    u = true;
                    break;
                }
                was.insert(ans[i - 1 - z]);
            }
            if (!u) {
                ans[i] = ans[i + 1 - k];
            }
            else
                ans[i] = names[p++];
        } else {
            ans[i] = names[p++];
        }
    }
    for (auto s: ans)
        cout << s << " ";
    return 0;
}