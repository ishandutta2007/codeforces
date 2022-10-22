#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    for (int i = 0; i + 2 < n; i++)
        if (a[i + 1] == a[i] + 1 && a[i + 2] == a[i] + 2)
        {
            printf("YES\n");
            return 0;
        }
        
    printf("NO\n");
    
    return 0;
}