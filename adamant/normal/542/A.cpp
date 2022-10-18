#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 42;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return (make_pair(a.second, a.first) > make_pair(b.second, b.first));
}

const int maxn = 4e5 + 7, logn = 33;
int L[maxn * logn], R[maxn * logn], mx[maxn * logn];
int num[maxn * logn];
int sz = 2;

int make(int &v)
{
    if(!v) v = sz++;
    return v;
}

void upd(int p, int x, int n, int v = 1, int l = 0, int r = inf)
{
    if(x >= mx[v])
        mx[v] = x,
        num[v] = n;
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    if(p < m)
        upd(p, x, n, make(L[v]), l, m);
    else
        upd(p, x, n, make(R[v]), m, r);
}

pair<int, int> get(int a, int b, int v = 1, int l = 0, int r = inf)
{
    if(a <= l && r <= b)
        return {mx[v], num[v]};
    if(r <= a || b <= l)
        return {-1, 0};
    int m = (l + r) / 2;
    return max(get(a, b, L[v], l, m), get(a, b, R[v], m, r));
}

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair<int, int> seg[n];
    for(int i = 0; i < n; i++)
        cin >> seg[i].first >> seg[i].second;
    int pl[n], pr[n], p[n];
    iota(pl, pl + n, 0);
    iota(pr, pr + n, 0);
    iota(p, p + n, 0);
    sort(pl, pl + n, [&](int a, int b){return seg[a] < seg[b];});
    sort(pr, pr + n, [&](int a, int b){return comp(seg[a], seg[b]);});
    tuple<int, int, int> que[m];
    for(int i = 0; i < m; i++)
        cin >> get<0>(que[i]) >> get<1>(que[i]) >> get<2>(que[i]);
    int pq[m];
    iota(pq, pq + m, 0);
    sort(pq, pq + m, [&](int a, int b){return get<1>(que[a]) < get<1>(que[b]);});
    sort(p, p + n, [&](int a, int b){return seg[a].second < seg[b].second;});
    int64_t ans = 0;
    int j = 0;
    int mxl[n], mxr[n], la[n], ra[n];
    mxl[0] = seg[pl[0]].second;
    la[0] = pl[0];
    mxr[0] = seg[pr[0]].first;
    ra[0] = pr[0];
    for(int i = 1; i < n; i++)
    {
        if(seg[pl[i]].second > mxl[i - 1])
            mxl[i] = seg[pl[i]].second,
            la[i] = pl[i];
        else
            mxl[i] = mxl[i - 1],
            la[i] = la[i - 1];

        if(seg[pr[i]].first < mxr[i - 1])
            mxr[i] = seg[pr[i]].first,
            ra[i] = pr[i];
        else
            mxr[i] = mxr[i - 1],
            ra[i] = ra[i - 1];
    }
    int A, B;
    for(int i = 0; i < m; i++)
    {
        int L = get<0>(que[pq[i]]), R = get<1>(que[pq[i]]), C = get<2>(que[pq[i]]);
        while(j < n && seg[p[j]].second <= R)
        {
            upd(seg[p[j]].first, seg[p[j]].second - seg[p[j]].first, p[j]);
            j++;
        }
        int len = R - L;
        int maxl = 0, maxr = 0;
        int lpos = lower_bound(pl, pl + n, make_pair(L + 1, 0), [&](int a, pair<int, int> b){return seg[a] < b;}) - pl;
        int rpos = lower_bound(pr, pr + n, make_pair(inf, R - 1), [&](int a, pair<int, int> b){return comp(seg[a], b);}) - pr;
        if(lpos)
            maxl = min(len, mxl[lpos - 1] - L);
        if(rpos)
            maxr = min(len, R - mxr[rpos - 1]);
        auto maxm = get(L, R + 1);
        if(1LL * maxl * C > ans)
        {
            ans = 1LL * maxl * C;
            A = la[lpos - 1];
            B = pq[i];
        }
        if(1LL * maxr * C > ans)
        {
            ans = 1LL * maxr * C;
            A = ra[rpos - 1];
            B = pq[i];
        }
        if(1LL * maxm.first * C > ans)
        {
            ans = 1LL * maxm.first * C;
            A = maxm.second;
            B = pq[i];
        }
    }
    if(!ans)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << ans << "\n";
    cout << A + 1 << ' ' << B + 1 << "\n";
}