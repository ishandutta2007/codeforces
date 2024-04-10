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

vector < vector <int> > a;
vector < vector <int> > ans;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    a.push_back(vector <int> ());

    int n, k;
    cin >> n >> k;

    for (int i = 1; (int)ans.size() < n; ++i) {
        for (int j = (int)a.size() - 1; j >= 0; --j) {
            bool ok = true;
            for (size_t k = 0; k < a[j].size() && ok; ++k) {
                ok = gcd(a[j][k], i) == 1;
            }
            if (ok) {
                a.push_back(a[j]);
                a.rbegin()->push_back(i);
                if (a.rbegin()->size() == 4) {
                    ans.push_back(*a.rbegin());
                    set <int> s(a.rbegin()->begin(), a.rbegin()->end());
                    a.clear();
                    a.push_back(vector <int>());
                    break;
                }
            }
        }
    }

    cout << *(ans.rbegin()->rbegin()) * k << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            if (j) {
                cout << " ";
            }
            cout << ans[i][j] * k;
        }
        cout << "\n";
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}