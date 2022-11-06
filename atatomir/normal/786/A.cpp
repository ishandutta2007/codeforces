#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 15011

int n, k, i, x;
vector<int> s[maxN];
int gr[maxN];
int ans[maxN];
queue<int> Q;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);

    scanf("%d", &k);
    for (i = 1; i <= k; i++) {
        scanf("%d", &x);
        s[0].pb(x);
    }

    scanf("%d", &k);
    for (i = 1; i <= k; i++) {
        scanf("%d", &x);
        s[1].pb(x);
    }

    for (i = 1; i < n; i++) {
        for (auto e : s[0]) {
            int to = (i + e) % n;
            //list[to + n].pb(i);
            gr[i]++;
        }
    }

    for (i = 1; i < n; i++) {
        for (auto e : s[1]) {
            int to = (i + e) % n;
            //list[to].pb(i + n);
            gr[i + n]++;
        }
    }

    for (i = 0; i <= 2 * n; i++)
        ans[i] = -1;

    ans[0] = ans[n] = 0;
    Q.push(0);
    Q.push(n);

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();

        if (ans[node] == 0) {
            for (auto e : s[(node < n ? 1 : 0)]) {
                int to = (node + n - e) % n;
                if (node < n) to += n;

                if (ans[to] != -1) continue;
                ans[to] = 1;
                Q.push(to);
            }
        } else {
            for (auto e : s[(node < n ? 1 : 0)]) {
                int to = (node + n - e) % n;
                if (node < n) to += n;

                if (ans[to] != -1) continue;
                if (--gr[to] == 0) {
                    ans[to] = 0;
                    Q.push(to);
                }
            }
        }
    }

    for (i = 1; i < n; i++) {
        if (ans[i] == 1)
            printf("Win ");
        if (ans[i] == 0)
            printf("Lose ");
        if (ans[i] == -1)
            printf("Loop ");
    }
    printf("\n");

    for (i = 1 + n; i < 2 * n; i++) {
        if (ans[i] == 1)
            printf("Win ");
        if (ans[i] == 0)
            printf("Lose ");
        if (ans[i] == -1)
            printf("Loop ");
    }
    printf("\n");




    return 0;
}