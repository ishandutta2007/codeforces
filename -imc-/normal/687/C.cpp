#include <bits/stdc++.h>

using namespace std;

typedef long long li;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    
    static bool d[1005][1005];
    static bool can[505];
    
    d[0][0] = true;
    
    for (int i = 0; i < n; i++)
        for (int sum1 = k; sum1 >= 0; sum1--)
            for (int sum2 = k; sum2 >= 0; sum2--)
                if (d[sum1][sum2])
                {
                    d[sum1 + c[i]][sum2 + c[i]] = true;
                    d[sum1][sum2 + c[i]] = true;
                }
            
    vector<int> answer;
    for (int x = 0; x <= k; x++)
        if (d[x][k])
            answer.push_back(x);
        
    printf("%d\n", answer.size());
    for (int x: answer)
        printf("%d ", x);
    printf("\n");
    
    return 0;
}