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

int n, i, j, fr, la;
pair<int, char> pos[maxN];
ll ans;

void add_full(char ch) {
    int fr, la;

    fr = la = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[i].second != ch) continue;
        if (fr == 0) fr = i;
        la = i;
    }

    if (fr == 0) return;
    ans += 1LL * (pos[la].first - pos[fr].first);
}

void add_all(int p1, int p2, char ch) {
    int fr, la;

    fr = la = 0;
    for (int i = p1; i <= p2; i++) {
        if (pos[i].second != ch && pos[i].second != 'G') continue;
        if (fr == 0) fr = i;
        la = i;
    }

    if (fr == 0) return;
    ans += 1LL * (pos[la].first - pos[fr].first);
}

int get_min(int p1, int p2, char ch) {
    int la = 0;
    int ans = 0;
    ll sum = 0;

    for (int i = p1; i <= p2; i++) {
        if (pos[i].second != 'G' && pos[i].second != ch) continue;
        if (la != 0) ans = max(ans, pos[i].first - pos[la].first), sum += pos[i].first - pos[la].first;
        la = i;
    }

    return sum - ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %c", &pos[i].first, &pos[i].second);
        if (pos[i].second == 'G') {
            if (fr == 0) fr = i;
            la = i;
        }
    }

    if (fr == 0) {
        add_full('R');
        add_full('B');
        printf("%lld", ans);
        return 0;
    }

    add_all(1, fr, 'R');
    add_all(1, fr, 'B');
    add_all(la, n, 'R');
    add_all(la, n, 'B');

    for (i = fr; i < la; i = j) {
        for (j = i + 1; pos[j].second != 'G'; j++);
        ans += min(2LL * (pos[j].first- pos[i].first),
                   1LL * (pos[j].first- pos[i].first) + get_min(i, j, 'R') + get_min(i, j, 'B') );
    }

    printf("%lld", ans);


    return 0;
}