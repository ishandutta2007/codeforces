#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define y1 drfijortjubo
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=2e5+10;

int x[300],y[300];
int n,a,b;

bool can(int i, int j)
{
    if (x[i]+x[j]<=a && max(y[i],y[j])<=b)
        return(1);
    if (x[i]+x[j]<=b && max(y[i],y[j])<=a)
        return(1);

    swap(x[i],y[i]);

    if (x[i]+x[j]<=a && max(y[i],y[j])<=b)
        return(1);
    if (x[i]+x[j]<=b && max(y[i],y[j])<=a)
        return(1);

    swap(x[i],y[i]);
    swap(x[j],y[j]);

    if (x[i]+x[j]<=a && max(y[i],y[j])<=b)
        return(1);
    if (x[i]+x[j]<=b && max(y[i],y[j])<=a)
        return(1);

    swap(x[i],y[i]);

    if (x[i]+x[j]<=a && max(y[i],y[j])<=b)
        return(1);
    if (x[i]+x[j]<=b && max(y[i],y[j])<=a)
        return(1);


    return(0);
}

signed main()
{
    cin>>n>>a>>b;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int mx=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            if (can(i,j))
                mx=max(mx,x[i]*y[i]+x[j]*y[j]);
        }
    cout<<mx;
}