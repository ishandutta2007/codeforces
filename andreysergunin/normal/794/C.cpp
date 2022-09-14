#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s;
    cin >> t;
    int n = sz(s);
    vector<int> a(26), b(26);
    for (int i = 0; i < n; ++i) {
        ++a[s[i] - 'a'];
        ++b[t[i] - 'a'];
    }

    string res;
    for (int i = 0; i < n; ++i) {
        int minn = 26;
        int maxx = 0;
        for (int j = 0; j < 26; ++j) {
            if (a[j] && j < minn)
                minn = j;
            if (b[j] && j > maxx)
                maxx = j;
        }
        if (minn < maxx) {
            if (i & 1) {
                res += (char)(maxx + 'a');
                --b[maxx];
            } else {
                res += (char)(minn + 'a');
                --a[minn];
            }
        }
    }
    s = "";
    t = "";

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < a[i]; ++j)
            s += (char)(i + 'a');
        for (int j = 0; j < b[i]; ++j)
            t += (char)(i + 'a');
    }
    reverse(all(s));

    int cur = (n & 1 ? 0 : 1);
    while (sz(res) < n) {
        if (cur) {
            res.push_back(t.back());
            t.pop_back();
        } else {
            res.push_back(s.back());
            s.pop_back();
        }
        cur ^= 1;
    }

    cout << res << endl;
}