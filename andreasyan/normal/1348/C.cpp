#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, k;
char a[N];
int q[26];

void solv()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", a);
    sort(a, a + n);
    if (k == 1)
    {
        printf("%s\n", a);
        return;
    }
    memset(q, 0, sizeof q);
    for (int i = 0; i < n; ++i)
    {
        q[a[i] - 'a']++;
    }
    int s;
    for (int i = 0; i < 26; ++i)
    {
        if (q[i])
        {
            s = i;
            break;
        }
    }
    if (q[s] < k)
    {
        putchar(a[k - 1]);
        putchar('\n');
        return;
    }
    int qq = 0;
    for (int i = s + 1; i < 26; ++i)
    {
        if (q[i])
            ++qq;
    }
    if (qq == 0)
    {
        for (int u = 0; u < q[s] / k; ++u)
            putchar(s + 'a');
        if (q[s] % k != 0)
            putchar('a' + s);
        putchar('\n');
        return;
    }
    if (qq == 1 && q[s] == k)
    {
        putchar(s + 'a');
        for (int i = s + 1; i < 26; ++i)
        {
            for (int j = 0; j < q[i] / k; ++j)
                putchar(i + 'a');
            if (q[i] % k != 0)
                putchar(i + 'a');
        }
        putchar('\n');
        return;
    }
    for (int i = 0; i < q[s] - (k - 1); ++i)
    {
        putchar(s + 'a');
    }
    for (int f = s + 1; f < 26; ++f)
    {
        for (int i = 0; i < q[f]; ++i)
            putchar(f + 'a');
    }
    putchar('\n');
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