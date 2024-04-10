#include <iostream>

using namespace std;

const int MAXM = 1000 * 1000 + 5;
int was[MAXM];

pair<pair<long long, long long>, long long> getPath(long long h, long long a,
                                                    long long x, long long y,
                                                    long long m) {
    for(int i = 0; i < m; i++)
        was[i] = -1;
    long long pos = h, len = 0, cycle = 0;
    bool found = false;
    while(was[pos] == -1) {
        was[pos] = cycle;
        if(pos == a)
            found = true;
        if(!found)
            len++;
        cycle++;
        pos = ((long long)x * pos + y) % m;
    }
    long long pref = was[pos];
    cycle -= pref;
    if(!found)
        return make_pair(make_pair(pref, cycle), -1);
    return make_pair(make_pair(pref, cycle), len);
}

long long gcd(long long a, long long b) {
    return b? gcd(b, a % b) : a;
}

pair<long long, long long> extGcd(long long a, long long b) {
    if(!b)
        return make_pair(1, 0);
    pair<long long, long long> p = extGcd(b, a % b);
    return make_pair(p.second, p.first - (a / b) * p.second);
}

long long solve(long long a, long long b, long long c) {
    long long g = gcd(a, -b);
    if(!c)
        return 0;
    if(!g)
        return -1;
    if(c % g)
        return -1;
    long long k = c / g;
    pair<long long, long long> p = extGcd(a, -b);
    p.first *= k;
    p.second *= -k;
    long long q = min((-p.first - 1) / (-b / g) + 1,
                (-p.second - 1) / (a / g) + 1);
    if(q > 0) {
        p.first -= q * (b / g);
        p.second += q * (a / g);
    }
    q = min(p.first / (-b / g), p.second / (a / g));
    if(q > 0) {
        p.first += q * (b / g);
        p.second -= q * (a / g);
    }
    return p.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long m, h0, a0, x0, y0, h1, a1, x1, y1;
    cin >> m >> h0 >> a0 >> x0 >> y0 >> h1 >> a1 >> x1 >> y1;
    pair<pair<long long, long long>, long long> p0 = getPath(h0, a0, x0, y0, m),
        p1 = getPath(h1, a1, x1, y1, m);
    if(p0.second == -1 || p1.second == -1) {
        cout << -1 << '\n';
        return 0;
    }
    int s = max(p0.first.first, p1.first.first);
    for(int i = 0; i < s; i++) {
        if(h0 == a0 && h1 == a1) {
            cout << i << '\n';
            return 0;
        }
        h0 = ((long long)x0 * h0 + y0) % m;
        h1 = ((long long)x1 * h1 + y1) % m;
    }
    p0 = getPath(h0, a0, x0, y0, m);
    p1 = getPath(h1, a1, x1, y1, m);
    if(p0.second == -1 || p1.second == -1) {
        cout << -1 << '\n';
        return 0;
    }
    if(p1.second < p0.second)
        swap(p0, p1);
    long long t =
        solve(p0.first.second, -p1.first.second, p1.second - p0.second);
    if(t == -1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << p0.first.second * t + p0.second + s << '\n';
    return 0;
}