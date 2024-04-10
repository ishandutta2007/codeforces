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

void solv()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> ans;
    bitset<1003> u;
    u[0] = 1;
    for (int i = n; i >= 1; --i)
    {
        if ((u | (u << i))[k])
            continue;
        ans.push_back(i);
        u = (u | (u << i));
    }

    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}