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

const int maxN = 400011;
const int maxLog = 21;
const int def = 200000;

int n, i, maxi, x, act, ans = 100000;
bool on[maxLog][maxN];
vector<int> sol, aux;

void solve(int step, int limit) {
    int i, maxi, to;
    bool need = false;

    if (step == maxLog - 1 || act >= ans) return;

    if (limit == 0) {
        ans = act;
        sol = aux;
        return;
    }

    for (i = -limit; i <= limit; i++)
        if (on[step][i + def] && (abs(i) & 1))
            need = true;

    if (!need) {
        maxi = 0;
        for (i = -limit; i <= limit; i++) {
            if (on[step][i + def]) {
                to = (i / 2);
                on[step + 1][to + def] = true;
                maxi = max(maxi, abs(to));
            }
        }

        solve(step + 1, maxi);
        for (i = -limit; i <= limit; i++) on[step + 1][i + def] = false;
    } else {
        act++;

        aux.pb(-(1 << step));
        maxi = 0;
        for (i = -limit; i <= limit; i++) {
            if (on[step][i + def]) {
                to = (i & 1 ? i + 1 : i) / 2;
                on[step + 1][to + def] = true;
                maxi = max(maxi, abs(to));
            }
        }

        solve(step + 1, maxi);
        for (i = -limit; i <= limit; i++) on[step + 1][i + def] = false;
        aux.pop_back();

        aux.pb(1 << step);
        maxi = 0;
        for (i = -limit; i <= limit; i++) {
            if (on[step][i + def]) {
                to = (i & 1 ? i - 1 : i) / 2;
                on[step + 1][to + def] = true;
                maxi = max(maxi, abs(to));
            }
        }

        solve(step + 1, maxi);
        for (i = -limit; i <= limit; i++) on[step + 1][i + def] = false;
        aux.pop_back();

        act--;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        on[0][def + x] = true;
        maxi = max(maxi, abs(x));
    }

    solve(0, maxi);

    printf("%d\n", ans);
    for (auto e : sol) printf("%d ", e);



    return 0;
}