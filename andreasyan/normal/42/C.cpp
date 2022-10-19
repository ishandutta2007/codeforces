#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int n = 4;

int x[n * 2];

void ubd(char ty, int i)
{
    printf("%c%d\n", ty, i);
    if (ty == '+')
    {
        ++x[i];
        ++x[i + 1];
    }
    else
    {
        x[i] /= 2;
        x[i + 1] /= 2;
    }
}

const int m = 20;
bool c[m][m][m][m];
pair<char, int> p[m][m][m][m];

void solv()
{
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    queue<vector<int> > q;
    c[1][1][1][1] = true;
    q.push({0, 1, 1, 1, 1});
    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        for (int i = 1; i <= n - 1; ++i)
        {
            vector<int> h = v;
            h[i] *= 2;
            h[i + 1] *= 2;
            if (h[i] < m && h[i + 1] < m)
            {
                if (!c[h[1]][h[2]][h[3]][h[4]])
                {
                    p[h[1]][h[2]][h[3]][h[4]] = m_p('/', i);
                    c[h[1]][h[2]][h[3]][h[4]] = true;
                    q.push(h);
                }
            }
            h = v;
            h[i]--;
            h[i + 1]--;
            if (h[i] >= 1 && h[i + 1] >= 1)
            {
                if (!c[h[1]][h[2]][h[3]][h[4]])
                {
                    p[h[1]][h[2]][h[3]][h[4]] = m_p('+', i);
                    c[h[1]][h[2]][h[3]][h[4]] = true;
                    q.push(h);
                }
            }
        }
    }
    while (1)
    {
        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            if (x[i] > 1)
            {
                z = false;
                break;
            }
        }
        if (z)
            return;
        if (x[1] < m && x[2] < m && x[3] < m && x[4] < m && c[x[1]][x[2]][x[3]][x[4]])
        {
            ubd(p[x[1]][x[2]][x[3]][x[4]].first, p[x[1]][x[2]][x[3]][x[4]].second);
            continue;
        }
        int maxu = -1;
        for (int i = 1; i <= n - 1; ++i)
        {
            if (x[i] % 2 == 0 && x[i + 1] % 2 == 0)
            {
                maxu = max(maxu, max(x[i], x[i + 1]));
            }
        }
        for (int i = 1; i <= n - 1; ++i)
        {
            if (x[i] % 2 == 0 && x[i + 1] % 2 == 0)
            {
                if (max(x[i], x[i + 1]) == maxu)
                {
                    ubd('/', i);
                    z = true;
                    break;
                }
            }
        }
        if (z)
            continue;
        for (int i = 1; i <= n - 1; ++i)
        {
            if (x[i] % 2 == 1 && x[i + 1] % 2 == 1)
            {
                maxu = max(maxu, max(x[i], x[i + 1]));
            }
        }
        for (int i = 1; i <= n - 1; ++i)
        {
            if (x[i] % 2 == 1 && x[i + 1] % 2 == 1 && maxu != 1)
            {
                if (maxu == max(x[i], x[i + 1]))
                {
                    ubd('+', i);
                    z = true;
                    break;
                }
            }
        }
        if (z)
            continue;
        ubd('+', 2);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}