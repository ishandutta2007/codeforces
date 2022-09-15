#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N; scanf("%d", &N);
    while(N--)
    {
        long long x; scanf("%lld", &x);
        
        if(1 <=x%14 &&x%14<=6 && x >= 15) puts("YES");
        else puts("NO");
    }
}