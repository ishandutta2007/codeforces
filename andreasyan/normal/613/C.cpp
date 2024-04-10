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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[26];

int m;
char s[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        q += (a[i] % 2);
    }
    if (q > 1)
    {
        printf("0\n");
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < a[i]; ++j)
                printf("%c", i + 'a');
        }
        printf("\n");
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = gcd(ans, a[i]);
    printf("%d\n", ans);
    if (q % 2 == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < a[i] / ans; ++j)
            {
                s[m++] = i + 'a';
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j < a[i] / ans; ++j)
            {
                s[m++] = i + 'a';
            }
        }
        for (int i = 0; i < ans / 2; ++i)
            printf("%s", s);
        printf("\n");
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (a[i] % 2 == 1)
                continue;
            for (int j = 0; j < a[i] / ans / 2; ++j)
            {
                s[m++] = i + 'a';
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (a[i] % 2 == 0)
                continue;
            for (int j = 0; j < a[i] / ans; ++j)
            {
                s[m++] = i + 'a';
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] % 2 == 1)
                continue;
            for (int j = 0; j < a[i] / ans / 2; ++j)
            {
                s[m++] = i + 'a';
            }
        }
        for (int i = 0; i < ans; ++i)
            printf("%s", s);
        printf("\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}