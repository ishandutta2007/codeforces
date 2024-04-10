#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 50011



int n, i, j, nr;
int v[maxN];
vector<int> sol;
vector<int> aux;

map<int, bool> used;


bool check(int lim) {
    int i;

    sol.clear();
    aux.clear();

    for (i = 1; i <= n; i++) {
        int x = v[i];

        while (x > lim) x >>= 1;
        aux.pb(x);
    }

    sort(aux.begin(), aux.end());
    used.clear();

    for (auto e : aux) {
        bool found = false;

        for (i = 0; i <= 30; i++) {
            if ( (e >> i) == 0 ) break;
            if (used[e >> i]) continue;

            sol.pb(e >> i);
            used[e >> i] = found = true;
            break;
        }

        if (!found) return false;
    }

    return true;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    int ans = 0;
    for (int step = (1 << 29); step > 0; step >>= 1)
        if (!check(ans + step))
            ans += step;

    check(ans + 1);
    for (auto e : sol) printf("%d ", e);



    return 0;
}