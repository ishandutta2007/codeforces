#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 2*100000 + 50;
typedef long long llong;

long long sum[4*MAXN+50];
llong delta[4*MAXN+50];

void modify(int v, int l, int r, int i, int j, llong d)
{
    if (i <= l && r <= j)
    {
        delta[v] += d;
        sum[v] += d * (r - l + 1);
        return;
    }
    
    int c = (l + r) / 2;
    
    if (i <= c)
    {
        modify(2*v+0, l, c, i, j, d);
    }
    
    if (c < j)
    {
        modify(2*v+1, c+1, r, i, j, d);
    }
    
    sum[v] = sum[2*v+0] + sum[2*v+1] + delta[v] * (r - l + 1);
}

llong res = 0;

void sumf(int v, int l, int r, int i, int j, llong d)
{
    if (i <= l && r <= j)
    {
        res += sum[v] + d * (r - l + 1);
        return;
    }
    
    int c = (l + r) / 2;
    
    if (i <= c)
    {
        sumf(2*v+0, l, c, i, j, d + delta[v]);
    }
    
    if (c < j)
    {
        sumf(2*v+1, c+1, r, i, j, d + delta[v]);
    }
} 

int main()
{
    #if 0
    freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);
    #endif
    int t;
    int n = 1;
    
    scanf("%d\n", &t);
    
    for (int i = 0; i < t; i++)
    {
        int type ;
        scanf("%d", &type);
        
        if (type == 1)
        {
            int x, ai;
            scanf("%d %d", &ai, &x);
            modify(1, 1, MAXN-1, 1, ai, x);
        }
        else if (type == 2)
        {
            int x;
            scanf("%d", &x);
            n++;
            modify(1, 1, MAXN-1, n, n, x);
        }
        else
        {
            //scanf("\n");
            
			if (n>1)
			{
				res = 0;
				sumf(1, 1, MAXN-1, n, n, 0);
				//cout << "jk " << res << " " << n << endl;
				modify(1, 1, MAXN-1, n, n, -res);
				n--;
			}
        }
        
        res = 0;
        sumf(1, 1, MAXN-1, 1, n, 0);
        
        printf("%.9f\n",double(res)/n);
    }
    
    
}