#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+5;
int n,a[maxn];
int main()
{
    cin>>n;
    int x,minx=1e9,minvt;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x>=0) x=-x-1;
        a[i]=x;
        if (x<minx)
        {
            minx=x;
            minvt=i;
        }
    }
    if (n&1) a[minvt]=-a[minvt]-1;
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}