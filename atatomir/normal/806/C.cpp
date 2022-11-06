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

const int def = 45;

int n, i, j;
ll v[maxN];
int two[maxN];
int dif[maxN];
int end_here[maxN];

int act_two[maxN];
int act_dif[maxN];

void add_val(ll x) {
    int i;

    for (i = 0; (1LL << (i + 1)) <= x; i++);
    if (x == (1LL << i))
        two[i]++;
    else
        dif[i]++;
}

bool check(int cnt) {
    int i, j, aux;

    memcpy(act_two, two, sizeof(two));
    memcpy(act_dif, dif, sizeof(dif));

    for (i = 0; i <= def && cnt > 0; i++) {
        aux = min(end_here[i], cnt);
        cnt -= aux;

        for (j = 0; j <= i; j++) {
            act_dif[j] += aux;
            act_two[j] -= aux;
        }
    }

    aux = 0;
    for (i = def; i >= 0; i--) {
        aux += act_two[i] - act_two[i + 1];
        aux -= act_dif[i];
        if (aux < 0) return 0;
    }

    return 1;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
        add_val(v[i]);
    }

    for (i = 1; i <= def; i++) {
        if (two[i] > two[i - 1]) {
            dif[i] += two[i] - two[i - 1];
            two[i] = two[i - 1];
        }

        end_here[i - 1] = two[i - 1] - two[i];
    }

    if (!check(0)) {
        printf("-1");
        return 0;
    }

    int ans = 0;
    for (int step = 1 << 20; step > 0; step >>= 1)
        if (ans + step <= two[0])
            if (check(ans + step))
                ans += step;

    for (; ans >= 0; ans--) printf("%d ", two[0] - ans );


    return 0;
}