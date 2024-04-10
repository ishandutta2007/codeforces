#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    int nOdd = (n + 1) / 2, nEven = n / 2;
    int nMore = (a * b + 1) / 2, nLess = a * b / 2;
    
    int nowOdd = 1, nowEven = 2;
    
    if (nOdd <= nMore && nEven <= nLess)
    {
        for (int y = 0; y < a; y++)
        {
            for (int x = 0; x < b; x++)
                if ((x + y) % 2 == 0)
                {
                    printf("%d ", (nowOdd <= n ? nowOdd : 0)); nowOdd += 2;
                }
                else
                {
                    printf("%d ", (nowEven <= n ? nowEven : 0)); nowEven += 2;
                }
            printf("\n");
        }
    }
    else
    {
        printf("-1\n");
    }
    
    return 0;
}