#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int n;
        scanf("%d", &n);
        if (n <= 2)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", (n / 2) - (n % 2 == 0));
    }
    return 0;
}