#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, INF = 1000000009;

int n;
int l[N], r[N], c[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i] >> c[i];

    int l0 = INF, r0 = -INF;

    map<int, int> lm, rm;
    map<pair<int, int>, int> lrm;
    for (int i = 1; i <= n; ++i)
    {
        l0 = min(l0, l[i]);
        r0 = max(r0, r[i]);

        if (lm.find(l[i]) == lm.end())
            lm[l[i]] = c[i];
        else
            lm[l[i]] = min(lm[l[i]], c[i]);

        if (rm.find(r[i]) == rm.end())
            rm[r[i]] = c[i];
        else
            rm[r[i]] = min(rm[r[i]], c[i]);

        if (lrm.find(m_p(l[i], r[i])) == lrm.end())
            lrm[m_p(l[i], r[i])] = c[i];
        else
            lrm[m_p(l[i], r[i])] = min(lrm[m_p(l[i], r[i])], c[i]);

        int ans = lm[l0] + rm[r0];
        if (lrm.find(m_p(l0, r0)) != lrm.end())
            ans = min(ans, lrm[m_p(l0, r0)]);

        cout << ans << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}