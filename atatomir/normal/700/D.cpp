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

int sqrt_dim;

struct query {
    int l, r, id;

    void read(int _id) {
        scanf("%d%d", &l, &r);
        id = _id;
    }

    bool operator<(const query& who)const {
        return mp(l / sqrt_dim, r) < mp(who.l / sqrt_dim, who.r);
    }
};

struct myque {
    int l, r;
    vector< pair<int, int> > data;

    void init() {
        l = 1; r = 0;
        data.resize(maxN * 3);
    }
};



int n, m, i;
int v[maxN];
query Q[maxN];
int ans[maxN];

int l, r; // index
int fr[maxN]; // freq of every element
int cnt[maxN]; // count of any freq
vector<int> act; // valid freq
bool in_act[maxN]; // checking if value is in act

myque q1, q2;



void rm_elem(int val) {
    cnt[fr[val]]--;

    if (--fr[val] == 0) return;
    if(++cnt[fr[val]] == 1) {
        if (!in_act[fr[val]]) {
            act.pb(fr[val]);
            in_act[fr[val]] = true;
        }
    }
}

void add_elem(int val) {
    cnt[fr[val]]--;

    fr[val]++;
    if(++cnt[fr[val]] == 1) {
        if (!in_act[fr[val]]) {
            act.pb(fr[val]);
            in_act[fr[val]] = true;
        }
    }
}

void clean_act() {
    int i;

    for (i = 0; i < act.size(); i++) {
        int e = act[i];

        if (cnt[e] > 0) continue;

        in_act[e] = false;
        swap(act[i], act.back());
        act.pop_back();
        i--;
    }
}

pair<int, int> extract_min() {
    if (q1.l > q1.r)
        return q2.data[q2.l++];
    if (q2.l > q2.r)
        return q1.data[q1.l++];

    if (q1.data[q1.l] < q2.data[q2.l])
        return q1.data[q1.l++];
    else
        return q2.data[q2.l++];
}

void add_to_front(pair<int, int> now) {
    if (q1.l > 1 && (q1.l > q1.r || now.first <= q1.data[q1.l].first))
        q1.data[--q1.l] = now;
    else
        q2.data[--q2.l] = now;
}

int solve() {
    int i;
    int ans = 0;

    q1.init();
    q2.init();

    clean_act();
    sort(act.begin(), act.end());
    for (auto e : act)
        q1.data[ ++q1.r ] = mp(e, cnt[e]);

    if (act.size() == 1 && cnt[act[0]] == 1) return 0;

    while (q1.l <= q1.r || q2.l < q2.r || (q2.l == q2.r && q2.data[q2.l].second > 1)) {
        auto now = extract_min();
        auto to_push = now;

        if (now.second > 1) {
            // from the same group
            to_push = mp(now.first * 2, now.second / 2);

            now.second %= 2;
            if (now.second == 1)
                add_to_front(now);
        } else {
            // from different groups
            auto p2 = extract_min();

            to_push = {now.first + p2.first, 1};
            if (--p2.second > 0)
                add_to_front(p2);
        }

        ans += to_push.first * to_push.second;
        if (q2.l <= q2.r && q2.data[q2.r].first == to_push.first)
            q2.data[q2.r].second += to_push.second;
        else
            q2.data[++q2.r] = to_push;
    }

    return ans;
};


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    sqrt_dim = sqrt(n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    scanf("%d", &m);
    for (i = 1; i <= m; i++) Q[i].read(i);
    sort(Q + 1, Q + m + 1);

    l = 1; r = 0;
    for (int step = 1; step <= m; step++) {
        int qL = Q[step].l;
        int qR = Q[step].r;

        while (r < qR) add_elem(v[++r]);
        while (r > qR) rm_elem(v[r--]);

        while (l < qL) rm_elem(v[l++]);
        while (l > qL) add_elem(v[--l]);

        ans[Q[step].id] = solve();
    }

    for (i = 1; i <= m; i++)
        printf("%d\n", ans[i]);


    return 0;
}