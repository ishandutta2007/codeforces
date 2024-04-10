#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


const int MAXN = 111;

int a[MAXN], d[MAXN];
bool f[MAXN];
int A[MAXN], I[MAXN];
int n, m;
queue <int> q;

int add(int x)
{
    if (f[x]) return 0;
    f[x] = true;
    A[m] = a[x];
    I[m] = x;
    m++;
    q.push(x);
    return 0;
}        

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);

    for (int i = 1; i <= n; i++)
        if (f[i] == false)
        {
            int x = i;
            m = 0;
            while (q.size()) q.pop();
                    
            add(x);
            while (q.size())
            {
                x = q.front();
                q.pop();
                for (int i = 1; i <= n; i++)
                    if (abs(i - x) == d[x] || abs(i - x) == d[i])
                        add(i);
            }
            sort(A, A + m);
            sort(I, I + m);
            for (int j = 0; j < m; j++)
                if (A[j] != I[j])
                {
                    puts("NO");
                    return 0;
                }
        }
    puts("YES");
    return 0;
}