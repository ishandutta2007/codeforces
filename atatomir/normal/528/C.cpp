#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 400011

int n, m, i, x, y;
vector< pair<int, int> > list[maxN];
bool us[maxN];
stack<int> S;
vector<int> ord;
int cnt[maxN];

vector<int> odd;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(mp(y, i));
        list[y].pb(mp(x, i));
        cnt[x]++; cnt[y]++;
    }

    for (i = 1; i <= n; i++) {
        if (cnt[i] & 1) {
            odd.pb(i);
        }
    }

    while (!odd.empty()) {
        x = odd.back(); odd.pop_back();
        y = odd.back(); odd.pop_back();
        m++;
        list[x].pb(mp(y, m));
        list[y].pb(mp(x, m));
    }

    if (m & 1)
        list[1].pb(mp(1, ++m));

    S.push(1);
    while (!S.empty()) {
        int node = S.top();
        bool found = false;

        for (i = 0; i < list[node].size(); i++) {
            if (us[list[node][i].second]) {
                list[node][i] = list[node].back();
                list[node].pop_back();
                i--;
                continue;
            }

            found = true;
            us[list[node][i].second] = true;
            S.push(list[node][i].first);
            break;
        }

        if (!found) {
            S.pop();
            ord.pb(node);
        }
    }

    printf("%d\n", m);
    for (i = 1; i < ord.size(); i++) {
        if (i & 1)
            printf("%d %d\n", ord[i - 1], ord[i]);
        else
            printf("%d %d\n", ord[i], ord[i - 1]);
    }


    return 0;
}