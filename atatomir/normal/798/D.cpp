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

struct op {
    int x, y;
    int id;

    bool operator<(const op& who)const {
        return mp(x, y) < mp(who.x, who.y);
    }

    bool operator<=(const op& who)const {
        return mp(x, y) <= mp(who.x, who.y);
    }
};

int n, i;
op P[maxN];
vector<op> S;
vector<int> ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &P[i].x), P[i].id = i;
    for (i = 1; i <= n; i++) scanf("%d", &P[i].y);

    sort(P + 1, P + n + 1);
    for (i = 1; i <= n; i++) {
        if (!S.empty()) {
            if (S.back().y <= P[i].y) {
                S.pop_back();
                ans.pb(P[i].id);
                continue;
            }
        }

        S.pb(P[i]);
    }

    for (i = 0; i < S.size(); i += 2)
        ans.pb(S[i].id);

    if (S.size() >= 2 && S.size() % 2 == 0)
        ans.pb(S.back().id);

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto e : ans) printf("%d ", e);


    return 0;
}