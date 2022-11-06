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

#define maxN 300011

int n, q, i;
int op, x;

int last, ans, cnt;
vector<int> notif[maxN];
bool valid[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &op, &x);

        if (op == 1) {
            notif[x].pb(++cnt);
            valid[cnt] = true;
            ans++;
        }

        if (op == 2) {
            for (auto e : notif[x])
                if (valid[e] == true)
                    valid[e] = false, ans--;
            notif[x].clear();
        }

        if (op == 3) {
            for (int j = last + 1; j <= x; j++)
                if (valid[j] == true)
                    valid[j] = false, ans--;
            last = max(last, x);
        }

        printf("%d\n", ans);
    }


    return 0;
}