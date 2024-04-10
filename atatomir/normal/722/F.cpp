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

#define maxN 100011
#define maxDim 55

int n, m, i, j, k, x, nr, ans, last;
int dim[maxN];
vector< pair<int, int> > pos[maxN];

vector<int> divs[maxDim];
int cnt[maxDim];
int act[maxDim];
queue< pair<int, int> > Q;


bool can_push(int mod, int rem) {
    for (auto e : divs[mod])
        if (cnt[e] != 0 && act[e] != rem % e)
            return false;

    return true;
}

void pop_queue() {
    int mod, rem;

    if (Q.empty())
        cerr << "empty queue..";

    mod = Q.front().first;
    rem = Q.front().second;
    Q.pop();

    for (auto e : divs[mod]) {
        cnt[e]--;
        if (cnt[e] == 0) act[e] = 0;
    }
}

void push_queue(int mod, int rem) {
    for (auto e : divs[mod]) {
        if (cnt[e] == 0) {
            act[e] = rem % e;
            cnt[e] = 1;
        } else {
            if (act[e] != rem % e) cerr << "error";
            cnt[e]++;
        }
    }

    Q.push(mp(mod, rem));
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &k);

        dim[i] = k;
        for (j = 1; j <= k; j++) {
            scanf("%d", &x);
            pos[x].pb(mp(i, j % k));
        }
    }

    for (i = 1; i <= 40; i++)
        for (j = 1; j <= i; j++)
            if (i % j == 0)
                divs[i].pb(j);

    for (nr = 1; nr <= m; nr++) {
        ans = 0;

        memset(cnt, 0, sizeof(cnt));
        memset(act, 0, sizeof(act));
        while (!Q.empty()) Q.pop();

        for (auto e : pos[nr]) {
            if (e.first != last + 1) {
                memset(cnt, 0, sizeof(cnt));
                memset(act, 0, sizeof(act));
                while (!Q.empty()) Q.pop();
            }
            last = e.first;

            while (!can_push(dim[e.first], e.second))
                pop_queue();

            push_queue(dim[e.first], e.second);

            ans = max(ans, (int)Q.size());
        }

        printf("%d\n", ans);
    }

    return 0;
}