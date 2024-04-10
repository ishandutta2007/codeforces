#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define ll unsigned long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fir first
#define sec second
#define m_p make_pair
#define pb push_back

///--------------------------------------------------------------------------------------------------------------///
int main()
{
    ll k2,k3,k5,k6,ans=0;
    cin>>k2>>k3>>k5>>k6;
    ll mn=min(k2,min(k5,k6));
    k2-=mn;
    ans+=mn*256;
    ans+=min(k3,k2)*32;
    cout<<ans;
}