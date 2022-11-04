#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <vector>
#include <bitset>
#define eps 1e-12

using namespace std;

int n, X[3], Y[3], R[3], D[3], F[233333];

struct nd {
    double x, y;
    nd() {}
    nd(double _1, double _2) {
        x = _1;
        y = _2;
    }
};

vector <nd> S;

int getf(int x) {
    return F[x] == x ? x : F[x] = getf(F[x]);
}

void merge(int x, int y) {
    if(getf(x) != getf(y)) F[getf(x)] = getf(y);
}

double sqr(double x) {return x * x;}

bool equal(double x, double y) {return (y - x) <= eps && (y - x >= -eps);}

bool equal(nd x, nd y) {return equal(x.x, y.x) && equal(x.y, y.y);}

void Solve(int x, double alp) {
    S.push_back(nd(X[x] + R[x] * cos(alp), Y[x] + R[x] * sin(alp)));
}

double dis(nd X, nd Y) {
    return sqrt(sqr(X.x - Y.x) + sqr(X.y - Y.y));
}

int ans = 1;

void calc(int x, int y) {
    double ds = dis(nd(X[x], Y[x]), nd(X[y], Y[y])), val = (sqr(R[x]) - sqr(R[y]) + sqr(ds)) / 2 / R[x] / ds, alp = atan2(X[y] - X[x], Y[y] - Y[x]);
    if(val < 1 + eps && val > -1 - eps) {
        Solve(x, asin(val) - alp);
        Solve(x, M_PI - asin(val) - alp);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d%d", &X[i], &Y[i], &R[i]);
    ans += n;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            calc(i, j);
    for(int i = 0; i < S.size(); i++)
        for(int j = i + 1; j < S.size(); j++)
            if(equal(S[i], S[j])) {
                S[i] = nd(-1e18, -1e18);
                break;
            }
    int t = 0;
    for(int i = 0; i < S.size(); i++) if(!equal(S[i], nd(-1e18, -1e18))) S[t++] = S[i];
    S.resize(t);
    ans -= t;
    for(int i = 0; i < n + t; i++) F[i] = i;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < S.size(); j++) if(equal(dis(S[j], nd(X[i], Y[i])), R[i])) {
            merge(i, n + j);
            ans++;
        }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) if(getf(i) == getf(j)) {
            ans--;
            break;
        }
    printf("%d\n", ans);
    return 0;
}