#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

const int MAXN = 105, MOD = 1000 * 1000 * 1000 + 7;
int n;
map<int, long long> a[MAXN], b[MAXN];

long long gcd(long long x, long long y) {
    return y? gcd(y, x % y) : x;
}

pair<long long, long long> extGcd(long long x, long long y) {
    if(!y)
        return make_pair(1, 0);
    pair<long long, long long> p = extGcd(y, x % y);
    return make_pair(p.second, p.first - (x / y) * p.second);
}

int powMod(int x, long long p) {
    int y = 1;
    while(p) {
        if(p & 1ll)
            y = (long long)y * x % MOD;
        p >>= 1;
        x = (long long)x * x % MOD;
    }
    return y;
}

void fact(int x, map<int, long long> &mp) {
    for(int i = 2; i * i <= x; i++)
        if(!(x % i)) {
            int y = 0;
            while(!(x % i)) {
                x /= i;
                y++;
            }
            mp[i] = y;
        }
    if(x > 1)
        mp[x] = 1;
}

bool intersect(long long &a0, long long &b0, long long a1, long long b1) {
    long long c = a1 - a0, g = gcd(b0, b1);
    if(c % g)
        return false;
    pair<long long, long long> p = extGcd(b0, b1);
    p.first *= c / g;
    p.second *= -c / g;
    long long lcm = b0 / g * b1;
    if(p.first < 0) {
        long long k = (-p.first + (lcm / b0) - 1) / (lcm / b0);
        p.first += k * (lcm / b0);
        p.second += k * (lcm / b1);
    }
    long long k = p.first / (lcm / b0);
    p.first -= k * (lcm / b0);
    p.second -= k * (lcm / b1);
    if(p.second < 0) {
        k = (-p.second + (lcm / b1) - 1) / (lcm / b1);
        p.first += k * (lcm / b0);
        p.second += k * (lcm / b1);
    }
    a0 = a0 + b0 * p.first;
    b0 = lcm;
    return true;
}

map<int, long long> get(int id, long long k) {
    map<int, long long> mp;
    for(map<int, long long>::iterator it = a[id].begin();
        it != a[id].end(); it++)
        if(it->second)
            mp[it->first] = it->second;
    if(k)
        for(map<int, long long>::iterator it = b[id].begin();
            it != b[id].end(); it++)
            mp[it->first] += k * it->second;
    return mp;
}

bool check(const map<int, long long> &mp) {
    for(int i = 0; i < n; i++) {
        long long k;
        if(b[i].empty())
            k = 0;
        else {
            int p = b[i].begin()->first;
            long long aa = a[i][p], bb = b[i].begin()->second;
            k = (mp.find(p) == mp.end()? 0 : mp.find(p)->second) - aa;
            if(k < 0 || k % bb)
                return false;
            k /= bb;
        }
        map<int, long long> mp0 = get(i, k);
        if(mp != mp0)
            return false;
    }
    return true;
}

void getAns(int id, long long k) {
    map<int, long long> mp = get(id, k);
    if(!check(mp)) {
        cout << -1 << '\n';
        return;
    }
    int ans = 1;
    for(map<int, long long>::iterator it = mp.begin(); it != mp.end(); it++)
        ans = (long long)ans * powMod(it->first, it->second) % MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int aa, bb;
        cin >> aa >> bb;
        fact(aa, a[i]);
        fact(bb, b[i]);
        for(map<int, long long>::iterator it = b[i].begin();
            it != b[i].end(); it++)
            a[i][it->first];
    }
    for(int i = 0; i < n; i++)
        if(b[i].empty()) {
            getAns(i, 0);
            return 0;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            long long aa = -1, bb = -1, cc = -1;
            for(map<int, long long>::iterator it = b[i].begin();
                it != b[i].end(); it++) {
                int p = it->first;
                long long a0 = a[i][p], b0 = it->second,
                    a1 = (a[j].find(p) == a[j].end()? 0 : a[j][p]),
                    b1 = (b[j].find(p) == b[j].end()? 0 : b[j][p]);
                if(b1 == 0) {
                    if(a1 < a0 || (a1 - a0) % b0)
                        cout << -1 << '\n';
                    else
                        getAns(i, (a1 - a0) / b0);
                    return 0;
                }
                long long na = b0, nb = -b1, nc = a1 - a0, g = gcd(b0, b1);
                if(nc % g) {
                    cout << -1 << '\n';
                    return 0;
                }
                na /= g;
                nb /= g;
                nc /= g;
                if(aa == -1) {
                    aa = na;
                    bb = nb;
                    cc = nc;
                    continue;
                }
                if(aa == na && bb == nb && cc == nc)
                    continue;
                long long x = nb * cc - bb * nc, y = aa * nb - na * bb;
                if(!y || x % y || x / y < 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                getAns(i, x / y);
                return 0;
            }
        }
    int p = b[0].begin()->first;
    long long aa = a[0][p], bb = b[0].begin()->second;
    for(int i = 1; i < n; i++)
        if(!intersect(aa, bb, a[i][p], b[i][p])) {
            cout << -1 << '\n';
            return 0;
        }
    getAns(0, (aa - a[0][p]) / b[0].begin()->second);
    return 0;
}