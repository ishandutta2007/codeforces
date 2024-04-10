#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        char buf[256];
        scanf(" IAO'%s", buf);
        
        string s = buf;
        int x;
        sscanf(s.c_str(), "%d", &x);
        
        ll tenPower = 10, sum = 0;
        for (int i = 1; i < (int)s.length(); i++)
            sum += tenPower, tenPower *= 10;
        
        x += tenPower * ((1989 + sum - x + tenPower - 1) / tenPower);
        printf("%d\n", x);
    }
    
    return 0;
}