#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, s;
        scanf("%d%d", &n, &s);
        printf("%d\n", s / (n / 2 + 1));
    }
    return 0;
}