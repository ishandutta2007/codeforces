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
mt19937 rr(random_device{}());

const int P = 1e9 + 7;

int main() {
    // freopen("input.txt", "r", stdin)p;
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    int n = sz(s);
    int m = sz(t);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    int l = 0, r = n;
    while (r - l > 1) {
        string s1;
        int mid = (l + r) / 2;
        vector<bool> used(n, true);
        for (int i = 0; i < mid; ++i) 
            used[p[i]] = false;
        for (int i = 0; i < n; ++i) {
            if (used[i])
                s1 += s[i];
        }
        int cur = 0;
        for (int i = 0; i < sz(s1) && cur < m; ++i) {
            if (s1[i] == t[cur])
                ++cur;
        }
        if (cur == m) 
            l = mid;
        else 
            r = mid;
    }
    cout << l << endl;

}