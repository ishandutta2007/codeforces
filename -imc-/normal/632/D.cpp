#include <bits/stdc++.h>

using namespace std;

const int maxM = 1000500;
int cnt[maxM];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < n; i++)
        if (a[i] <= m)
            cnt[a[i]]++;
        
    for (int i = m; i >= 1; i--)
        for (int j = 2; j * i <= m; j++)
            cnt[i * j] += cnt[i];
    
    int index = max_element(cnt, cnt + m + 1) - cnt;
    if (cnt[index] == 0)
    {
        index = 1;
        cnt[index] = 0;
    }
    
    printf("%d %d\n", index, cnt[index]);
    
    int taken = 0;
    for (int i = 0; i < n; i++)
        if (index % a[i] == 0 && taken < cnt[index])
        {
            printf("%d ", i + 1);
            taken++;
        }
    printf("\n");
    
    return 0;
}