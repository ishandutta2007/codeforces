#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define MAXN 2000010
ld mn[MAXN], mx[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    ll dx1, dy1, dx2, dy2;
    scanf("%lld%lld%lld%lld", &dx1, &dy1, &dx2, &dy2);
    if (dy1 < 0) {
        dy1 = -dy1;
        dx1 = -dx1;
    }
    if (dy2 < 0) {
        dy2 = -dy2;
        dx2 = -dx2;
    }

    if (dy1 == 0) {
        dx1 = abs(dx1);
    }
    if (dy2 == 0) {
        dx2 = abs(dx2);
    }

    if (dy1*dx2 == dx1*dy2) {
        printf("NO\n");
        return 0;
    }
    if (dy1*dx2 < dx1*dy2) {
        swap(dx1, dx2);
        swap(dy1, dy2);
    }
    for (int i = 0; i <= dy1; i++) {
        mn[i] = ((ld)i/(ld)dy1)*dx1;
    }
    for (int i = 0; i < dy2; i++) {
        mx[i] = ((ld)i/(ld)dy2)*dx2;
    }
    for (int i = dy1+1; i <= dy1+dy2; i++) {
        mn[i] = ((ld)(i-dy1)/(ld)dy2)*dx2 + dx1;
    }
    for (int i = dy2; i <= dy1+dy2; i++) {
        mx[i] = ((ld)(i-dy2)/(ld)dy1)*dx1 + dx2;
    }

    vector<pair<int, int> > points;
    for (int i = 0; i < dy1+dy2 && (int)points.size() <= 100000; i++) {
        //printf("%.10Lf %.10Lf - ", mn[i], mx[i]);
        mn[i] += 2000000;
        mx[i] += 2000000;
        if (i < dy1) {
            mn[i] += 1 - (1e-8);
        } else {
            mn[i] += 1 + (1e-8);
        }

        if (i < dy2) {
            mx[i] += (1e-8);
        } else {
            mx[i] += -(1e-8);
        }

        //printf("%.10Lf %.10Lf\n", mn[i], mx[i]);

        for (int j = mn[i]; j <= mx[i]; j++) {
            points.push_back({j, i});
        }
    }
    ll sz = abs(dx1*dy2-dy1*dx2);
    //printf("%lld\n", sz);
    //assert(sz == (ll)points.size());
    if ((int)points.size() != n) {
        printf("NO\n");
        //for (auto a : points) printf("%d %d\n", a.first, a.second);
    } else {
        printf("YES\n");
        for (auto a : points) printf("%d %d\n", a.first, a.second);
    }
}