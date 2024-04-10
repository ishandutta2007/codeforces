#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int MAXN = 8009;
const int MAXX = (int)1e+6 + 7;

struct triple {
    int x, l, r;
    triple(int x = 0, int l = 0, int r = 0) : 
        x(x), l(l), r(r)
    { }
};

int s[MAXN];
vector <triple> v[MAXN];

int lg[MAXX];
int upd[MAXX], cnt;
int n, m;

int cpwr[MAXX];

int count_power(int l, int r)
{
    return lg[r] - lg[l - 1];
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    lg[0] = -1;
    lg[1] = 0;
    for (int i = 2; i < MAXX; ++i) {
        lg[i] = lg[i >> 1] + 1;
    }
    
    cin >> n >> m;
    s[1] = 1;
    for (int i = 2; i <= n; ++i) {
        s[i] = s[i - 1] + lg[s[i - 1]] + 1;
    }
    
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> t >> l >> r >> x;
            v[t].push_back(triple(x, l, r));
        } else {
            int l, r, ans = 0;
            cin >> t >> l;
            //cout << t << " " << l << endl;
            r = l;
            ++cnt;
            for (; t <= n; ++t) {
                //cout << " " << t << " " << l << " " << r << endl;
                for (size_t i = 0; i < v[t].size(); ++i) {
                    if (l <= v[t][i].r && v[t][i].l <= r && upd[v[t][i].x] != cnt) {
                        upd[v[t][i].x] = cnt;
                        ++ans;
                    }
                }
                int len = r - l + 1;
                int k = count_power(l, r);
                l += count_power(1, l - 1);
                r = l + len - 1 + k;
            }
            cout << ans << "\n";
        }
    }
    
	return 0;
}