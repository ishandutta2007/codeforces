#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
int n,a[maxn];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int d1=1,d2=0,kq=0;
    for (int i=2;i<=n;i++)
        if (a[i]==a[i-1]) d1++;
        else
        {
            kq=max(kq,min(d1,d2)*2);
            d2=d1;
            d1=1;
        }
    kq=max(kq,min(d1,d2)*2);
    cout<<kq;
    return 0;
}