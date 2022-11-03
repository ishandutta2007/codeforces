#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define ld  long double
///-------------------///


ll a[500000],ans;
vector <ll > vec;

///-------------------///





///---program start---///
int main()
{
    ll n,st;
    cin>>n>>st;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    if (n==1) cout<<0; else
    {
        ll l=a[1];
        ll r=a[n-1];
        ll mn1=min(abs(st-l)+abs(l-r),abs(st-r)+abs(l-r));
        l=a[2];
        r=a[n];
        ll mn2=min(abs(st-l)+abs(l-r),abs(st-r)+abs(l-r));
        cout<<min(mn1,mn2);
    }
}