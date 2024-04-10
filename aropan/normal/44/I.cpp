#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 11;
const int MAXM = 200000;

int q[MAXM][MAXN];
int f[MAXM];
int a[MAXN]; 
int q1, q2;
int n, c;

int add(int *a, int n)
{
    for (int i = 0; i < n; i++)
        q[q1][i] = a[i];
    f[q1] = n;
    q1++;
    return 0;
}

int write(int *a, int n)
{
    int next[n + 1], last[n + 1];
    memset(next, 0, sizeof(next));
    memset(last, 0, sizeof(last));
    
    for (int i = n - 1; i >= 0; i--)
    {
        next[i + 1] = last[a[i]];
        last[a[i]] = i + 1;
    }
    
    bool fgroup = false;
    for (int i = 1; i <= n && last[i]; i++)
    {
        if (fgroup) printf(",");
        fgroup = true;
        
        bool fnumber = false;
        
        printf("{");
    
        int x = last[i];
        while (x)
        {
            if (fnumber) printf(",");
            fnumber = true;
            printf("%d", x);
            x = next[x];
        }
        printf("}");
    }
    printf("\n");
    return 0;
}

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        a[i] = i == 0;
        
    add(a, 1);
    c = 0;
    while (q1 != q2)
    {
        if (f[q2] == n) break;
        
        
        int *a = q[q2];
        int n = f[q2];
        int m = 0;
        
        for (int i = 0; i < n; i++)
            m = max(m, a[i]);
            
        if (c % 2)
        {
            for (int i = m + 1; i >= 1; i--)
            {
                a[n] = i;
                add(a, n + 1);
            }
        }
        else
        {
            for (int i = 1; i <= m + 1; i++)
            {
                a[n] = i;
                add(a, n + 1);
            }
        }
        
        c++;
        if (f[q2] != f[q2 + 1]) c = 0;
        q2++;
    }
    printf("%d\n", q1 - q2);
    for (int i = q2; i < q1; i++)
        write(q[i], n);
    
    return 0;
}