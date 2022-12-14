#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        int A = (a + b) / 2;
        int B = a + b - A;
        set<int> S;
        for(int i = 0; i <= a; i++)
            if(A - i >= 0 && a - i >= 0 && a - i <= B && A - i <= b && B - a + i <= b && B - a + i >= 0)
                S.insert(A + a - i - i);

        A = (a + b + 1) / 2;
        B = a + b - A;
        for(int i = 0; i <= a; i++)
            if(A - i >= 0 && a - i >= 0 && a - i <= B && A - i <= b && B - a + i <= b && B - a + i >= 0)
                S.insert(A + a - i - i);
        printf("%d\n", (int)S.size());
        for(int k: S)
            printf("%d ", k);
        puts("");
    }
    return 0;
}