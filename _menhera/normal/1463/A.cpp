#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    for(int t=0; t<T; ++t)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);

        if( (a+b+c)%9 == 0 && min({a, b, c})>=(a+b+c)/9)
            puts("YES");
        else
            puts("NO");
    }
}