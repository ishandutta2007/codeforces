#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 10004;
char ss[4][20] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

int n;
char a[N];

vector<vector<int> > u[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    u[0].push_back({0, 0, 0, 0});
    for (int i = 0; i < n; ++i)
    {
        sort(u[i].begin(), u[i].end());
        vector<vector<int> > vv;
        for (int j = 0; j < u[i].size(); ++j)
        {
            if (!j || u[i][j] != u[i][j - 1])
                vv.push_back(u[i][j]);
        }
        u[i] = vv;
        for (int j = 0; j < u[i].size(); ++j)
        {
            int minu = N;
            for (int k = 0; k < 4; ++k)
                minu = min(minu, u[i][j][k]);
            if (a[i + 1] == '?')
            {
                for (int k = 0; k < 4; ++k)
                {
                    if (minu == u[i][j][k])
                    {
                        vector<int> v = u[i][j];
                        v[k]++;
                        u[i + 1].push_back(v);
                    }
                }
            }
            else
            {
                vector<int> v = u[i][j];
                for (int k = 0; k < 4; ++k)
                {
                    if (ss[k][0] == a[i + 1])
                        ++v[k];
                }
                u[i + 1].push_back(v);
            }
        }
    }
    bool z[4] = {};
    for (int j = 0; j < u[n].size(); ++j)
    {
        int minu = N;
        for (int k = 0; k < 4; ++k)
            minu = min(minu, u[n][j][k]);
        for (int k = 0; k < 4; ++k)
        {
            if (minu == u[n][j][k])
                z[k] = true;
        }
    }
    for (int k = 0; k < 4; ++k)
    {
        if (z[k])
            printf("%s\n", ss[k]);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}