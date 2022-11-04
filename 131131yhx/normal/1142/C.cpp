#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define M 200010
#define PLL pair <ll, ll>
#define PDD pair <long double, long double>
#define x first
#define y second
#define eps 1e-5

using namespace std;

typedef long long ll;

struct seg {
    ll A, C;
    seg() {}
    seg(ll _1, ll _2, ll _3) {
        A = _1, C = _3;
    }
};

int n;

PLL P[M];

seg Nw[M];

/*ll cross(PII A, PII md, PII B) {
    return (A.x - md.x) * (B.y - md.y) - (A.y - md.y) * (B.x - md.x);
}*/

long double getjiao(seg A, seg B) {
    long double detx = B.A - A.A, dety = B.C - A.C;
    long double x = dety / -detx;
    return x;
}

bool up(seg A, PDD B) {
    return A.A * B.x + B.y + A.C < eps;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld", &P[i].x, &P[i].y);
    }
    sort(P + 1, P + n + 1);
    int t = 0;
    for(int i = 1; i <= n; i++)
        if(i == n || P[i].x != P[i + 1].x) P[++t] = P[i];
    n = t;
    for(int i = 1; i <= t; i++) {
        Nw[i] = seg(P[i].x, 1, P[i].x * P[i].x - P[i].y);
    }
    vector <seg> V(1, Nw[1]);
    for(int i = 2; i <= t; i++) {
        while(V.size() >= 2 && getjiao(V[(int) V.size() - 2], V.back()) < getjiao(V.back(), Nw[i]) + eps) V.pop_back();
        V.push_back(Nw[i]);
    }
    printf("%d\n", (int) V.size() - 1);
    return 0;
    return 0;
}