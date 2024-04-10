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
typedef pair<int, int> pii;
typedef double ld;
typedef unsigned int uint;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    vector<string> t(n);
    vector<vector<int>> p(n);
    int len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        int k;
        cin >> k;
        p[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> p[i][j];
            --p[i][j];
            len = max(len, p[i][j] + sz(t[i]));
        }
    }

    vector<int> f(len);
    vector<int> id(len);
    for (int i = 0; i < n; ++i) {
        for (int pos : p[i]) {
            if (f[pos] < sz(t[i])) {
                f[pos] = sz(t[i]);
                id[pos] = i;
            }
        }
    }

    string s = "";
    for (int i = 0; i < len; ++i)
        s += 'a';

    int k = -1;
    for (int i = 0; i < len; ++i) {
        if (f[i] && (k == -1 || i + f[i] > k + f[k])) {
            k = i;
        }
        if (k != -1 && k + f[k] > i) {
            s[i] = t[id[k]][i - k];
        }
    }
    cout << s << endl;

}