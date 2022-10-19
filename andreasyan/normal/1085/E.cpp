#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int k, n;
char s[N], a[N], b[N];

char u[30];
bool c[30];

bool rec(int i, bool za, bool zb)
{
    if (i == n)
    {
        vector<char> v;
        for (int i = 0; i < k; ++i)
        {
            if (!c[i])
                v.push_back(i + 'a');
        }
        for (int i = 0; i < k; ++i)
        {
            if (!u[i])
            {
                u[i] = v.back();
                v.pop_back();
            }
        }
        printf("YES\n");
        printf("%s\n", u);
        return true;
    }
    if (u[s[i]])
    {
        bool yza, yzb;
        if (!za)
            yza = false;
        else
        {
            if (u[s[i]] < a[i])
                return false;
            if (u[s[i]] == a[i])
                yza = true;
            else
                yza = false;
        }
        if (!zb)
            yzb = false;
        else
        {
            if (u[s[i]] > b[i])
                return false;
            if (u[s[i]] == b[i])
                yzb = true;
            else
                yzb = false;
        }
        if (rec(i + 1, yza, yzb))
            return true;
        return false;
    }
    char l0 = 'a' - 1, r0 = 'a' + k;
    if (za)
        l0 = a[i];
    if (zb)
        r0 = b[i];
    for (char j = l0 + 1; j <= r0 - 1; ++j)
    {
        if (c[j - 'a'])
            continue;
        u[s[i]] = j;
        c[j - 'a'] = true;
        if (rec(i + 1, false, false))
            return true;
        u[s[i]] = 0;
        c[j - 'a'] = false;
    }
    if (za && !c[a[i] - 'a'])
    {
        u[s[i]] = a[i];
        c[a[i] - 'a'] = true;
        bool yza, yzb;
        if (!za)
            yza = false;
        else
        {
            if (u[s[i]] < a[i])
                return false;
            if (u[s[i]] == a[i])
                yza = true;
            else
                yza = false;
        }
        if (!zb)
            yzb = false;
        else
        {
            if (u[s[i]] > b[i])
                return false;
            if (u[s[i]] == b[i])
                yzb = true;
            else
                yzb = false;
        }
        if (rec(i + 1, yza, yzb))
            return true;
        u[s[i]] = 0;
        c[a[i] - 'a'] = false;
    }
    if (zb && !c[b[i] - 'a'])
    {
        u[s[i]] = b[i];
        c[b[i] - 'a'] = true;
        bool yza, yzb;
        if (!za)
            yza = false;
        else
        {
            if (u[s[i]] < a[i])
                return false;
            if (u[s[i]] == a[i])
                yza = true;
            else
                yza = false;
        }
        if (!zb)
            yzb = false;
        else
        {
            if (u[s[i]] > b[i])
                return false;
            if (u[s[i]] == b[i])
                yzb = true;
            else
                yzb = false;
        }
        if (rec(i + 1, yza, yzb))
            return true;
        u[s[i]] = 0;
        c[b[i] - 'a'] = false;
    }
    return false;
}

void solv()
{
    memset(u, 0, sizeof u);
    memset(c, false, sizeof c);
    scanf("%d", &k);
    scanf(" %s", s);
    scanf(" %s", a);
    scanf(" %s", b);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        s[i] -= 'a';
    if (!rec(0, true, true))
    {
        printf("NO\n");
        return;
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}