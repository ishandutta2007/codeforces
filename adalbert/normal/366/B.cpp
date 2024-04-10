#include <bits/stdc++.h>
using namespace std;
long long cnt[200000],a[200000],mn,imn;
int main()
{
    long long n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[(i%k)]+=a[i];
    }
    mn=1000000000000000;
    for (int i=1;i<k;i++)
        if (cnt[i]<mn)
        {
            mn=cnt[i];
            imn=i;
        }
    if (cnt[0]<mn)
        {
            imn=k;
        }
        cout<<imn;
}