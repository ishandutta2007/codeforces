#include <bits/stdc++.h>

using namespace std;

long long n, a, it, jt, w;
long long t[100001][2];

int main()
{
    scanf("%lld", &n);
    for(int i=1; i<=n*2; ++i)
    {
        scanf("%lld", &a);
        if(t[a][0])
        {
            t[a][1]=i;
        }
        else
        {
            t[a][0]=i;
        }
    }
    it=1;
    jt=1;
    for(int i=1; i<=n; ++i)
    {
        w+=min(abs(it-t[i][0])+abs(jt-t[i][1]), abs(it-t[i][1])+abs(jt-t[i][0]));
        it=t[i][0];
        jt=t[i][1];
    }
    printf("%lld", w);
    return 0;
}