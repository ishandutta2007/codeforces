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

struct brick {
    ll w, tp;

    bool operator<(const brick& who)const {
        return w * who.tp > who.w * tp;
    }

    void operator+=(const brick& who) {
        w += who.w;
        tp += who.tp;
    }
};

int n, i;
ll m;
brick act;
vector<brick> one, two, three, one_two;
int sum[maxN];
ll ans;

ll check(ll limit, ll cnt) {
    cnt = max(cnt, 0LL);
    cnt = min(cnt, (ll)one.size() - 1);
    ll cnt_two = limit - cnt;
    if (limit - cnt < 0) return 0;
    cnt_two /= 2;

    cnt_two = min(cnt_two, (ll)two.size() - 1);
    return one[cnt].w + two[cnt_two].w;
}

ll get_best(ll limit) {
    auto cmp = [](const brick& a, const brick& b)->bool {
        return a.tp < b.tp;
    };
    int pos = upper_bound(one_two.begin(), one_two.end(), (brick){0, limit}, cmp) - one_two.begin() - 1;
    int cnt_one = sum[pos];

    return max(check(limit, cnt_one - 1), max(check(limit, cnt_one), check(limit, cnt_one + 1)));
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m;

    one.pb({0, 0});
    two.pb({0, 0});
    three.pb({0, 0});
    one_two.pb({0, 0});

    for (i = 1; i <= n; i++) {
        cin >> act.tp >> act.w;

        if (act.tp == 1) {
            one.pb(act);
            one_two.pb(act);
        }

        if (act.tp == 2) {
            two.pb(act);
            one_two.pb(act);
        }

        if (act.tp == 3) {
            three.pb(act);
        }
    }

    sort(one.begin() + 1, one.end());
    sort(two.begin() + 1, two.end());
    sort(three.begin() + 1, three.end());
    sort(one_two.begin() + 1, one_two.end());

    for (i = 1; i < one.size(); i++)
        one[i] += one[i - 1];

    for (i = 1; i < two.size(); i++)
        two[i] += two[i - 1];

    for (i = 1; i < three.size(); i++)
        three[i] += three[i - 1];

    for (i = 1; i < one_two.size(); i++)
        sum[i] = sum[i - 1] + (one_two[i].tp == 1), one_two[i] += one_two[i - 1];

    for (i = 0; i < three.size(); i++) {
        act = three[i];

        if (act.tp > m) break;
        ans = max(ans, act.w + get_best(m - act.tp));
    }

    cout << ans;


    return 0;
}