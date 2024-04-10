#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <map>

using namespace std;

const int MAXL = 11;
const int MAXN = 4000002;

map <string, int> M;

int last[MAXN];
int next[MAXN], dest[MAXN];
int f[MAXN], g[MAXN];
char S[MAXL];
string a[MAXN];
int l, n, m, k;
int upd[MAXN], cnt;
       
int dfs(int x)
{
    if (upd[x] == cnt) return 0;
    upd[x] = cnt;
    for (int i = last[x]; i; i = next[i])
        if (g[dest[i]] == 0 || dfs(g[dest[i]]))
        {
            f[x] = dest[i];
            g[dest[i]] = x;
            return 1;
        }
    return 0;
}


int rec(int m, int c, string s)
{
    if (m == l) return 0;
    rec(m + 1, c, s);
    if (c < 4)
    {
        a[k++] = (s + S[m]);
        rec(m + 1, c + 1, s + S[m]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    m = 0;
    M.clear();
    for (int i = 1; i <= n; i++)
    {
        gets(S);
        l = strlen(S);
        k = 0;
        rec(0, 0, "");

        sort(a, a + k);
        k = unique(a, a + k) - a;
        for (int j = 0; j < k; j++)
        {
            if (M[a[j]] == 0)
                M[a[j]] = M.size();

            m++;
            dest[m] = M[a[j]];
            next[m] = last[i];
            last[i] = m;
        }
    }


    for (map <string, int> :: iterator iter = M.begin(); iter != M.end(); ++iter)
        a[iter->second] = iter->first;

    for (int i = 1; i <= n; i++)
        for (int j = last[i]; j; j = next[j])
        {
            if (g[dest[j]] == 0)
            {
                f[i] = dest[j];
                g[dest[j]] = i;
                break;
            }
        }

    for (int i = 1; i <= n; i++)
        if (f[i] == 0)
        {   
            cnt++;
            if (!dfs(i))
            {
                puts("-1");
                return 0;
            }
        }

    for (int i = 1; i <= n; i++)
        printf("%s\n", a[f[i]].c_str());

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}