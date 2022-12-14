#include<bits/stdc++.h>
using namespace std;

int a[10101];

int n;

void solve()
{
    for(int i = 1; i <= n; i += 2)
    if(a[i] % 2 != i % 2)
    {
        puts("-1");
        return;
    }
    vector<int> ans;
    
    for(int i = n; i >= 2; i -= 2)
    {
        for(int j = 2; j <= i; j++)
            if(a[j] == i)
            {
                ans.push_back(j);
                reverse(a + 1, a + j + 1);
                break;
            }
        for(int j = 3; j <= i; j++)
            if(a[j] == i - 1)
            {
                ans.push_back(j - 1);
                reverse(a + 1, a + j);
                break;
            }
        for(int j = 2; j <= i; j++)
        if(a[j] == i)
        {
            ans.push_back(j + 2);
            reverse(a + 1, a + j + 3);
            break;
        }
        for(int j = 2; j <= i; j++)
        if(a[j] == i)
        {
            ans.push_back(j);
            reverse(a + 1, a + j + 1);
            break;
        }
        ans.push_back(i);
        reverse(a + 1, a + i + 1);
    }
    printf("%d\n", (int)ans.size());
    for(int x: ans)
        printf("%d ", x);
    puts("");
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        solve();
    }
    return 0;
}