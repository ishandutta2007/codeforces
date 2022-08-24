#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    set <int> s;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        scanf("%d", &x);
        if (!s.count(x))
        {
            s.insert(x);
        }
        else
        {
            s.erase(x);
        }
        ans = max(ans, (int) s.size());
    }
    printf("%d\n", ans);
}