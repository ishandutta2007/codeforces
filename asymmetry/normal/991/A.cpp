#include <bits/stdc++.h>

using namespace std;

int a, b, c, n;

int main()
{
    cin>>a>>b>>c>>n;
    if(min(a, b)<c)
    {
        printf("-1");
        return 0;
    }
    if(c>n)
    {
        printf("-1");
        return 0;
    }
    if(n-a-b+c<=0)
    {
        printf("-1");
        return 0;
    }
    printf("%d", n-a-b+c);
    return 0;
}