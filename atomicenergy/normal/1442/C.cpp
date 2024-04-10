
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt& operator+=(const ModInt& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator-=(const ModInt& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator*=(const ModInt& p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt& operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }

    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const ModInt& p) {
        return os << p.x;
    }

    friend istream& operator>>(istream& is, ModInt& a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using mint = ModInt< 998244353 >;





mint power(mint a, long long b) {
    if (b == 0) return 1;
    mint y = power(a, b / 2);
    if (b % 2 == 0) return y * y;
    return y * y * a;
}




const auto INF = numeric_limits< long long >::max();

vector< long long > dijkstra(const vector< vector< pair<long long, long long> > >& g, long long s) {
    
    vector< long long > dist(g.size(), INF);

    priority_queue< pair< long long, long long >, vector< pair< long long, long long > >, greater<> > pq;
    dist[s] = 0;
    pq.push({ dist[s], s });
    while (!pq.empty()) {
        long long cost = pq.top().first;
        long long idx = pq.top().second;
        pq.pop();
        if (dist[idx] < cost) continue;
        for (auto u : g[idx]) {
            auto next_cost = cost + u.second;
            if (dist[u.first] <= next_cost) continue;
            dist[u.first] = next_cost;
            pq.push({ dist[u.first], u.first });
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m;
    cin >> n >> m;


    vector<pair<long long, long long> > v;
    for (long long i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        x--, y--;
        v.push_back({ x, y });
    }

    vector< vector< pair<long long, long long> > > g2(n*20);

    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < 20; j++) {
            if (j % 2 == 0) {
                g2[20*v[i].first + j].push_back({ 20*v[i].second + j, 1 });
            }
            else {
                g2[20 * v[i].second + j].push_back({ 20 * v[i].first + j, 1 });
            }
        }
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < 19; j++) {
            g2[20 * i + j].push_back({ 20 * i + j + 1, (1ll << j) });
        }
    }

    auto dists = dijkstra(g2, 0);

    ll mn = INF;

    for (long long j = 0; j < 19; j++) {
        mn = min(mn, dists[(n - 1) * 20 + j]);
    }

    if (mn < INF) {
        cout << mn << endl;
        return 0;
    }

    vector< vector< pair<long long, long long> > > g3(n * 2);

    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < 2; j++) {
            if (j % 2 == 0) {
                g3[2 * v[i].first + j].push_back({ 2 * v[i].second + j, 1 });
            }
            else {
                g3[2 * v[i].second + j].push_back({ 2 * v[i].first + j, 1 });
            }
        }
    }

    for (long long i = 0; i < n; i++) {
        
            g3[2 * i].push_back({ 2 * i + 1, 1000000 });
            g3[2 * i + 1].push_back({ 2 * i, 1000000 });
    }

    auto dists2 = dijkstra(g3, 0);

    ll mn2 = min(dists2[2 * n - 2], dists2[2 * n - 1]);
    ll flips = mn2 / 1000000;
    mn2 %= 1000000;
    mint ans = power(2, flips) - 1;
    ans += mn2;
    cout << ans << endl;
}