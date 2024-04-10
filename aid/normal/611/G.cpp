#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;

    Point() {}

    Point(long long _x, long long _y): x(_x), y(_y) {}

    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

const int MAXN = 1000 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
Point p[MAXN], sum[MAXN];
unsigned long long s[MAXN];
int ssum[MAXN];

long long cp(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

void sub(int &a, int b) {
    a -= b;
    if(a < 0)
        a += MOD;
}

unsigned long long getS(int i, int j) {
    return s[j] - s[i] - cp(p[i] - p[0], p[j] - p[0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    reverse(p, p + n);
    for(int i = 0; i < n; i++)
        p[n + i] = p[i];
    sum[0] = Point(0, 0);
    for(int i = 0; i < 2 * n - 1; i++) {
        sum[i + 1] = sum[i] + (p[i + 1] - p[0]);
        sum[i + 1].x %= MOD;
        sum[i + 1].y %= MOD;
    }
    s[0] = 0;
    for(int i = 0; i < 2 * n - 1; i++)
        s[i + 1] = s[i] + cp(p[i] - p[0], p[i + 1] - p[0]);
    ssum[0] = 0;
    for(int i = 0; i < 2 * n - 1; i++)
        ssum[i + 1] = ((unsigned long long)ssum[i] + s[i + 1]) % MOD;
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        int l = i, r = i + n;
        while(l < r - 1) {
            int m = (l + r) / 2;
            unsigned long long ss = getS(i, m);
            if(2 * ss <= s[n])
                l = m;
            else
                r = m;
        }
        int j = l;
        sub(ans, (long long)(j - i) * (s[i] % MOD) % MOD);
        add(ans, (ssum[j] - ssum[i] + MOD) % MOD);
        sub(ans, (cp(p[i] - p[0], sum[j] - sum[i]) % MOD + MOD) % MOD);
        if((unsigned long long)2 * getS(i, j) == s[n])
            cnt++;
    }
    sub(ans, (long long)(cnt / 2) * (s[n] / 2) % MOD);
    ans = (((long long)n * (n - 3) / 2) % MOD * (s[n] % MOD) - 2 * ans) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}