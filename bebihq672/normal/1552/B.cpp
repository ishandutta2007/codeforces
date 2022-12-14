#include<bits/stdc++.h>
using namespace std;

int r[50505][11];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 5; j++)
                scanf("%d", &r[i][j]);

        int idx = 1;
        for(int i = 2; i <= n; i++)
        {
            int cnt = 0;
            for(int j = 1; j <= 5; j++)
                if(r[i][j] < r[idx][j])
                    cnt++;
            if(cnt >= 3)
                idx = i;
        }
        bool flag = 0;
        for(int i = 1; i <= n; i++)
        if(i != idx)
        {
            int cnt = 0;
            for(int j = 1; j <= 5; j++)
                if(r[i][j] < r[idx][j])
                    cnt++;
            if(cnt >= 3)
            {
                puts("-1");
                flag = 1;
                break;
            }
        }
        if(!flag)
            printf("%d\n", idx);
    }
    return 0;
}