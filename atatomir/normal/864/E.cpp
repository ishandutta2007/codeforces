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

#define maxN 111
#define maxD 2017

const int def = 2000;

struct teddy_bear {
    int t, d, p;
    int id;

    bool operator<(const teddy_bear& who)const {
        return d < who.d;
    }
};

int n, i, j, best;
teddy_bear ord[maxN];
int dp[maxN][maxD], prov[maxN][maxD];

void recons(int best) {
    int i;
    vector<int> bears = {};

    cout << dp[n][best] << '\n';
    for (i = n; i > 0; i--) {
        if (prov[i][best]) {
            bears.pb(ord[i].id);
            best -= ord[i].t;
        } else {
            //! sleeeeeep....
        }
    }

    reverse(bears.begin(), bears.end());
    cout << bears.size() << '\n';
    for (auto e : bears) cout << e << ' ';
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> ord[i].t >> ord[i].d >> ord[i].p;
        ord[i].id = i;
    }

    sort(ord + 1, ord + n + 1);

    for (i = 1; i <= def; i++) dp[0][i] = -(1 << 30);
    for (i = 1; i <= n; i++) {
        memcpy(dp[i], dp[i -1], sizeof(dp[i]));
        for (j = 0; j <= 2000; j++) prov[i][j] = 0;

        for (j = 0; j + ord[i].t < ord[i].d; j++) {
            if (dp[i][j + ord[i].t] < dp[i - 1][j] + ord[i].p) {
                dp[i][j + ord[i].t] = dp[i - 1][j] + ord[i].p;
                prov[i][j + ord[i].t] = 1;
            }
        }
    }

    best = 0;
    for (i = 1; i <= def; i++)
        if (dp[n][i] > dp[n][best])
            best = i;

    recons(best);



    return 0;
}