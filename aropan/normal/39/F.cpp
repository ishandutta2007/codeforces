#include <cstdio>

using namespace std;

const int MAXN = 111;

int n, m, k, l, ans;
int a[MAXN], b[MAXN];
int A[MAXN];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < k; i++)
        scanf("%d", &b[i]);
    
    ans = 1e+9;
    for (int i = 0; i < m; i++)
    {
        int c = 0;
        for (int j = 0; j < k; j++)
            c += b[j] % a[i] == 0;
            
        if (c < ans)
        {
            ans = c;
            l = 0;
        }
        if (c == ans)
            A[l++] = i + 1;
    }
    printf("%d\n", l);
    for (int i = 0; i < l; i++)
    {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
        
        
    
    return 0;
}