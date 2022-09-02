#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n , d;
    cin>>n>>d;
    ll a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    ll result = 2;
    for (int i = 0; i<n-1; i++)
    {
        if (a[i+1]-a[i]==2*d) result++;
        else if (a[i+1]-a[i]>2*d) result+=2;
    }
    cout<<result;
}