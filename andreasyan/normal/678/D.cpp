#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll m=1000000007;

ll ast(ll x,ll y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x%m;
    if(y%2==0)
    {
        long long t=ast(x,y/2);
        return (t*t)%m;
    }
    else
        return (ast(x,y-1)*x)%m;
}
ll bzh(ll x,ll y)
{
    return (x*ast(y,m-2))%m;
}

int main()
{
    ll a,b,n,x;
    cin>>a>>b>>n>>x;
    if(a!=1)
        cout<<((ast(a,n)*x)%m+(b*bzh((ast(a,n)-1+m)%m,(a-1+m)%m))%m)%m<<endl;
    else
        cout<<((ast(a,n)*x)%m+(b*(n%m))%m)%m<<endl;
    return 0;
}