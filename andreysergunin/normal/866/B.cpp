// MIPT Shock Content
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
typedef double ld;

mt19937 rr(random_device{}());

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<int> a(n), b(n);
    vector<ll> s(n);
    vector<pair<int, ll>> x, y;
    ll sum = 0;
    ll sumx = 0, sumy = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> a[i] >> b[i];
        ans += s[i] * min(a[i], b[i]);
        sum += s[i];
        if (a[i] > b[i]) {
            x.push_back({a[i] - b[i], s[i]});
            sumx += s[i];
        } 
        if (a[i] < b[i]) {
            y.push_back({b[i] - a[i], s[i]});
            sumy += s[i];
        }
    }
    ll cnt = (sum + m - 1) / m;
    sort(all(x));
    reverse(all(x));

    sort(all(y));
    reverse(all(y));

    ll ansx = ans;
    ll u, v;
    u = (sumx + m - 1) / m;
    v = cnt - u;
    u *= m;
    v *= m;
    for (int i = 0; i < sz(x); ++i) {
        ansx += min(x[i].second, u) * x[i].first;
        u -= min(x[i].second, u);
    }
    for (int i = 0; i < sz(y); ++i) {
        ansx += min(y[i].second, v) * y[i].first;
        v -= min(y[i].second, v);
    }

    ll ansy = ans;
    v = (sumy + m - 1) / m;
    u = cnt - v;
    v *= m;
    u *= m;
    for (int i = 0; i < sz(x); ++i) {
        ansy += min(x[i].second, u) * x[i].first;
        u -= min(x[i].second, u);
    }
    for (int i = 0; i < sz(y); ++i) {
        ansy += min(y[i].second, v) * y[i].first;
        v -= min(y[i].second, v);
    }

    ans = max(ansx, ansy);
    cout << ans << endl;
}