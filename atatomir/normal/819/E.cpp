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

#define maxN 333

int n, i, p, a, b;
vector< vector<int> > ans, act, aux;

bool check() {
    int i, j;
    int cnt[maxN][maxN];

    for (auto &v : ans) {
        v.pb(v[0]);
        for (i = 1; i < v.size(); i++) {
            cnt[v[i - 1]][v[i]]++;
            cnt[v[i]][v[i - 1]]++;
        }
        v.pop_back();
    }

    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            if (cnt[i][j] != 2)
                return false;

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    if (n % 2 == 0) {
        act.pb({1, 2, 3});
        act.pb({3, 4, 1});
        ans.pb({2, 4, 3});
        ans.pb({2, 4, 1});
        p = 4;

        while (p < n) {
            p += 2;
            a = p - 1;
            b = p;

            aux = act;
            act.clear();

            for (auto e : aux) {
                if (e[0] == 1) {
                    act.pb({a, b, 1});
                    ans.pb({a, b, 2});
                } else {
                    ans.pb({e[0], a, e[1], b});
                }
                ans.pb({e[0], a, e[1], e[2]});
                act.pb({e[0], e[1], b});
            }

        }

    } else {
        ans = {{2, 3, 1}};
        act = {{2, 3, 1}};
        p = 3;

        while (p < n) {
            p += 2;
            a = p - 1;
            b = p;

            aux = act;
            act.clear();
            for (auto e : aux) {
                ans.pb({e[0], a, e[1], b});
                ans.pb({e[0], a, e[1], e[2]});
                act.pb({e[0], e[1], b});
            }

            ans.pb({a, b, 1});
            act.pb({a, b, 1});
        }
    }

    for (auto e : act) ans.pb(e);

    if (!check()) {
        cerr << "error";
        return 0;
    }

    printf("%d\n", ans.size());
    for (auto v : ans) {
        printf("%d ", v.size());
        for (auto e : v)
            printf("%d ", e);
        printf("\n");
    }

    return 0;
}