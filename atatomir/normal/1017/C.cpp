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

int n, i, j, p[maxN], sol;
pair<int, int> best;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    best = mp(n + 1, n);

    for (i = 1; i <= n; i++) {
        j = (n + i - 1) / i;
        best = min(best, mp(i + j, i));
    }

    sol = best.second;
    for (i = 1; i <= n; i++) p[i] = i;
    for (i = 1; i <= n; i += sol) {
        reverse(p + i, p + min(n + 1, i + sol));
    }

    for (i = 1; i <= n; i++) printf("%d ", p[i]);

    return 0;
}