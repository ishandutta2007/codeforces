#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;


const int MAXN = 100007;
const int MAXM = 19;

int f[MAXN][MAXM];
int lg[MAXN];
map <int, long long> ans;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> f[i][0];
    }

    //n = 10000;
    //for (int i = 0; i < n; ++i) {
        //f[i][0] = rand() % 1000000000 + 1;
    //}
    //f[n][0] = 1;

    lg[1] = 0;
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i >> 1] + 1;
    }

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        int x = 0;
        int next = i;
        while (next < n) {
            x = gcd(f[next][0], x);
            int prev = next;
            for (int k = lg[n]; k >= 0; --k) {
                if (next + (1 << k) <= n && f[next][k] % x == 0) {
                    next += 1 << k;
                }
            }
            ans[x] += next - prev;
        }
    }

    //{
        //map <int, int> res;
        //for (int i = 0; i < n; ++i) {
            //int x = 0;
            //for (int j = i; j < n; ++j) {
                //x = gcd(x, f[j][0]);
                //res[x] += 1;
            //}
        //}
        //for (map <int, int> :: iterator it = res.begin(); it != res.end(); ++it) {
            //if (ans[it->first] != it->second) {
                //cout << it->first << " " << it->second << " " << ans[it->first] << endl;
                //exit(1);
            //}
            //ans.erase(it->first);
        //}
        //if (ans.size()) {
            //cout << "ERROR" << ans.size() << endl;
            //exit(1);
        //}
    //}
    //return 0;

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (ans.count(x)) {
            cout << ans[x] << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}