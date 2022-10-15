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

bool rec(vector <int> &a)
{
    if (a.size() == 1) {
        return a[0] == 24;
    }
    if (s.find(a) != s.end()) {
        return false;
    }
    s.insert(a);
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = i + 1; j < a.size(); ++j) {
            vector <int> b = a;
            int x = a[i], y = a[j];
            b.erase(b.begin() + j);
            b.erase(b.begin() + i);

            b.push_back(x + y);
            ans.push_back(make_pair('+', make_pair(x, y)));
            if (rec(b)) {
                return true;
            }
            b.pop_back();
            ans.pop_back();

            b.push_back(y - x);
            ans.push_back(make_pair('-', make_pair(y, x)));
            if (rec(b)) {
                return true;
            }
            b.pop_back();
            ans.pop_back();

            b.push_back(x - y);
            ans.push_back(make_pair('-', make_pair(x, y)));
            if (rec(b)) {
                return true;
            }
            b.pop_back();
            ans.pop_back();

            b.push_back(x * y);
            ans.push_back(make_pair('*', make_pair(x, y)));
            if (rec(b)) {
                return true;
            }
            b.pop_back();
            ans.pop_back();
        }
    }
    return false;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n;
    cin >> n;
    if (n < 4) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector <int> a;
    for (int i = 1; i <= n % 2 + 4; ++i) {
        a.push_back(i);
    }
    rec(a);
    for (int i = n % 2 + 4; i < n; i += 2) {
        ans.push_back(make_pair('-', make_pair(i + 2, i + 1)));
        ans.push_back(make_pair('*', make_pair(24, 1)));
    }
    for (size_t i = 0; i < ans.size(); ++i) {
        int x = ans[i].second.first;
        int y = ans[i].second.second;
        int r = -1;
        switch (ans[i].first) {
            case '-': r = x - y; break;
            case '+': r = x + y; break;
            case '*': r = x * y; break;
        }
        cout << x << " " << ans[i].first << " " << y << " = " << r << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}