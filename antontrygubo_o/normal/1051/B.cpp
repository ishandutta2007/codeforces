#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
        
    ll l, r;
    cin>>l>>r;
    cout<<"YES"<<endl;
    for (ll k = l; k<r; )
    {
        cout<<k<<' '<<k+1<<endl;
        k+=2;
    }
    
}