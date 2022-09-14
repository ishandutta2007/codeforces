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

    int n;
    cin >> n;

    vector<int> cnt(40);
    vector<ll> a(n);
    vector<ll> b;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ll tmp = a[i];
        int k = 0;
        while (!(tmp & 1)) {
            tmp /= 2;
            ++k;
        }
        if (tmp == 1) { 
            ++cnt[k];
        } else {
            b.push_back(a[i]);
        }
    }

    vector<ll> c;
    for (int i = 39; i >= 0; --i) {

        int minn = cnt[i];
        for (int j = 0; j < i; ++j) {
            minn = min(minn, cnt[j]);
        }

        for (int j = 0; j < minn; ++j) {
            c.push_back((1ll << (ll)i));
        }
        for (int j = 0; j <= i; ++j)
            cnt[j] -= minn;

        for (int j = 0; j < cnt[i]; ++j) {
            b.push_back((1ll << (ll)i));
        }
        cnt[i] = 0;

    }
    sort(all(b));
    reverse(all(b));

    if (sz(b) > sz(c)) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < sz(b); ++i) {
        if (b[i] > 2 * c[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> res;
    while (sz(c) >= sz(b)) {
        res.push_back(sz(c));
        ll tmp = c.back();
        c.pop_back();
        while (tmp > 0) {
            b.push_back(tmp);
            tmp /= 2;
        }
    }
    reverse(all(res));
    for (int i = 0; i < sz(res); ++i)
        cout << res[i]  << " ";
    cout << endl;


    return 0;

}