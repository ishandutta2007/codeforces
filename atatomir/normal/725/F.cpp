#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

int n, i;
int a, b, c, d;
vector<ll> v;
ll ans;


void add(int a, int b) {
    ans += a - b;
    v.pb(a + b);
}

void add_stack() {
    if (a + b >= c + d) {
        add(a, b);
        add(c, d);
        return;
    }

    if (a > d)
        add(a - d, d - a);
    if (b > c)
        add(c - b, b - c);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add_stack();
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll sgn = 1;
    for (auto e : v) {
        ans += sgn * e;
        sgn *= -1;
    }

    printf("%lld", ans / 2);
    return 0;
}