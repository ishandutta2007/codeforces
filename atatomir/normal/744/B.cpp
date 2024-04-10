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

#define maxN 1024
#define inf 1000000009

int n, i, j;
int pre[10][2][maxN];
vector<int> m1, m2;

int main()
{

    scanf("%d", &n);
    for (int bit = 0; bit < 10; bit++) {
        m1.clear();
        m2.clear();
        for (i = 0; i < n; i++) {
            if ( (i >> bit) & 1 )
                m1.pb(i + 1);
            else
                m2.pb(i + 1);
        }

        if (m1.size() && m1.size() != n) {
            printf("%d\n", m1.size());
            for (auto e : m1)
                printf("%d ", e);
            printf("\n");
            fflush(stdout);

            for (i = 1; i <= n; i++) scanf("%d", &pre[bit][1][i]);
        }



        if (m2.size() && m2.size() != n) {
            printf("%d\n", m2.size());
            for (auto e : m2)
                printf("%d ", e);
            printf("\n");
            fflush(stdout);

            for (i = 1; i <= n; i++) scanf("%d", &pre[bit][0][i]);
        }

        if (m1.size() == 0) for (i = 1; i <= n; i++) pre[bit][1][i] = inf;
        if (m2.size() == 0) for (i = 1; i <= n; i++) pre[bit][0][i] = inf;
    }

    printf("-1\n");
    for (i = 0; i < n; i++) {
        int ans = inf;

        for (int bit = 0; bit < 10; bit++)
            if ( (i >> bit) & 1 )
                ans = min(ans, pre[bit][0][i + 1]);
            else
                ans = min(ans, pre[bit][1][i + 1]);

        printf("%d ", ans);
    }


    fflush(stdout);


    return 0;
}