#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define M 1000010

using namespace std;

typedef long long ll;

struct node {
    ll a, b, c;
    node() {}
    node(ll _1, ll _2, ll _3) {a = _1, b = _2, c = _3;}
    bool operator < (const node& X) const {return a < X.a;}
};

node X[M];

ll F[M], A[M];

int n ;

ll Do(ll x, ll y) {
    ll s = X[y].a - X[x].a;
    return F[x] - X[y].c + X[y].b * s;
}

ll calc(ll a, ll b, ll c, ll d) { // < : 0
    if(b == 0 || d == 0) {
        if(b == 0 && d != 0) return 1;
        if(d == 0 && b != 0) return 0;
        if(b == 0 && d == 0) return 1;
    } else {
        if((double) a * d <= 1e18 && (double) b * c <= 1e18)
            return a * d >= b * c;
        ll X = a / b, Y = c / d;
        if(X != Y) return X >= Y;
        return calc(d, c % d, b, a % b);
    }
}

bool check(ll a, ll b, ll c) {
    ll ax = X[a].a, ay = F[a], bx = X[b].a, by = F[b], cx = X[c].a, cy = F[c];
    return calc(by - ay, bx - ax, cy - by, cx - bx);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        X[i] = node(a, b, c);
    }
    sort(X + 1, X + n + 1);
    vector <int> V(0);
    V.push_back(0);
    int t = 0;
    for(int i = 1; i <= n; i++) {
        ll nwans = Do(V[t], i), tmp;
        while(t + 1 != V.size() && nwans < (tmp = Do(V[t + 1], i))) {
            nwans = tmp;
            t++;
        }
        F[i] = nwans;
        if(F[i] > F[V.back()]) {
            while(t + 1 != V.size() && !check(V[V.size() - 2], V.back(), i)) V.pop_back();
            V.push_back(i);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, F[i]);
    printf("%lld\n", ans);
    return 0;
}