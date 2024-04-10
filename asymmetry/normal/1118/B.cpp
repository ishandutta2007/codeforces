#include <bits/stdc++.h>

using namespace std;

int n, w;
int t[200001];
int p1[200001];
int p2[200001];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        p1[i]=p1[i-1];
        p2[i]=p2[i-1];
        scanf("%d", &t[i]);
        if(i&1)
        {
            p1[i]+=t[i];
        }
        else
        {
            p2[i]+=t[i];
        }
    }
    for(int i=1; i<=n; ++i)
    {
        if(i&1)
        {
            if(p1[i]-t[i]+p2[n]-p2[i]==p2[i]+p1[n]-p1[i])
            {
                ++w;
            }
        }
        else
        {
            if(p2[i]-t[i]+p1[n]-p1[i]==p1[i]+p2[n]-p2[i])
            {
                ++w;
            }
        }
    }
    printf("%d\n", w);
    return 0;
}