#include <iostream>
#include <stdio.h>
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
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ld EPS = 1e-12;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n, m;
    cin >> n;
    ll l, v1, v2;
    cin >> l >> v1 >> v2;

    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll len = (ll)l * v2;

    vector<pair<ll, int>> events;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] * (v1 + v2) - len >= 0) {
            events.push_back({a[i] * (v1 + v2) - len, 1});
            events.push_back({a[i] * (v1 + v2), -1});
        } else {
            cnt += 1;
            events.push_back({(2 * l + a[i]) * (v1 + v2) - len, 1});
            events.push_back({a[i] * (v1 + v2), -1});
        }
    }
    events.push_back({2 * l * (v1 + v2), 0});

    sort(all(events));

    vector<ll> res(n + 1);

    ll tm = 0;
    for (int i = 0; i < sz(events); ++i) {
        // cout << events[i].first << " " << events[i].second << endl;
        if (0 <= cnt && cnt <= n) {
            res[cnt] += events[i].first - tm;
        }
        tm = events[i].first;
        cnt += events[i].second;
    }

    cout.precision(12);
    cout << fixed;
    ll d = 2 * l * (v1 + v2);
    for (int i = 0; i <= n; ++i) {
        cout << (ld)res[i] / d << "\n";
    }
}