#include <cstdio>
#include <set>
#include <queue>
#include <cstdlib>

#define C first.first
#define K first.second
#define X second

using namespace std;

typedef pair < pair<int, int> , int > hpair;

const int MAXN = 1001;
const int MAXK = MAXN * MAXN / 3 + 1;

const int xi[4] = {-1, 0, 1, 0};
const int yi[4] = {0, 1, 0, -1};

int n, m, k;
char a[MAXN][MAXN];
int d[MAXN][MAXN];
set <int> S[MAXK];
int c[MAXK][4];
hpair f[MAXK];
int color[MAXK];

priority_queue < hpair, vector < hpair >, greater < hpair > > h;

int add(int x, int c, int k)
{
    f[x] = make_pair(make_pair(c, k), x);
    h.push(f[x]);
    return 0;
}

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; scanf("\n"), i++)
        for (int j = 0; j < m; scanf("%c", &a[i][j]), j++);
        
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'b')
            {
                k++;
                if (
                    0 < i && a[i - 1][j] == 'w' &&
                    i < n - 1 && a[i + 1][j] == 'w'
                )
                {
                    a[i - 1][j] = a[i][j] = a[i + 1][j] = '.';
                    d[i - 1][j] = d[i][j] = d[i + 1][j] = k;
                    continue;
                }
                
                if (
                    0 < j && a[i][j - 1] == 'w' &&
                    j < m - 1 && a[i][j + 1] == 'w'
                )
                {
                    a[i][j - 1] = a[i][j] = a[i][j + 1] = '.';
                    d[i][j - 1] = d[i][j] = d[i][j + 1] = k;
                    continue;
                }
                
                puts("NO");
                return 0;
            }
            
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != '.')
            {
                puts("NO");
                return 0;
            }
            
//    for (int i = 0; i < n; printf("\n"), i++)
//        for (int j = 0; j < m; printf("%3d", d[i][j]), j++);
            
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (d[i][j])
            {
                for (int z = 0; z < 4; z++)
                {
                    int 
                        x = i + xi[z],
                        y = j + yi[z];
                        
                    if (x < 0 || n <= x || y < 0 || m <= y || d[x][y] == 0 || d[x][y] == d[i][j]) continue;
                    
                    S[d[i][j]].insert(d[x][y]);
                    S[d[x][y]].insert(d[i][j]);
                }
            }
            
//    for (int i = 1; i <= k; printf("\n"), i++)
//        for (set <int> :: iterator x = S[i].begin(); x != S[i].end(); printf("%3d", *x), x++);
        
        
    for (int i = 1; i <= k; i++)
    {
        f[i] = make_pair(make_pair(4, -S[i].size()), i);
        h.push(f[i]);
    }
    
    while (h.size())
    {
        int x = h.top().X;
        
        if (f[x] != h.top())
        {
            h.pop();
            continue;
        }
        h.pop();
        
        
        for (int i = 0; i < 4; i++)
            if (c[x][i] == false)
            {
                if (color[x] == 0 || rand() % 2)
                    color[x] = i + 1;
            }
            
        if (color[x] == 0)
        {
            puts("NO");
            return 0;
        }
                
        for (set <int> :: iterator i = S[x].begin(); i != S[x].end(); i++)
            if (color[*i] == 0)
            {
                add(*i, f[*i].C - (int)(c[*i][color[x] - 1] == false), f[*i].K + 1);
                c[*i][color[x] - 1] = true;
            }
    }
    
    puts("YES");
    for (int i = 0; i < n; printf("\n"), i++)
        for (int j = 0; j < m; j++)
        {
            if (d[i][j]) a[i][j] = color[d[i][j]] + 'a' - 1;
            printf("%c", a[i][j]);
        }
    return 0;
}