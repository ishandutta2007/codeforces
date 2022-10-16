#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int x[MAXN], y[MAXN];
vector<int> vx[2 * MAXN], vy[2 * MAXN];

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

pair<int, int> extGcd(int a, int b) {
    if(!b)
        return make_pair(1, 0);
    pair<int, int> p = extGcd(b, a % b);
    return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x, int m) {
    int res = extGcd(x, m).first;
    if(res < 0)
        res += m;
    return res;
}

void srt(vector< pair<int, int> > &x) {
    sort(x.begin(), x.end());
    size_t n = 0;
    for(size_t i = 1; i < x.size(); i++) {
        if(x[i].first != x[n].first) {
            n++;
            x[n] = x[i];
        }
    }
    n++;
    x.resize(n);
}

long long solve(int n, int m, const vector<int> &x, const vector<int> &y) {
    if(x.empty() && y.empty())
        return -2;
    vector< pair<int, int> > xx, yy;
    int invn = inv(n, m), invm = inv(m, n);
    for(size_t i = 0; i < x.size(); i++) {
        xx.push_back(make_pair(((long long)x[i] * invm) % n, x[i]));
        yy.push_back(make_pair(((long long)(x[i] % m) * invn) % m, x[i]));
    }
    for(size_t i = 0; i < y.size(); i++) {
        yy.push_back(make_pair(((long long)y[i] * invn) % m, y[i]));
        xx.push_back(make_pair(((long long)(y[i] % n) * invm) % n, y[i]));
    }
    srt(xx);
    xx.push_back(make_pair(xx[0].first + n, xx[0].second));
    srt(yy);
    yy.push_back(make_pair(yy[0].first + m, yy[0].second));
    long long res = -1;
    if((int)x.size() != n)
        for(size_t i = 0; i + 1 < xx.size(); i++)
            res = max(res, (long long)(xx[i + 1].first - xx[i].first - 1) * m +
                      xx[i].second);
    if((int)y.size() != m)
        for(size_t i = 0; i + 1 < yy.size(); i++)
            res = max(res, (long long)(yy[i + 1].first - yy[i].first - 1) * n +
                      yy[i].second);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int b;
    cin >> b;
    for(int i = 0; i < b; i++)
        cin >> x[i];
    int g;
    cin >> g;
    for(int i = 0; i < g; i++)
        cin >> y[i];
    int gg = gcd(n, m);
    if(gg > b + g) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < b; i++)
        vx[x[i] % gg].push_back(x[i] / gg);
    for(int i = 0; i < g; i++)
        vy[y[i] % gg].push_back(y[i] / gg);
    int nn = n / gg, mm = m / gg;
    long long ans = -1;
    for(int i = 0; i < gg; i++) {
        long long cur = solve(nn, mm, vx[i], vy[i]);
        if(cur == -2) {
            cout << -1 << '\n';
            return 0;
        }
        if(cur != -1)
            ans = max(ans, cur * gg + i);
    }
    cout << ans << '\n';
    return 0;
}