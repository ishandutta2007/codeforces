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

set < vector <int> > s;
vector < pair < char, pair < int, int > > > ans;

void del(int x, int *cnt, map <int, int> &pos, queue <int> &q, int a)
{
    x = a - x;
    if (pos.count(x)) {
        if (--cnt[pos[x]] == 1) {
            q.push(pos[x]);
        }
    }
}

void del(int x, int *cnt, map <int, int> &pos, queue <int> &q, int a, int b)
{
    del(x, cnt, pos, q, a);
    del(x, cnt, pos, q, b);
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n, a, b;
    while (cin >> n >> a >> b) {
        map < int, int > pos;
        int arr[n];
        int ans[n];
        int cnt[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            ans[i] = -1;
            cnt[i] = 0;
            pos[arr[i]] = i;
        }
        queue <int> q;
        for (int i = 0; i < n; ++i) {
            int x;
            x = a - arr[i];
            if (pos.count(x)) {
                cnt[i] += 1;
            }
            if (a != b) {
                x = b - arr[i];
                if (pos.count(x)) {
                    cnt[i] += 1;
                }
            }
            if (cnt[i] == 1) {
                q.push(i);
            }
        }
        while (q.size()) {
            int i = q.front();
            q.pop();
            if (cnt[i] < 1) {
                continue;
            }
            int x;
            x = a - arr[i];
            if (pos.count(x) && cnt[pos[x]] > 0) {
                cnt[i] = cnt[pos[x]] = 0;
                del(arr[i], cnt, pos, q, a, b);
                del(x, cnt, pos, q, a, b);
                ans[i] = ans[pos[x]] = 0;
                continue;
            }

            x = b - arr[i];
            if (pos.count(x) && cnt[pos[x]] > 0) {
                cnt[i] = cnt[pos[x]] = 0;
                del(arr[i], cnt, pos, q, a, b);
                del(x, cnt, pos, q, a, b);
                ans[i] = ans[pos[x]] = 1;
                continue;
            }
        }
        if (*min_element(ans, ans + n) == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                if (i) {
                    cout << " ";
                }
                cout << ans[i];
            }
            cout << endl;
        }
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}