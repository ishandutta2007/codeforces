#include <bits/stdc++.h>

using namespace std;

int n, k;
int t[200000];

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; ++i)
    {
        cin>>t[i];
    }
    sort(t, t+n);
    if(k==0)
    {
        if(t[0]-1<1)
        {
            printf("-1");
            return 0;
        }
        printf("%d", t[0]-1);
        return 0;
    }
    if(k==n)
    {
        printf("%d", t[n-1]);
        return 0;
    }
    if(t[k]>t[k-1])
    {
        cout<<t[k-1];
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}