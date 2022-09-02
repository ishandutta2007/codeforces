#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll n, ll k)
{
    ll n1 =n;
    ll Vasia = 0;
    while (n)
    {
        Vasia+=min(n, k);
        if (n>k) n-=k;
        else n = 0;
        n = n-n/10;
    }
    return (2*Vasia>=n1);
}

int main()
{
    ll n;
    cin>>n;
    ll left = 0; ll right = n;
    while (right-left>1)
    {
        ll current = (right+left)/2;
        if (check(n, current)) right = current;
        else left = current;
    }
cout<<right;

}