#include<bits/stdc++.h>
using namespace std;

int a[10101];

int ans[101][2];

int last[101];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n * k; i++)
        scanf("%d", &a[i]);
    
    deque<int> DQ;
    
    int cnt = 0;
    for(int l = 1, r = 1; r <= n * k; r++)
    {
        if(last[a[r]] == 0 || last[a[r]] < l || ans[a[r]][0] != 0)
            last[a[r]] = r;
        else
        {
            ans[a[r]][0] = last[a[r]];
            ans[a[r]][1] = r;
            cnt ++;
            DQ.push_back(r);
        }
        while(cnt >= (n + k - 2) / (k - 1))
        {
            while(DQ.size() > 0 && DQ.front() <= l)
            {
                cnt--;
                DQ.pop_front();
            }
            l++;
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}