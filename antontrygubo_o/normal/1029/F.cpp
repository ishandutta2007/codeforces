#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
   ll a, b;
   cin>>a>>b;
   vector<ll> diva;
   vector<ll> divb;
   for (ll i = 1; i<=sqrt(a); i++) if (a%i==0)
   {
       diva.push_back(i);
       if (i*i!=a) diva.push_back(a/i);
   }
    for (ll i = 1; i<=sqrt(b); i++) if (b%i==0)
   {
       divb.push_back(i);
       if (i*i!=b) divb.push_back(b/i);
   }
   
   sort(diva.begin(), diva.end());
   sort(divb.begin(), divb.end());
   
    ll best = 100000000000000000;
    for (ll i = 1; i<=sqrt(a+b); i++) if ((a+b)%i==0)
    {
        ll j = (a+b)/i;
        if (lower_bound(diva.begin(), diva.end(), i+1) != lower_bound(diva.begin(), diva.end(), (a+j-1)/j)) best = i+j;
        if (lower_bound(divb.begin(), divb.end(), i+1) != lower_bound(divb.begin(), divb.end(), (b+j-1)/j)) best = i+j;
        
    }
   cout<<2*best;
   
}