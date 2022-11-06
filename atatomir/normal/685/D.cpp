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

#define maxN 100011
#define inf 2000000000

int n, k, i, j, id, p1, p2, dif;
pair<int, int> P[maxN];
vector< pair<int, int> > E;
ll ans[maxN];

vector<int> xx;
vector<int> last, val;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);

    for (i = 1; i <= n; i++) {
        scanf("%d%d", &P[i].first, &P[i].second);
        E.pb(mp(P[i].second, +i));
        E.pb(mp(P[i].second + k, -i));

        xx.pb(P[i].first);
        xx.pb(P[i].first + k);
    }

    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());

    val.resize(xx.size());
    last.resize(xx.size());

    sort(E.begin(), E.end());
    for (auto e : E) {
        id = abs(e.second);
        p1 = P[id].first;
        p2 = P[id].first + k;

        p1 = lower_bound(xx.begin(), xx.end(), p1)- xx.begin();
        p2 = lower_bound(xx.begin(), xx.end(), p2)- xx.begin();
        dif = (e.second > 0 ? +1 : -1);

        for (i = p1; i < p2; i++) {
            ans[ val[i] ] += 1LL * (xx[i + 1] - xx[i]) * (e.first - last[i]);

            last[i] = e.first;
            val[i] += dif;
        }
    }


    for (i = 1; i <= n; i++) printf("%lld ", ans[i]);

    return 0;
}