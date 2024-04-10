#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll f (ll m, ll n)
{
    if (n<m) swap(m, n);
    if (m==1)
    {
        if (n==1) return 1;
        if (n==2) return 2;
        if (n==3) return 3;
        if (n==4) return 2;
        if (n==5) return 1;
        if (n==0) return 0;
        return f(1, n%6);
    }
    if (m==2)
    {
        if (n==2) return 4;
        if (n==3) return 2;
        if (n==7) return 2;
        return 0;
    }
    if (n%2==0) swap(m, n);
    if (m%2==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

ll result(ll m, ll n)
{
    return m*n-f(m, n);
}

int main(){
    ios_base::sync_with_stdio(false);
    ll m, n;
    cin>>m>>n;
    cout<<result(m, n);
    
}