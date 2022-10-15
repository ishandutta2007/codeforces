#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1111111;

char a[MAXN], b[MAXN];
bool st[MAXN], fn[MAXN];
int ans[MAXN];
int n, m;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%s\n%s\n", a + 1, b + 1);
    n = strlen(a + 1);
    
    
    st[0] = true;
    for (int i = 1; i <= n; i++)
        st[i] = st[i - 1] && a[i] == b[i];
    
    fn[n + 1] = true;
    for (int i = n; i >= 1; i--)
        fn[i] = fn[i + 1] && a[i] == b[i - 1];
        
    for (int i = 1; i <= n; i++)
        if (st[i - 1] && fn[i + 1])
            ans[m++] = i;
            
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
    {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}