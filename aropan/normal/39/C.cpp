#include <cstdio>
#include <algorithm>

#define L first.first
#define R first.second
#define I second

using namespace std;

const int MAXN = 5000;
int s[MAXN];
int xx[MAXN];
pair < pair <int, int>, int > a[MAXN];
int f[MAXN], cf[MAXN];
int d[MAXN];
int ans[MAXN];
int n, m, k;

bool opr_sort(const int &i, const int &j)
{
    return a[i].R - a[i].L < a[j].R - a[j].L;
}


int MODIFY(int i, int id)
{
    while (i <= MAXN)
    {
        if (cf[s[i]] < cf[id])
            s[i] = id;
        i = (i | (i - 1)) + 1;
    }
    return 0;
}

int FIND(int i)
{
    int ans = 0;
    while (i)
    {
        if (cf[s[i]] > cf[ans])
            ans = s[i];
        i = i & (i - 1);
    }
    return ans;
}


int run(int ll, int rr)
{
    for (int i = 0; i <= m + 1; i++)
        s[i] = 0;
        
    for (int i = 1; i <= n; i++)
        cf[i] = f[i];
        
    for (int i = 1; i <= n; i++)
    {
        if (a[i].L == ll && a[i].R == rr) continue;
        
        if (a[i].L < ll  || rr < a[i].R) continue;
        
        cf[i] += cf[FIND(a[i].L)];
        MODIFY(a[i].R, i);
    }
    return 0;
        
}

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int c, r;
        scanf("%d %d", &c, &r);
        
        a[i].L = c - r;
        a[i].R = c + r;
        
        xx[m++] = a[i].L;
        xx[m++] = a[i].R;
    }
    sort(xx ,xx + m);
    m = unique(xx, xx + m) - xx;
    
    for (int i = 1; i <= n; i++)
    {
        a[i].L = lower_bound(xx, xx + m, a[i].L) - xx + 1;
        a[i].R = lower_bound(xx, xx + m, a[i].R) - xx + 1;
    }
    n++;
    a[n].L = 0;
    a[n].R = m + 1;
    
    for (int i = 1; i <= n; i++)
        a[i].I = i;
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        d[i] = i;
    sort(d + 1, d + n + 1, opr_sort);
    
    for (int i = 1; i <= n; i++)
    {
        int I = d[i];
        run(a[I].L, a[I].R);
        f[I] = cf[FIND(a[I].R)] + 1;
    }
    
    k = 0;
    ans[k++] = 1;
    
    for (int i = 0; i < k; i++)
    {
        int I = ans[i];
        run(a[I].L, a[I].R);
        
        int x = a[I].R;
        int next = FIND(x);
        
        while (next)
        {
            ans[k++] = next;
            x = a[next].L;
            next = FIND(x);
        }
    }
    
    printf("%d\n", k - 1);
    for (int i = 1; i < k; i++)
    {
        if (i - 1) printf(" ");
        printf("%d", a[ans[i]].I);
    }
    printf("\n");
    return 0;
}