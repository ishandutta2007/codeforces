#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<int> k(m);
    for (int i = 0; i < m; ++i) {
        cin >> k[i];
    }
    vector<int> l(m);
    int cnt = 0;

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cnt += (k[i] == 0);
        sum += k[i];
    }

    int rg = 0;
    int ans = n + 1;

    for (int lf = 0; lf < n; ++lf) {
        while (rg < n && cnt < m) {
            ++l[a[rg]];
            if (l[a[rg]] == k[a[rg]]) {
                ++cnt;
            }
            ++rg;
        }
        if (cnt == m) {
            ans = min(ans, rg - lf - sum);
        }
        if (l[a[lf]] == k[a[lf]]) {
            --cnt;
        }
        --l[a[lf]];
    }

    cout << (ans == n + 1 ? -1 : ans) << endl;

}