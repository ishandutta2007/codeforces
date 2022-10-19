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

int qry(const vector<int> v)
{
    if (v.empty())
        return -1;
    printf("? %d", v.size());
    for (int i = 0; i < v.size(); ++i)
    {
        printf(" %d", v[i]);
    }
    printf("\n");
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int n, k;
vector<int> a[N];

int ans[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i)
        a[i].clear();
    for (int i = 1; i <= k; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    int maxu = qry(v);
    int l = 1, r = n;
    int maxi;
    while (l <= r)
    {
        int m = (l + r) / 2;
        vector<int> v;
        for (int i = 1; i <= m; ++i)
            v.push_back(i);
        if (qry(v) == maxu)
        {
            maxi = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    for (int i = 1; i <= k; ++i)
    {
        bool z = false;
        for (int j = 0; j < a[i].size(); ++j)
        {
            if (a[i][j] == maxi)
            {
                z = true;
                break;
            }
        }
        if (!z)
            ans[i] = maxu;
        else
        {
            vector<int> v;
            sort(all(a[i]));
            for (int j = 1; j <= n; ++j)
            {
                if (!binary_search(all(a[i]), j))
                    v.push_back(j);
            }
            ans[i] = qry(v);
        }
    }
    printf("! ");
    for (int i = 1; i <= k; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
    char comeonitscorrect[20];
    scanf(" %s", comeonitscorrect);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}