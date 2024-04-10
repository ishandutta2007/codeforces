#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    ll sum1 = 0;
    ll sum2 = 0;
    ll a, b;
    for (int i = 0; i<2*n; i++) 
    {
        cin>>a>>b; sum1+=a; sum2+=b;
    }
    sum1/=n;
    sum2/=n;
    cout<<sum1<<' '<<sum2;
}