#include <bits/stdc++.h>

using namespace std;

const int pre[] = { 1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401 };

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int q, i;
    scanf("%d", &q);
    for(int b = 0; b < q; b++)
    {
        int a;
        scanf("%d", &a);
        for(i = 1;; i++)
        {
            if(a == (1 << i) - 1)
            {
                printf("%d\n", pre[i - 2]);
                break;
            }
            else if(a < (1 << i) - 1)
            {
                printf("%d\n", (1 << i) - 1);
                break;
            }
        }
    }

    return 0;
}