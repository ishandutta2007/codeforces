#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin>>n;
    n++;
    ll x = 1;
    ll counter = 0;
    while (2*x<n) {x*=2; counter++;}
    cout<<counter+1;

}