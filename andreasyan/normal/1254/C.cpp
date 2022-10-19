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
const int N = 1003;

ll qry(int ty, int x, int y, int z)
{
    printf("%d %d %d %d\n", ty, x, y, z);
    fflush(stdout);
    ll ans;
    scanf("%lld", &ans);
    return ans;
}

int n;
ll s[N];

bool so(int x, int y)
{
    return s[x] < s[y];
}

void solv()
{
    scanf("%d", &n);
    vector<int> l, r, ans;
    for (int i = 3; i <= n; ++i)
    {
        if (qry(2, 1, 2, i) < 0)
            r.push_back(i);
        else
            l.push_back(i);
    }
    for (int i = 3; i <= n; ++i)
        s[i] = qry(1, 1, 2, i);
    sort(r.begin(), r.end(), so);
    vector<int> r0, r1;
    for (int i = 0; i < sz(r) - 1; ++i)
    {
        if (qry(2, 1, r.back(), r[i]) < 0)
            r0.push_back(r[i]);
        else
            r1.push_back(r[i]);
    }
    if (!r.empty())
        r0.push_back(r.back());
    sort(l.begin(), l.end(), so);
    vector<int> l0, l1;
    for (int i = 0; i < sz(l) - 1; ++i)
    {
        if (qry(2, 2, l.back(), l[i]) < 0)
            l0.push_back(l[i]);
        else
            l1.push_back(l[i]);
    }
    if (!l.empty())
        l0.push_back(l.back());
    ans.push_back(1);
    for (int i = 0; i < r0.size(); ++i)
        ans.push_back(r0[i]);
    reverse(r1.begin(), r1.end());
    for (int i = 0; i < r1.size(); ++i)
        ans.push_back(r1[i]);
    ans.push_back(2);
    for (int i = 0; i < l0.size(); ++i)
        ans.push_back(l0[i]);
    reverse(l1.begin(), l1.end());
    for (int i = 0; i < l1.size(); ++i)
        ans.push_back(l1[i]);
    printf("0 ");
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}