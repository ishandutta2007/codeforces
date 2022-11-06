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

#define maxN 200011

int n, m, i, a, b, w;
vector< pair<int, pair<int, int> > > ord;

int dad[maxN];
int cnt[maxN];
int ans;

int Find(int x) {
    if (dad[x] == x) return x;
    dad[x] = Find(dad[x]);
    return dad[x];
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        ord.pb(mp(w, mp(a, b)));
    }

    for (i = 1; i <= n; i++) {
        dad[i] = i;
        cnt[i] = 1;
    }

    sort(ord.begin(), ord.end());
    reverse(ord.begin(), ord.end());

    for (auto e : ord) {
        a = e.second.first;
        b = e.second.second;

        a = Find(a);
        b = Find(b);

        if (a == b) {
            if (cnt[a] > 0) {
                cnt[a]--;
                ans += e.first;
            }
        } else {
            if (cnt[a] + cnt[b] > 0) {
                dad[a] = b;
                cnt[b] += cnt[a];
                cnt[b]--;
                ans += e.first;
            }
        }
    }

    cout << ans;


    return 0;
}