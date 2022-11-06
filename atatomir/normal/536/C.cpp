#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

struct frac {
    ll a, b;

    bool operator<(const frac& who)const {
        return a * who.b < b * who.a;
    }

    bool operator==(frac x) {
        return b == x.b;
    }
};

struct point {
    frac x, y;
    int id;

    bool operator<(const point& who)const {
        return mp(x, y) < mp(who.x, who.y);
    }
};

int n, i, pos;
point v[maxN], st[maxN];
vector<int> ans;
map< pair<int, int>, vector<int> > M;

ll cross(point A, point B, point C) {
    ll Ax = A.x.b;
    ll Ay = A.y.b;
    ll Bx = B.x.b;
    ll By = B.y.b;
    ll Cx = C.x.b;
    ll Cy = C.y.b;

    return By * Cx * (Ax - Bx) * (Ay - Cy) - Bx * Cy * (Ay - By) * (Ax - Cx);
}

bool cmp(point A, point B) {
    return mp(A.y, A.x) < mp(B.y, B.x);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &v[i].x.b, &v[i].y.b);
        v[i].x.a = v[i].y.a = 1;
        v[i].id = i;

        M[mp(v[i].x.b, v[i].y.b)].pb(i);
    }

    sort(v + 1, v + n + 1);
    for (i = 1; i <= n; i++) {
        if (pos >= 1 && st[pos].x == v[i].x && st[pos].y == v[i].y) continue;
        while (pos >= 2) {
            ll aux = cross(st[pos - 1], st[pos], v[i]);
            if (aux >= 0) break;
            pos--;
        }
        st[++pos] = v[i];
    }

    int limit = min_element(st + 1, st + pos + 1, cmp)->id;
    while (st[pos].id != limit) pos--;

    for (i = 1; i <= pos; i++)
        for (auto e : M[mp(st[i].x.b, st[i].y.b)])
            ans.pb(e);

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    //printf("%d\n", ans.size());
    for (auto e : ans)
        printf("%d ", e);


    return 0;
}