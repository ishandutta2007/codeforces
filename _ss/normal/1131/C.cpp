#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
int a[maxn],n,b[maxn];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int t=2,d=n;
    b[1]=a[n];
    for (int i=n-1;i>=1;i=i-2)
    if (i>1)
    {
        b[t]=a[i];
        t++;
        b[d]=a[i-1];
        d--;
    }
    else b[t]=a[i];
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}