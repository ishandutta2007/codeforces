#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val, cnt[3];
};

const int MAXN = 400 * 1000 + 5, MOD[] = {740393153, 517293671, 841156751};
int h[MAXN], lval[MAXN], lcnt[MAXN][3], rval[MAXN], rcnt[MAXN][3],
    ans[MAXN], val, cnt[3];
Node st[4 * MAXN];
vector< pair<int, int> > q[MAXN];
vector<int> lans[MAXN], rans[MAXN], ch;

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[v].val = 0;
        for(int i = 0; i < 3; i++)
            st[v].cnt[i] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    if(st[2 * v].val > st[2 * v + 1].val) {
        st[v].val = st[2 * v].val;
        for(int i = 0; i < 3; i++)
            st[v].cnt[i] = st[2 * v].cnt[i];
    }
    else if(st[2 * v].val < st[2 * v + 1].val) {
        st[v].val = st[2 * v + 1].val;
        for(int i = 0; i < 3; i++)
            st[v].cnt[i] = st[2 * v + 1].cnt[i];
    }
    else {
        st[v].val = st[2 * v].val;
        for(int i = 0; i < 3; i++) {
            st[v].cnt[i] = st[2 * v].cnt[i] + st[2 * v + 1].cnt[i];
            if(st[v].cnt[i] >= MOD[i])
                st[v].cnt[i] -= MOD[i];
        }
    }
}

void get(int v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r) {
        if(val < st[v].val) {
            val = st[v].val;
            for(int i = 0; i < 3; i++)
                cnt[i] = st[v].cnt[i];
        }
        else if(val == st[v].val)
            for(int i = 0; i < 3; i++) {
                cnt[i] += st[v].cnt[i];
                if(cnt[i] >= MOD[i])
                    cnt[i] -= MOD[i];
            }
        return;
    }
    int tm = (tl + tr) / 2;
    if(l < tm)
        get(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        get(2 * v + 1, tm, tr, max(l, tm), r);
}

void update(int v, int tl, int tr, int pos) {
    if(tl == tr - 1) {
        if(val > st[v].val) {
            st[v].val = val;
            for(int i = 0; i < 3; i++)
                st[v].cnt[i] = cnt[i];
        }
        else if(val == st[v].val)
            for(int i = 0; i < 3; i++) {
                st[v].cnt[i] += cnt[i];
                if(st[v].cnt[i] >= MOD[i])
                    st[v].cnt[i] -= MOD[i];
            }
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos < tm)
        update(2 * v, tl, tm, pos);
    else
        update(2 * v + 1, tm, tr, pos);
    if(st[2 * v].val > st[2 * v + 1].val) {
        st[v].val = st[2 * v].val;
        for(int i = 0; i < 3; i++)
            st[v].cnt[i] = st[2 * v].cnt[i];
    }
    else if(st[2 * v].val < st[2 * v + 1].val) {
        st[v].val = st[2 * v + 1].val;
        for(int i = 0; i < 3; i++)
            st[v].cnt[i] = st[2 * v + 1].cnt[i];
    }
    else {
        st[v].val = st[2 * v].val;
        for(int i = 0; i < 3; i++) {
            st[v].cnt[i] = st[2 * v].cnt[i] + st[2 * v + 1].cnt[i];
            if(st[v].cnt[i] >= MOD[i])
                st[v].cnt[i] -= MOD[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ch.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        ch[i] = h[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        q[a].push_back(make_pair(b, i));
    }
    sort(ch.begin(), ch.end());
    ch.erase(unique(ch.begin(), ch.end()), ch.end());
    for(int i = 0; i < n; i++)
        h[i] = lower_bound(ch.begin(), ch.end(), h[i]) - ch.begin();
    buildst(1, 0, ch.size());
    int allval = 0, allcnt[] = {0, 0, 0};
    for(int i = 0; i < n; i++) {
        lans[i].resize(q[i].size());
        for(size_t j = 0; j < q[i].size(); j++) {
            val = 0;
            for(int k = 0; k < 3; k++)
                cnt[k] = 0;
            int b = lower_bound(ch.begin(), ch.end(), q[i][j].first) - ch.begin();
            if(b != 0)
                get(1, 0, ch.size(), 0, b);
            lans[i][j] = val;
        }
        val = 0;
        for(int j = 0; j < 3; j++)
            cnt[j] = 0;
        if(h[i] != 0)
            get(1, 0, ch.size(), 0, h[i]);
        if(val == 0)
            for(int j = 0; j < 3; j++)
                cnt[j] = 1;
        lval[i] = val;
        for(int j = 0; j < 3; j++)
            lcnt[i][j] = cnt[j];
        val++;
        update(1, 0, ch.size(), h[i]);
        if(val > allval) {
            allval = val;
            for(int j = 0; j < 3; j++)
                allcnt[j] = cnt[j];
        }
        else if(val == allval)
            for(int j = 0; j < 3; j++) {
                allcnt[j] += cnt[j];
                if(allcnt[j] >= MOD[j])
                    allcnt[j] -= MOD[j];
            }
    }
    buildst(1, 0, ch.size());
    for(int i = n - 1; i >= 0; i--) {
        rans[i].resize(q[i].size());
        for(size_t j = 0; j < q[i].size(); j++) {
            val = 0;
            for(int k = 0; k < 3; k++)
                cnt[k] = 0;
            int b = upper_bound(ch.begin(), ch.end(), q[i][j].first) - ch.begin();
            if(b != (int)ch.size())
                get(1, 0, ch.size(), b, ch.size());
            rans[i][j] = val;
        }
        val = 0;
        for(int j = 0; j < 3; j++)
            cnt[j] = 0;
        if(h[i] + 1 != (int)ch.size())
            get(1, 0, ch.size(), h[i] + 1, ch.size());
        if(val == 0)
            for(int j = 0; j < 3; j++)
                cnt[j] = 1;
        rval[i] = val;
        for(int j = 0; j < 3; j++)
            rcnt[i][j] = cnt[j];
        val++;
        update(1, 0, ch.size(), h[i]);
    }
    for(int i = 0; i < n; i++) {
        bool ok = false;
        if(lval[i] + rval[i] + 1 != allval)
            ok = true;
        else
            for(int j = 0; j < 3; j++) {
                int lrcnt = (long long)lcnt[i][j] * rcnt[i][j] % MOD[j];
                if(lrcnt != allcnt[j])
                    ok = true;
            }
        for(size_t j = 0; j < q[i].size(); j++) {
            ans[q[i][j].second] = lans[i][j] + rans[i][j] + 1;
            if(ok)
                ans[q[i][j].second] = max(ans[q[i][j].second], allval);
            else
                ans[q[i][j].second] = max(ans[q[i][j].second], allval - 1);
        }
    }
    for(int i = 0; i < m; i++)
        cout << ans[i] << '\n';
    return 0;
}