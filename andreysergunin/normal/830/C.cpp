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

const ll INF = 2e11;
const int LIM = 1e5;

int n;
ll k;
vector<int> a;
ll ans = 1;
ll sum = 0;


bool check(int d) {
    ll x = 0;
    for (int i = 0; i < n; ++i)
        x += (a[i] - 1) / d + 1;
    x *= d;
    if (x <= sum + k)
        return true;
    return false;
} 


struct Event {
    int t;
    int id;
    int a;
};

bool operator < (const Event &a, const Event &b) {
    if (a.t != b.t)
        return a.t < b.t;
    if (a.a != b.a)
        return a.a < b.a;
    return a.id < b.id;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 1; i <= LIM; ++i) {
        if (check(i)) {
            ans = max(ans, (ll)i);
        }
    }

    vector<Event> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= a[i] / LIM + 1; ++j) {
            int t = (a[i] - 1) / j + 1;
            q.push_back({t, i, j});
        }
    }

    sort(all(q));

    vector<ll> x(n, INF);

    ll s = n * INF;

    for (int i = 0; i < sz(q); ) {
        int j = i;
        while (i < sz(q) && q[i].t == q[j].t) {
            s -= x[q[i].id];
            x[q[i].id] = q[i].a;
            s += x[q[i].id];
            ++i;
        }


        ll d = (sum + k) / s;
        ll l = q[j].t;
        ll r = (i == sz(q) ? INF : q[i].t);

        if (l <= d) {
            if (r < d)
                d = r;
            ans = max(ans, d);
        }
    }

    cout << ans << endl;

}