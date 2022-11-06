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

struct aib {
    int n;
    vector<ll> data;

    void init(int _n) {
        n = _n;
        data = vector<ll>(n + 11, 0);
    }

    int zrs(int x) {
        return (x ^ (x - 1)) & x;
    }

    void add(int x, int v) {
        while (x <= n) {
            data[x] += v;
            x += zrs(x);
        }
    }

    ll sum(int x) {
        ll ans = 0;
        while (x > 0) {
            ans += data[x];
            x -= zrs(x);
        }
        return ans;
    }
};

int n, i;
int p[maxN];
aib work;

double ans = 0.00;
double aux, aux_sum;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &p[i]);

    if (n == 1) {
        printf("0.00");
        return 0;
    }

    work.init(n);
    for (i = n; i > 0; i--) {
        ans += work.sum(p[i]);
        work.add(p[i], +1);
    }

    work.init(n); aux = aux_sum = 0.00;
    for (i = n; i > 0; i--) {
        aux += work.sum(p[i]);
        aux_sum += aux;
        work.add(p[i], n - i + 1);
    }

    aux_sum /= (1.00 * n * (n + 1)) / 2.00;
    ans -= aux_sum;

    for (i = 1; i <= n; i++) {
        double invs = (1.00 * i * (i - 1)) / 4.00;
        double cases = 1.00 * (n - i + 1) / ( (1.00 * n * (n + 1)) / 2.00 );
        ans += invs * cases;
    }

    printf("%.20lf", ans);


    return 0;
}