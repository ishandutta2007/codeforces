#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
        t[i]--;
    }
    
    vector<int> answer(n);
    for (int l = 0; l < n; l++)
    {
        vector<int> cnt(n);
        int dom = 0;
        
        for (int r = l; r < n; r++)
        {
            cnt[t[r]]++;
            if (cnt[t[r]] > cnt[dom] || (cnt[t[r]] == cnt[dom] && t[r] < dom))
                dom = t[r];
            
            answer[dom]++;
        }
    }
    
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);
    printf("\n");
    
    return 0;
}