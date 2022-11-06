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

struct rect {
    ll x1, y1, x2, y2;

    bool contains(rect who) {
        if (x1 <= who.x1 && who.x2 <= x2)
            if (y1 <= who.y1 && who.y2 <= y2)
                return true;
        return false;
    }
};

ll n, i;
rect found;
rect R1, R2;


int query(rect R) {
    printf("? %lld %lld %lld %lld\n", R.x1, R.y1, R.x2, R.y2);
    fflush(stdout);

    int ans;
    scanf("%d", &ans);

    if (R.contains(found))
        ans--;
    return ans;
}

ll bin_x(rect act) {
    ll ans = act.x1 - 1;

    for (int step = (1 << 16); step > 0; step >>= 1)
        if (ans + step <= act.x2)
            if (query({act.x1, act.y1, ans + step, act.y2}) == 0)
                ans += step;

    return ans + 1;
}

ll bin_rev_x(rect act) {
    ll ans = act.x2 + 1;

    for (int step = (1 << 16); step > 0; step >>= 1)
        if (ans - step >= act.x1)
            if (query({ans - step, act.y1, act.x2, act.y2}) == 0)
                ans -= step;

    return ans - 1;
}

ll bin_y(rect act) {
    ll ans = act.y1 - 1;

    for (int step = (1 << 16); step > 0; step >>= 1)
        if (ans + step <= act.y2)
            if (query({act.x1, act.y1, act.x2, ans + step}) == 0)
                ans += step;

    return ans + 1;
}

ll bin_rev_y(rect act) {
    ll ans = act.y2 + 1;

    for (int step = (1 << 16); step > 0; step >>= 1)
        if (ans - step >= act.y1)
            if (query({act.x1, ans - step, act.x2, act.y2}) == 0)
                ans -= step;

    return ans - 1;
}

rect find_rect() {
    rect act = {1, 1, n, n};

    act.x2 = bin_x(act);
    act.y2 = bin_y(act);

    act.x1 = bin_rev_x(act);
    act.y1 = bin_rev_y(act);

    return act;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    found = {0, 0, 0, 0};

    R1 = find_rect();
    found = R1;

    R2 = find_rect();

    printf("! %lld %lld %lld %lld %lld %lld %lld %lld\n", R1.x1, R1.y1, R1.x2, R1.y2,
                                                          R2.x1, R2.y1, R2.x2, R2.y2);
    fflush(stdout);


    return 0;
}