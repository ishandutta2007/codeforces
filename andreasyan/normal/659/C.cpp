#include <bits/stdc++.h>
using namespace std;
 
int n, m;
 
set<int> s;
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    vector<int> ans;
    for (int i = 1; ; ++i)
    {
        if (s.find(i) != s.end())
            continue;
        m -= i;
        if (m < 0)
            break;
        ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}