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

#define maxN 1000011

int n, i, pos, j;
ll a[maxN], b[maxN];
map< ll, pair<int, int> > M;

vector<int> sol1, sol2;
bool inv;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        a[i] += a[i - 1];
    }
    for (i = 1; i <= n; i++) {
        scanf("%I64d", &b[i]);
        b[i] += b[i - 1];
    }

    if (a[n] > b[n]) {
        inv = true;
        for (i = 1; i <= n; i++)
            swap(a[i], b[i]);
    }

    pos = 0;
    for (i = 0; i <= n; i++) {
        while (pos < n && a[pos + 1] <= b[i]) pos++;

        ll dif = b[i] - a[pos];
        if (M.count(dif) == 1) {
            auto last = M[dif];

            for (j = last.first + 1; j <= pos; j++)
                sol1.pb(j);

            for (j = last.second + 1; j <= i; j++)
                sol2.pb(j);

            break;
        }
        M[dif] = mp(pos, i);
    }

    if (inv) swap(sol1, sol2);

    printf("%d\n", sol1.size());
    for (auto e : sol1) printf("%d ", e);
    printf("\n");

    printf("%d\n", sol2.size());
    for (auto e : sol2) printf("%d ", e);
    printf("\n");


    return 0;
}