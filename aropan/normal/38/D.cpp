#include <cstdio>
#include <algorithm>

#define abs(x) ((x) < 0?-(x) : (x))

using namespace std;

const int MAXN = 111;

int n;
int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
int c[MAXN], x[MAXN], y[MAXN];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
        if (x1[i] > x2[i]) swap(x1[i], x2[i]);
        if (y1[i] > y2[i]) swap(y1[i], y2[i]);
        
        x1[i] *= 2;
        x2[i] *= 2;
        y1[i] *= 2;
        y2[i] *= 2;
        
        
        x[i] = (x2[i] + x1[i]) / 2;
        y[i] = (y2[i] + y1[i]) / 2;
        c[i] = (x2[i] - x1[i]) * (x2[i] - x1[i]) * (x2[i] - x1[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int
            X = 0, Y = 0, C = 0;
        bool
            flag = true;
            
        for (int j = i; j > 0 && flag; j--)
        {
            X += x[j] * c[j];
            Y += y[j] * c[j];
            C += c[j];
            
            flag &= 
                x1[j - 1] * C <= X && X <= x2[j - 1] * C &&
                y1[j - 1] * C <= Y && Y <= y2[j - 1] * C;
        }
        if (flag == false) break;
        ans = i + 1;
    }
    printf("%d\n", ans);
    return 0;
}