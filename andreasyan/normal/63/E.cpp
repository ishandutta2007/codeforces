#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 22;
vector<vector<int> > v =
{{0, 1, 2}, {3, 4, 5, 6}, {7, 8, 9, 10, 11}, {12, 13, 14, 15}, {16, 17, 18},
 {0, 3, 7}, {1, 4, 8, 12}, {2, 5, 9, 13, 16}, {6, 10, 14, 17}, {11, 15, 18},
 {7, 12, 16}, {3, 8, 13, 17}, {0, 4, 9, 14, 18}, {1, 5, 10, 15}, {2, 6, 11}};

bool dp[1 << N];
void solv()
{
    vector<int> u;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = 0;
            for (int k = j; k < v[i].size(); ++k)
            {
                x |= (1 << v[i][k]);
                u.push_back(x);
            }
        }
    }
    for (int x = 0; x < (1 << 19); ++x)
    {
        for (int i = 0; i < u.size(); ++i)
        {
            int y = u[i];
            if ((x & y) == y)
            {
                if (!dp[(x ^ y)])
                {
                    dp[x] = true;
                    break;
                }
            }
        }
    }
    int x = 0;
    for (int i = 0; i < 19; ++i)
    {
        char u;
        scanf(" %c", &u);
        if (u == 'O')
            x |= (1 << i);
    }
    if (dp[x])
        printf("Karlsson\n");
    else
        printf("Lillebror\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}