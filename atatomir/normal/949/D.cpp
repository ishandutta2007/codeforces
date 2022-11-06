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

const int maxN = 100011;

ll n, d, b, i;
ll v[maxN], aux[maxN];

bool can_move(int i, int j) {
    return (j - i) <= i * d;
}

bool sub_check(int need, int limit) {
    ll i, j;
    ll p1, p2, act, to_rm;

    p1 = 1;
    p2 = 0;
    act = 0;
    for (i = 1; i <= limit && need > 0; i++) {
        while (p2 + 1 <= n && can_move(i, p2 + 1)) {
            act += aux[p2 + 1];
            p2++;
        }

        if (act >= b) {
            need--;
            act -= b;
            to_rm = b;

            while (to_rm > 0) {
                ll here = min(to_rm, aux[p1]);
                to_rm -= here;
                aux[p1] -= here;
                if (aux[p1] == 0) p1++;
            }
        }
    }

    return need <= 0;
}

bool check(int free) {
    int need;

    memcpy(aux, v, sizeof(aux));
    need = ((n + 1) / 2) - free;
    if (!sub_check(need, (n + 1) / 2)) return false;

    reverse(aux + 1, aux + n + 1);
    need = (n / 2) - free;
    if (!sub_check(need, n / 2)) return false;

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> d >> b;
    for (i = 1; i <= n; i++) cin >> v[i];


    int ans = -1;
    for (int step = 1 << 20; step > 0; step >>= 1)
        if (!check(ans + step))
            ans += step;

    cout << ans + 1;


    return 0;
}