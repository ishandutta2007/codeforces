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
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef double ld;

class BIT {
public:
    BIT() {};
    BIT(int n) {
        a.resize(n);
    }

    int sum(int l, int r) {
        if (r <= l)
            return 0; 
        return sum(r - 1) - sum(l - 1);
    }

    void update(int pos, int x) {
        for (int i = pos; i < sz(a); i |= (i + 1)) 
            a[i] += x;
    }

private:

    int sum(int pos) {
        int ans = 0;
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
            ans += a[i];
        return ans;
    }

    vector<int> a;
};


int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    vector<int> a(n);
    set<pii> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert({a[i], i});
    }

    BIT bit(n);
    for (int i = 0; i < n; ++i) {
        bit.update(i, 1);
    }


    int pos = -1;

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        pii p = *s.begin();
        pii q = {p.first, pos};
        auto it = s.lower_bound(q);
        pii r;
        if (it == s.end() || p.first < (*it).first) {
            r = p;
        } else {
            r = *it;
        }

        s.erase(r);
        int nxt = r.second;
        // cout << pos << " " << nxt << endl;
        if (pos < nxt) {
            ans += bit.sum(pos, nxt + 1);
        } else {
            ans += bit.sum(pos, n);
            ans += bit.sum(0, nxt + 1);
        }
        // cout << ans << endl;

        bit.update(nxt, -1);
        pos = nxt;
    }
    cout << ans << endl;

}