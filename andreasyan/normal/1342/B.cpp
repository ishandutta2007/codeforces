#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;

int n;
char a[N];

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    bool z = true;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != a[0])
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        printf("%s\n", a);
        return;
    }
    for (int i = 0; i < n; ++i)
        printf("01");
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