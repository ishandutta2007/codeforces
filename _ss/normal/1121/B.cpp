#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=2e5+1;
int n,a[1001],dd[maxn];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int d=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++) dd[a[i]+a[j]]++;
    for (int i=1;i<maxn;i++) d=max(d,dd[i]);
    cout<<d;
    return 0;
}