#include <bits/stdc++.h>

using namespace std;

map <pair <int, int>, int> xy;
map <int, int> x;
map <int, int> y;

int X, Y;

long long ans = 0;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &X, &Y);
        xy[{X, Y}]++;
        x[X]++;
        y[Y]++;
    }
    for (auto f : x) {
        long long t = f.second;
        ans += t * (t - 1) / 2;
    }
    for (auto f : y) {
        long long t = f.second;
        ans += t * (t - 1) / 2;
    }
    for (auto f : xy) {
        long long t = f.second;
        ans -= t * (t - 1) / 2;
    }
    printf("%lld\n", ans);
}