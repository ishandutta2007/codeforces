#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 300005;

int a, b;
int n;
char s[N];

bool solv()
{
    scanf("%d%d", &a, &b);
    scanf(" %s", s);
    n = strlen(s);
    int q = 0;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '.')
        {
            ++q;
        }
        else
        {
            v.push_back(q);
            q = 0;
        }
    }
    v.push_back(q);
    sort(all(v));
    reverse(all(v));

    while (!v.empty() && v.back() < b)
        v.pop_back();

    if (v.empty())
        return false;

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] >= b && v[i] < a)
            return false;
    }

    q = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] >= b * 2)
            ++q;
    }
    if (q >= 2)
        return false;
    else if (q == 0)
    {
        int qq = 0;
        if (v.size() % 2 == 1)
            return true;
        return false;
    }
    for (int l = 1; l + a - 1 <= v[0]; ++l)
    {
        int r = l + a - 1;

        int d1 = l - 1;
        int d2 = v[0] - r;

        if (d1 >= b && d1 < a)
            continue;
        if (d2 >= b && d2 < a)
            continue;

        if (d1 >= 2 * b)
            continue;
        if (d2 >= 2 * b)
            continue;

        int qq = v.size() - 1;
        if (d1 >= a)
            ++qq;
        if (d2 >= a)
            ++qq;

        if (qq % 2 == 0)
            return true;
    }
    return false;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}