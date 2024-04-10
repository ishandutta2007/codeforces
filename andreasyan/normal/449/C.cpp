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
const int N = 100005;

int n;

vector<pair<int, int> > ans;

vector<int> v;
bool c[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 3; i <= n; ++i)
    {
        if (i % 2 == 0)
            continue;
        if (c[i])
            continue;
        vector<int> vv;
        for (int j = i; j <= n; j += i)
        {
            if (c[j])
                continue;
            c[j] = true;
            vv.push_back(j);
        }
        if (vv.size() == 1)
            continue;
        if (vv.size() % 2 == 0)
        {
            for (int i = 0; i < vv.size(); i += 2)
                ans.push_back(m_p(vv[i], vv[i + 1]));
        }
        else
        {
            reverse(all(vv));
            vv.pop_back();
            v.push_back(vv.back());
            vv.pop_back();
            vv.push_back(i);
            for (int i = 0; i < vv.size(); i += 2)
                ans.push_back(m_p(vv[i], vv[i + 1]));
        }
    }
    for (int i = 2; i <= n; i += 2)
    {
        if (c[i])
            continue;
        c[i] = true;
        v.push_back(i);
    }
    if (v.size() % 2 == 1)
        v.pop_back();
    for (int i = 0; i < v.size(); i += 2)
        ans.push_back(m_p(v[i], v[i + 1]));
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}