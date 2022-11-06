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

#define maxN 1100011
#define inf 1000000000


int def = 1000;

int need, n, i, j, dim, pos, cmmdc, mini;
int a[maxN];
bool on[maxN];
int ans;

vector<int> tps;
int data[maxN];
queue<int> Q;

void check_left() {
    int i;

    for (i = 0; i < need; i++)
        if (on[i])
            return;

    printf("-1");
    exit(0);
}

void check_right() {
    int i;

    for (i = need + 1; i <= def; i++)
        if (on[i])
            return;

    printf("-1");
    exit(0);
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &need, &n); mini = need;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mini = min(mini, a[i]);
    }

    need -= mini;
    for (i = 1; i <= n; i++) {
        a[i] -= mini;
        on[a[i]] = true;
    }

    if (on[need]) {
        printf("1");
        return 0;
    }

    check_left();
    check_right();

    for (i = 0; i <= def; i++) {
        if (on[i]) {
            tps.pb(i - need);
            data[def + i - need] = 1;
            Q.push(def + i - need);
        }
    }

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();

        for (int bon : tps) {
            int to = node + bon;

            if (to < 0 || to > 2 * def) continue;
            if (data[to]) continue;
            data[to] = data[node] + 1;
            Q.push(to);
        }
    }

    printf("%d", data[def]);

    return 0;
}