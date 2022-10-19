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

int m;
char ans[30];
void kar()
{
    m = 0;
    char x;
    while (1)
    {
        x = getchar();
        if (x == '\n')
            break;
        ans[m++] = x;
    }
}

void solv()
{
    while (1)
    {
        printf("next 0\n");
        fflush(stdout);
        kar();
        printf("next 0 1\n");
        fflush(stdout);
        kar();
        if (ans[0] == '2')
            break;
    }
    while (1)
    {
        printf("next 0 1 2 3 4 5 6 7 8 9\n");
        fflush(stdout);
        kar();
        if (ans[0] == '1' && ans[1] == ' ')
            break;
    }
    printf("done\n");
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}