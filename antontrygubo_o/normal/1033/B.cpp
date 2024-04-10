#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double


bool prime(ll n)
{
    for (ll i = 2; i<=sqrt(n); i++) if (n%i==0) return false;
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for (int test = 0; test<t; test++)
    {
        ll a, b;
        cin>>a>>b;
        if (a!=b+1) cout<<"NO";
        else
        {
            if (prime(a+b)) cout<<"YES";
            else cout<<"NO";
        }
        cout<<endl;
    }
}