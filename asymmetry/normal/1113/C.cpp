#include <bits/stdc++.h>

using namespace std;

long long odp;
int n;
int t[300001];
int p[300001];
int wp[1048576];
int wnp[1048576];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &t[i]);
        p[i]=p[i-1]^t[i];
        if(i&1)
        {
            ++wnp[p[i]];
        }
        else
        {
            ++wp[p[i]];
        }
    }
    ++wp[0];
    for(int i=0; i<n; ++i)
    {
        if(i&1)
        {
            --wnp[p[i]];
            odp+=wnp[p[i]];
        }
        else
        {
            --wp[p[i]];
            odp+=wp[p[i]];
        }
    }
    printf("%lld", odp);
    return 0;
}