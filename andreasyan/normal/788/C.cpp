#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1003;

int n, k;
bool a[N];

bool c[N * 2];
int d[N * 2];
int bfs()
{
    queue<int> q;
    d[N] = 0;
    c[N] = true;
    q.push(N);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < N; ++i)
        {
            if (a[i])
            {
                int h = x + (i - n);
                if (h == N)
                    return d[x] + 1;
                if (0 <= h && h < N * 2 && !c[h])
                {
                    d[h] = d[x] + 1;
                    c[h] = true;
                    q.push(h);
                }
            }
        }
    }
    return -1;
}

void solv()
{
    scanf("%d%d", &n, &k);
    while (k--)
    {
        int x;
        scanf("%d", &x);
        a[x] = true;
    }
    printf("%d\n", bfs());
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