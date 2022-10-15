#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    string s;
    while (cin >> s) {
        vector <int> ans;
        int x = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                x += 1;
            } else
            if (s[i] == ')') {
                x -= 1;
            } else {
                x -= 1;
                ans.push_back(1);
            }
            if (x < 0) {
                cout << "-1" << endl;
                return 0;
            }
        }
        ans[(int)ans.size() - 1] += x;
        x = 0;
        int j = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                x += 1;
            } else
            if (s[i] == ')') {
                x -= 1;
            } else {
                x -= ans[j++];
            }
            if (x < 0) {
                cout << "-1" << endl;
                return 0;
            }
        }
        for (size_t i = 0; i < ans.size(); ++i) {
            cout << ans[i] << "\n";
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}