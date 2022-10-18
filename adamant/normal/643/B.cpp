#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    if (n == 4 || k <= n)
    {
        printf("-1\n");
        return 0;
    }
    
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--; c--; d--;
    
    vector<int> p(n, -1);
    set<int> unused;
    for (int i = 0; i < n; i++)
        if (i != a && i != b && i != c && i != d)
            unused.insert(i);
    
    p[0] = a;
    p[1] = c;
    p[n - 2] = d;
    p[n - 1] = b;
    
    for (int i = 0; i < n; i++)
        if (p[i] == -1)
        {
            p[i] = *unused.begin();
            unused.erase(unused.begin());
        }
    
    for (int i = 0; i < n; i++)
        printf("%d ", p[i] + 1);
    printf("\n");
    
    printf("%d %d ", p[1] + 1, p[0] + 1);
    for (int i = 2; i <= n - 3; i++)
        printf("%d ", p[i] + 1);
    printf("%d %d\n", p[n - 1] + 1, p[n - 2] + 1);
    
    return 0;
}