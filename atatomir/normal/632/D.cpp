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

#define maxN 1000011

int n, m, i, x;
int cnt[maxN];
vector<int> who[maxN];
bool last[maxN];

int val, v;
vector<int> divs[maxN];
vector<int> limit;
int act;

pair<int, int> ans;
vector<int> sol;


void sieve() {
    ll i, j;

    for (i = 2; i <= m; i++) {
        if (divs[i].size() > 0) continue;

        for (j = i; j <= m; j += i)
            divs[j].pb(i);
    }
}

void back(int step) {
    int ant = v;

    if (step == divs[val].size()) {
        act += cnt[v];
        last[v] = true;
        return;
    }

    back(step + 1);
    for (int i = 1; i <= limit[step]; i++) {
        v *= divs[val][step];
        back(step + 1);
    }

    v = ant;
}

int check(int _val) {
    int i;

    val = _val;
    limit.clear();
    for (int e : divs[val]) {
        int how_many = 0;

        int x = val;
        while (x % e == 0) how_many++, x /= e;

        limit.pb(how_many);
    }

    act = 0; v = 1;
    back(0);

    return act;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x <= m) cnt[x]++, who[x].pb(i);
    }

    sieve();

    ans = mp(-1, -1);

    for (i = 1; i <= m; i++)
        ans = max(ans, mp(check(i), -i));

    ans.second *= -1;

    memset(last, 0, sizeof(last));
    check(ans.second);
    for (i = 1; i <= m; i++) {
        if (last[i]) {
            for (auto e : who[i])
                sol.pb(e);
        }
    }

    sort(sol.begin(), sol.end());
    printf("%d %d\n", ans.second, ans.first);
    for (auto e : sol)
        printf("%d ", e);

    return 0;
}