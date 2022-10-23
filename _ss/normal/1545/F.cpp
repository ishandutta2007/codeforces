#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 2e5 + 10, block_size = 500, N_block = 410;
struct query { int t, k, x;};
int a[3][N], b[N], c[N], n, q, m;
query Q[N];
int id[N_block][N], belong[N], sta[N], en[N], cnt_single[N];
ll ans[N], ans_block[N], cnt_pair[N];
vi cnt_0_before[N_block], cnt_1[N_block], cnt_2[N_block], val_list[N_block];
vll cnt_01_before[N_block], cnt_12[N_block];

void fake_update(int pos, int val)
{
    int bp = belong[pos];
    if (!id[bp][val])
    {
        id[bp][val] = cnt_1[bp].size();
        cnt_0_before[bp].eb(0);
        cnt_01_before[bp].eb(0);
        cnt_1[bp].eb(0);
        cnt_2[bp].eb(0);
        cnt_12[bp].eb(0);
        val_list[bp].eb(val);
    }
}

void build_block(int x)
{
    ans_block[x] = 0;
    for (int i = sta[x]; i <= en[x]; ++i)
    {
        int id0 = id[x][a[0][i]];
        int id1 = id[x][a[1][i]];
        int id2 = id[x][a[2][i]];
        ans[i] = cnt_01_before[x][id2] + cnt_pair[id2];
        cnt_pair[id1] += cnt_0_before[x][id1] + cnt_single[id1];
        cnt_single[id0]++;
        ans_block[x] += ans[i];
    }
    for (int i = sta[x]; i <= en[x]; ++i)
        cnt_pair[id[x][a[1][i]]] = cnt_single[id[x][a[0][i]]] = 0;
}

void add0(int pos, int val, int cof)
{
    int bp = belong[pos];
    int inc01 = 0;
    for (int i = pos + 1; i <= en[bp]; ++i)
        if (a[1][i] == val) inc01++;
    for (int i = bp + 1; i <= m; ++i)
        if (id[i][val])
        {
            int idv = id[i][val];
            cnt_0_before[i][idv] += cof;
            cnt_01_before[i][idv] += inc01 * cof;
            ans_block[i] += (cnt_12[i][idv] + (ll)inc01 * cnt_2[i][idv]) * cof;
            inc01 += cnt_1[i][idv];
        }
}

void add1(int pos, int val, int cof)
{
    int bp = belong[pos];
    int idv = id[bp][val];
    cnt_1[bp][idv] += cof;
    for (int i = pos + 1; i <= en[bp]; ++i)
        if (a[2][i] == val) cnt_12[bp][idv] += cof;
    int inc01 = cnt_0_before[bp][idv];
    for (int i = sta[bp]; i < pos; ++i)
        if (a[0][i] == val) inc01++;
    for (int i = bp + 1; i <= m; ++i)
        if (id[i][val])
        {
            idv = id[i][val];
            cnt_01_before[i][idv] += inc01 * cof;
            ans_block[i] += (ll)inc01 * cnt_2[i][idv] * cof;
        }
}

void add2(int pos, int val, int cof)
{
    int bp = belong[pos];
    int idv = id[bp][val];
    cnt_2[bp][idv] += cof;
    for (int i = sta[bp]; i < pos; ++i)
        if (a[1][i] == val) cnt_12[bp][idv] += cof;
}

void preprocess()
{
    for (int i = 1; i <= n; ++i) belong[i] = (i - 1) / block_size + 1;
    m = belong[n];
    for (int i = 1; i <= m; ++i)
    {
        sta[i] = (i - 1) * block_size + 1;
        en[i] = min(n, i * block_size);
        fake_update(sta[i], 0);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= 2; ++j) fake_update(i, a[j][i]);
    for (int i = 1; i <= q; ++i)
        if (Q[i].t == 1)
        {
            int x = Q[i].x;
            fake_update(Q[i].k, x);
            fake_update(Q[i].k, b[x]);
            fake_update(Q[i].k, c[x]);
        }
    for (int i = 1; i <= m; ++i)
    {
        for (int val : val_list[i])
        {
            int idv = id[i][val];
            cnt_0_before[i][idv] = cnt_single[val];
            cnt_01_before[i][idv] = cnt_pair[val];
        }
        for (int j = sta[i]; j <= en[i]; ++j)
        {
            ans[j] = cnt_pair[a[2][j]];
            ans_block[i] += ans[j];
            cnt_pair[a[1][j]] += cnt_single[a[1][j]];
            cnt_single[a[0][j]]++;
        }
    }
    for (int i = 1; i <= n; ++i) cnt_single[i] = cnt_pair[i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = sta[i]; j <= en[i]; ++j)
        {
            int id1 = id[i][a[1][j]];
            int id2 = id[i][a[2][j]];
            cnt_12[i][id2] += cnt_1[i][id2];
            cnt_1[i][id1]++;
            cnt_2[i][id2]++;
        }
    }
}

void update(int pos, int val)
{
    if (a[0][pos] != b[val]) add0(pos, a[0][pos], -1), add0(pos, b[val], 1);
    if (a[1][pos] != val) add1(pos, a[1][pos], -1), add1(pos, val, 1);
    if (a[2][pos] != c[val]) add2(pos, a[2][pos], -1), add2(pos, c[val], 1);
    a[0][pos] = b[val];
    a[1][pos] = val;
    a[2][pos] = c[val];
    build_block(belong[pos]);
}

ll get(int r)
{
    int br = belong[r];
    build_block(br);
    ll res = 0;
    for (int i = 1; i < br; ++i) res += ans_block[i];
    for (int i = sta[br]; i <= r; ++i) res += ans[i];
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[1][i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i)
    {
        a[0][i] = b[a[1][i]];
        a[2][i] = c[a[1][i]];
    }
    for (int i = 1, t, k, x; i <= q; ++i)
    {
        cin >> t >> k;
        if (t == 1) cin >> x, Q[i] = {t, k, x};
        else Q[i] = {t, k, 0};
    }
    preprocess();
    for (int i = 1; i <= q; ++i)
        if (Q[i].t == 1) update(Q[i].k, Q[i].x);
        else cout << get(Q[i].k) << "\n";
    return 0;
}