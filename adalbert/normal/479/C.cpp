#include <bits/stdc++.h>
using namespace std;
long long mn,mx,n,k,imx,imn;
pair <long long , long long > a[50000];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+n);
    mx=0;
    for (int i=1;i<=n;i++)
    {
        if (mx>a[i].second) mx=a[i].first; else mx=a[i].second;
    }
    cout<<mx;
}