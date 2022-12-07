#include <bits/stdc++.h>

using namespace std;

int n, w=1000000000, p;
int t[100001];

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>t[i];
        t[i]-=i;
        t[i]=max(t[i], 0);
        if(t[i]%n!=0)
        {
            t[i]/=n;
            ++t[i];
        }
        else
        {
            t[i]/=n;
        }
    }
    for(int i=0; i<n; ++i)
    {
        if(t[i]<w)
        {
            w=t[i];
            p=i;
        }
    }
    cout<<++p;
    return 0;
}