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

#define maxN 5011
#define maxVal 100011

const int def = 3;

int n, i, j;
int a[maxN];
vector<int> list[maxN];

vector<int> last_val[maxVal], last_mod[11];
int dp[maxN][maxN], dp2[maxN];
int ans;

void add_to(vector<int>& data, int v) {
    data.pb(v);
    if (data.size() > def) {
        for (int i = 1; i < data.size(); i++)
            data[i - 1] = data[i];
        data.pop_back();
    }
}

int main()
{
    //reopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (i = n; i > 0; i--) {
        //! lower value
        for (auto e : last_val[a[i] - 1]) {
            list[i].pb(e);
        }

        //! upper value
        for (auto e : last_val[a[i] + 1]) {
            list[i].pb(e);
        }

        add_to(last_val[a[i]], i);

        //! mod value
        int aux = a[i] % 7;
        for (auto e : last_mod[aux]) {
            list[i].pb(e);
        }
        add_to(last_mod[aux], i);
    }

    for (i = 1; i <= n; i++) {
        for (auto to : list[i]) {
            if (a[to] == a[i] - 1) continue;
            if (a[to] == a[i] + 1) continue;
            if (a[to] % 7 == a[i] % 7) continue;
            cerr << "error";
        }
    }

    for (i = n; i > 0; i--) {
        dp2[i] = 1;
        for (auto to : list[i])
            dp2[i] = max(dp2[i], 1 + dp2[to]);
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++) {
            dp[i][j] = max(2, dp[i][j]);
            ans = max(ans, dp[i][j] + dp2[i] - 1);

            for (auto to : list[j]) {
                if (to < i)
                    dp[i][to] = max(dp[i][to], dp[i][j] + 1);

                if (to > i)
                    dp[to][i] = max(dp[to][i], dp[i][j] + 1);
            }


        }
    }


    cout << ans;


    return 0;
}