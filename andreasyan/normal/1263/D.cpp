#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 55;

int n;
int m[N];
char a[N][M];

vector<int> v[26];

int k;
bool c[N];
void dfs(int x)
{
    c[x] = true;
    for (int j = 0; j < m[x]; ++j)
    {
        while (!v[a[x][j] - 'a'].empty())
        {
            int h = v[a[x][j] - 'a'].back();
            v[a[x][j] - 'a'].pop_back();
            if (!c[h])
            {
                dfs(h);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", a[i]);
        m[i] = strlen(a[i]);
        for (int j = 0; j < m[i]; ++j)
        {
            v[a[i][j] - 'a'].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs(i);
        }
    }
    printf("%d\n", k);
    return 0;
}