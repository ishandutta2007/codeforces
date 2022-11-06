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

#define maxN 100011
#define lSon (node << 1)
#define rSon (lSon | 1)
#define maxBuck 93

struct state {
    int le, ri, best, cnt;
};

state combine(state A, state B) {
    state ans = {0, 0, 0};
    ans.best = max(max(A.best, B.best), A.ri + B.le);
    ans.le = A.le;
    ans.ri = B.ri;
    ans.cnt = A.cnt + B.cnt;

    if (A.le == A.cnt) ans.le = A.le + B.le;
    if (B.ri == B.cnt) ans.ri = A.ri + B.ri;
    return ans;
}

struct aint {
    int dim, *from;
    state data[262144 + 11];

    void build(int node, int l, int r) {
        if (l == r) {
            data[node].le = data[node].ri = data[node].best = from[l];
            data[node].cnt = 1;
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);
        data[node] = combine(data[lSon], data[rSon]);
    }

    void init(int _dim, int *_from) {
        dim = _dim;
        from = _from;
        build(1, 1, dim);
    }

    void upd(int node, int l, int r, int pos, int val) {
        if (l == r) {
            data[node].le = data[node].ri = data[node].best = val;
            data[node].cnt = 1;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd(lSon, l, mid, pos, val);
        if (pos > mid)
            upd(rSon, mid + 1, r, pos, val);

        data[node] = combine(data[lSon], data[rSon]);
    }

    state que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];

        state ans = {0, 0, 0};
        int mid = (l + r) >> 1;

        if (qL <= mid)
            ans = que(lSon, l, mid, qL, qR);
        if (qR > mid)
            ans = combine(ans, que(rSon, mid + 1, r, qL, qR));

        return ans;
    }
};

struct aint_max {
    int dim;
    int data[4 * maxN + 11];

    void init(int _dim) {
        dim = _dim;
    }

    void upd(int node, int l, int r, int pos, int v) {
        if (l == r) {
            data[node] = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd(lSon, l, mid, pos, v);
        if (pos > mid)
            upd(rSon, mid + 1, r, pos, v);

        data[node] = max(data[lSon], data[rSon]);
    }

    int que(int node, int l, int r, int qL, int qR) {
        int ans = 0;

        if (qL <= l && r <= qR)
            return data[node];

        int mid = (l + r) >> 1;
        if (qL <= mid)
            ans = max(ans, que(lSon, l, mid, qL, qR));
        if (qR > mid)
            ans = max(ans, que(rSon, mid + 1, r, qL, qR));

        return ans;
    }
};

int n, q, i, j, buck, op, a, b, x;
string s[maxN], y;

int lcp[maxN], cont;
aint small[maxBuck];
aint_max max_intr;

int aux[maxN];
vector<int> bigs;
ll ans;

vector< pair<ll, int> > work;
ll l[maxN], r[maxN];
stack< pair<ll, int> > S;


int get_lcp(const string& a, const string& b) {
    int i;

    for (i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i])
            break;
    }

    return i;
}

void rm_big(int val) {
    for (int i = 0; i < bigs.size(); i++) {
        if (bigs[i] != val) continue;
        for (j = i; j + 1 < bigs.size(); j++)
            bigs[j] = bigs[j + 1];
        bigs.pop_back();
        return;
    }
}

void add_big(int val) {
    int i, pos;

    for (pos = 0; pos < bigs.size(); pos++)
        if (bigs[pos] > val)
            break;

    bigs.pb(0);
    for (i = bigs.size() - 2; i >= pos; i--)
        bigs[i + 1] = bigs[i];

    bigs[pos] = val;
}

ll brute(int a, int b) {
    int i;

    if (bigs.empty()) return 0;

    work.clear();
    for (i = 0; i < bigs.size(); i++)
        if (bigs[i] >= a) break;

    if (i == bigs.size())
        return 0;

    work.pb(mp(0, bigs[i] - 1));

    for (; i < bigs.size(); i++) {
        if (bigs[i] > b) break;

        work.pb( mp(lcp[bigs[i]], bigs[i]));
        if (i + 1 != bigs.size()) {
            if (bigs[i + 1] - bigs[i] != 1) {
                work.pb(mp(0, bigs[i] + 1));
                work.pb(mp(0, bigs[i + 1] - 1));
            }
        }
    }

    work.pb(mp(0, work.back().second + 1));

    //! compute from left
    while (!S.empty()) S.pop();
    S.push(mp(-1, a - 1));
    i = 0;

    for (auto e : work) {
        while (S.top().first >= e.first)
            S.pop();

        l[i] = S.top().second;
        S.push(e);
        i++;
    }

    //! compute from right
    while (!S.empty()) S.pop();
    reverse(work.begin(), work.end());
    S.push(mp(-1, b + 1));
    i = work.size() - 1;

    for (auto e : work) {
        while (S.top().first >= e.first)
            S.pop();

        r[i] = S.top().second;
        S.push(e);
        i--;
    }

    //! conclusions
    ll ans = 0;

    reverse(work.begin(), work.end());
    for (i = 0; i < work.size(); i++)
        ans = max(ans, work[i].first * (r[i] - l[i]));

    return ans;
}


ll brute2(int a, int b) {
    int i;

    if (bigs.empty()) return 0;

    work.clear();
    for (i = a; i <= b; i++) work.pb(mp(lcp[i], i));

    //! compute from left
    while (!S.empty()) S.pop();
    S.push(mp(-1, a - 1));
    i = 0;

    for (auto e : work) {
        while (S.top().first >= e.first)
            S.pop();

        l[i] = S.top().second;
        S.push(e);
        i++;
    }

    //! compute from right
    while (!S.empty()) S.pop();
    reverse(work.begin(), work.end());
    S.push(mp(-1, b + 1));
    i = work.size() - 1;

    for (auto e : work) {
        while (S.top().first >= e.first)
            S.pop();

        r[i] = S.top().second;
        S.push(e);
        i--;
    }

    //! conclusions
    ll ans = 0;

    reverse(work.begin(), work.end());
    for (i = 0; i < work.size(); i++)
        ans = max(ans, work[i].first * (r[i] - l[i]));

    return ans;
}


int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> q;
    for (i = 1; i <= n; i++) cin >> s[i];
    s[n + 1] = "@";

    buck = 1 + sqrt(1.00 * maxN / (1 + log2(1.00 * maxN)));
    buck -= buck / 5;

    //! compute initial state

    max_intr.init(n);
    for (i = 1; i <= n; i++)
        max_intr.upd(1, 1, n, i, s[i].size());

    for (i = 1; i <= n; i++)
        lcp[i] = get_lcp(s[i], s[i + 1]);

    for (i = 1; i <= buck; i++) {
        for (j = 1; j <= n; j++)
            aux[j] = (lcp[j] >= i ? 1 : 0);

        small[i].init(n, aux);
    }

    for (i = 1; i <= n; i++)
        if (lcp[i] > buck)
            bigs.pb(i);

    for (int qq = 1; qq <= q; qq++) {
        cin >> op;

        if (op == 1) {
            cin >> a >> b;
            cont++;

            ans = max_intr.que(1, 1, n, a, b);

            if (a == b) {
                cout << ans << '\n';
                continue;
            }

            for (i = 1; i <= buck; i++) {
                ll auxi = small[i].que(1, 1, n, a, b - 1).best;
                if (auxi == 0) continue;
                ans = max(ans, 1LL * i * (auxi + 1));
            }

            ans = max(ans, brute(a, b - 1));

            cout << ans << '\n';
            /*if (cont == 995 && ans == 360) {
                bigs.clear();
                for (i = 1; i <= n; i++)
                    if (lcp[i] > buck)
                        bigs.pb(i);

                exit(brute(a, b - 1));
            }*/
        } else {
            cin >> x >> y;
            s[x] = y;
            if (x != 1) lcp[x - 1] = get_lcp(s[x - 1], s[x]);
            lcp[x] = get_lcp(s[x], s[x + 1]);

            max_intr.upd(1, 1, n, x, y.size());

            //! change small
            for (i = 1; i <= buck; i++) {
                if (x != 1) small[i].upd(1, 1, n, x - 1, (lcp[x - 1] >= i ? 1 : 0));
                small[i].upd(1, 1, n, x, (lcp[x] >= i ? 1 : 0));
            }

            //! change big
            rm_big(x - 1);
            rm_big(x);
            if (x != 1 && lcp[x - 1] > buck) add_big(x - 1);
            if (lcp[x] > buck) add_big(x);
        }
    }



    return 0;
}