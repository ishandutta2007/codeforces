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

int n, k, i, j, cnt;
int v[maxN], com;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= k; i++) {
        scanf("%d", &cnt);
        for (j = 1; j <= cnt; j++)
            scanf("%d", &v[j]);

        for (j = 1; v[j] == j && j <= cnt; j++);
        com = max(com, j - 1);
    }

    cout << 2 * n - 2 * com - k + 1;

    return 0;
}