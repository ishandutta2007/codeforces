#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

const int P = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

int binPow(int a, int b) {
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            mul(res, a);
        }
        mul(a, a);
    }
    return res;
}

void solve() {
    int x;
    cin >> x;
    string s;
    cin >> s;
    int n = sz(s);

    // vector<int> pref(n);

    // int r10 = binPow(10, P - 2);

    // pref[0] = 1;
    // for (int i = 0; i < n; ++i) {
    //     pref[i + 1] = pref[i];
    //     mul(pref[i + 1], 10);
    //     add(pref[i + 1], s[i] - '0');
    // }

    // int res = pref[n];
    // int pw = binPow(10, n);

    int len = n;

    for (int i = 1; i <= x; ++i) {
        // mul(pw, r10);
        // int cur = pref[i];
        // mul(cur, pw);

        // int suff = res;
        // sub(suff, cur);

        int cur = len;
        sub(cur, i);

        for (int j = 0; j < s[i - 1] - '1'; ++j) {
            add(len, cur);
            // mul(res, pw);
            // add(res, suff);
        }

        if (sz(s) < x) {
            int k = sz(s);
            for (int j = 0; j < s[i - 1] - '1'; ++j) {
                s += s.substr(i, k - i);
            }    
        }
    }   

    // cout << s << endl;


    cout << len << endl;

}