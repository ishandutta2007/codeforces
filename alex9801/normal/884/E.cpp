#include<bits/stdc++.h>
using namespace std;

int par[(1 << 14) + 1];
int root(int x)
{
    return par[x] == 0 ? x : (par[x] = root(par[x]));
}
bool merge(int x, int y)
{
    x = root(x);
    y = root(y);
    if(x == y)
        return 0;
    par[x] = y;
    return 1;
}

bool used[(1 << 14) + 1];
int tmp[(1 << 14) + 1];
int mem[2][1 << 14];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> v;
    for(int i = 1; i <= m; i++)
        v.push_back(i);

    int res = 0;
    for(int i = 0; i <= n; i++)
    {
        int x = i % 2;
        int y = 1 - i % 2;

        if(i == n)
        {
            for(int j = 0; j < m; j++)
                mem[x][j] = 0;
        }
        else
        {
            for(int j = 0; j < m / 4; j++)
            {
                char c;
                while(1)
                {
                    c = getchar();
                    if(isalnum(c))
                        break;
                }

                int t;
                if(isdigit(c))
                    t = c - '0';
                else
                    t = c - 'A' + 10;

                for(int k = 0; k < 4; k++)
                {
                    if(t & (1 << (3 - k)))
                        mem[x][4 * j + k] = 1;
                    else
                        mem[x][4 * j + k] = 0;
                }
            }
        }

        memset(tmp, 0, sizeof tmp);
        for(int j = 0; j < m; j++)
        {
            int r = root(mem[y][j]);
            assert(mem[y][j] == r);
            if(r && tmp[r] != -1)
            {
                if(mem[x][j])
                    tmp[r] = -1;
                else
                    tmp[r] = 1;
            }
        }

        for(int j = 1; j <= m; j++)
        {
            if(tmp[j] == 1)
            {
                res++;
                used[j] = 0;
                v.push_back(j);
            }
        }

        for(int j = 0; j < m; j++)
        {
            if(!mem[x][j])
                continue;

            if(mem[y][j])
                mem[x][j] = mem[y][j];
            else
            {
                assert(!v.empty());
                mem[x][j] = v.back();
                used[v.back()] = 1;
                par[v.back()] = 0;
                v.pop_back();
            }

            if(j > 0 && mem[x][j - 1])
                merge(mem[x][j - 1], mem[x][j]);
        }

        for(int j = 0; j < m; j++)
        {
            int r = root(mem[x][j]);
            if(r && mem[x][j] != r)
            {
                if(used[mem[x][j]])
                {
                    used[mem[x][j]] = 0;
                    v.push_back(mem[x][j]);
                }
                mem[x][j] = r;
            }
        }
    }

    printf("%d\n", res);
    return 0;
}