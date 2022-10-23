#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;

int main()
{
    ll n,m,k,l;
    cin>>n>>m>>k>>l;
    ll x=(l+k+m-1)/m;
    if (x*m>n) cout<<-1; else cout<<x;
    return 0;
}