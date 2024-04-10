#include <bits/stdc++.h>

using namespace std;

int n, k, a, h;
int t[1000000];
int g[1000001];
int w[1000000];

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; ++i)
    {
        cin>>t[i];
        ++g[t[i]];
    }
    for(int i=1; i<=1000000; ++i)
    {
        if(g[i]>0)
        {
            w[h]=i;
            ++h;
        }
    }
    sort(w, w+h-1);
    for(int i=0; i<n-1; ++i)
    {
        if((w[i]<w[i+1])&&(w[i]+k>=w[i+1]))
        {
            a+=g[w[i]];
        }
    }
    cout<<n-a;
    return 0;
}