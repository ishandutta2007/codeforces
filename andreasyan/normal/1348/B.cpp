#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 104;

int n, k;
int a[N];

void solv()
{
    scanf("%d%d", &n, &k);
    set<int> s;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    if (s.size() > k)
    {
        printf("-1\n");
        return;
    }
    int i = 0;
    while (s.size() < k)
    {
        s.insert(++i);
    }
    printf("%d\n", n * s.size());
    for (int i = 1; i <= n; ++i)
    {
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        {
            printf("%d ", *it);
        }
    }
    printf("\n");
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