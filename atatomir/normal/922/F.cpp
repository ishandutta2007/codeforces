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
#define maxNeed 1024

ll n, k, i, j, act, pos, need;
ll cnt[maxN];
vector< pair<ll, ll> > aux;

int ss, dd;
pair<ll, ll> dp[maxNeed][maxNeed];
bool deny[maxN];

void clean_up(pair<ll, ll>* data) {
    static int i;

    for (i = 0; i <= need; i++)
        data[i] = mp(-1, -1);
}

void recons(int step) {
    while (step > 0) {
        if (dp[step][need].first == 0) {
            step--;
        } else {
            deny[ dp[step][need].second ] = true;
            need -= dp[step][need].first;
            step--;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= pos; i++)
        if (!deny[i])
            cnt++;

    cout << "Yes\n";
    cout << cnt << '\n';
    for (int i = 1; i <= pos; i++)
        if (!deny[i])
            cout << i << ' ';

    exit(0);
}

void knapsack() {
    int i, j;

    clean_up(dp[0]);
    dp[0][0] = mp(0, 0);

    sort(aux.begin(), aux.end());
    if (need == 0) recons(0);

    for (i = 0; i < aux.size(); i++) {
        auto act = aux[i];
        if (act.first > need) break;

        ss = i; dd = i + 1;
        clean_up(dp[dd]);

        for (j = 0; j <= need; j++)
            if (dp[ss][j].first != -1)
                dp[dd][j] = mp(0, 0);

        for (j = 0; j + act.first <= need; j++) {
            if (dp[ss][j].first == -1) continue;
            dp[dd][j + act.first] = act;
        }

        if (dp[dd][need].first != -1) recons(dd);
    }

    cout << "No";
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k;
    for (i = 1; i <= n; i++)
        for (j = 2 * i; j <= n; j += i)
            cnt[j]++;

    act = pos = 0;
    while (act < k) {
        if (++pos > n) {
            cout << "No";
            return 0;
        }

        act += cnt[pos];
    }

    need = act - k;
    for (i = pos; i * 2 > pos; i--) aux.pb(mp(cnt[i], i));

    knapsack();



    return 0;
}