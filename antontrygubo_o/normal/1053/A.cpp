#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin>>n>>m>>k;
    if (k==1) {cout<<"NO"; return 0;}
    bool n1 = false;
    ll t = __gcd(n, k);
    if (t>1) n1 = true;
    n/=t;
    k/=t;
    bool m1 = false;
    t = __gcd(m, k);
    if (t>1) m1 = true;
    m/=t;
    k/=t;
    if (k==2)
    {
        cout<<"YES"<<endl;
        cout<<0<<' '<<0<<endl<<0<<' '<<m<<endl<<n<<' '<<0;
        return 0;
    }
    else if (k==1)
    {
        cout<<"YES"<<endl;
        if (m1) cout<<0<<' '<<0<<endl<<0<<' '<<2*m<<endl<<n<<' '<<0;
        else cout<<0<<' '<<0<<endl<<0<<' '<<m<<endl<<2*n<<' '<<0;
    }
    else cout<<"NO";
}