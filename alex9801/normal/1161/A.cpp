#include <bits/stdc++.h>
using namespace std;

int arr[100010];
int a[100010];
int b[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k, i;
    scanf("%d%d", &n, &k);
    for(i = 0; i < k; i++)
        scanf("%d", &arr[i]);

    memset(a, -1, sizeof a);
    memset(b, -1, sizeof b);

    for(i = 0; i < k; i++)
    {
        if(a[arr[i]] == -1)
            a[arr[i]] = i;
        
        b[arr[i]] = i;
    }

    int r = 0;
    for(i = 1; i <= n; i++)
    {
        if(a[i] == -1)
        {
            r++;
            if(i != 1)
                r++;
            if(i != n)
                r++;
        }
        else
        {
            if(i != 1)
            {
                if(a[i] > b[i - 1])
                    r++;
            }
            if(i != n)
            {
                if(a[i] > b[i + 1])
                    r++;
            }
        }
    }

    printf("%d\n", r);
    return 0;
}