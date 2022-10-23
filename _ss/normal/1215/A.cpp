#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    pii a,b;
    int n;
    cin>>a.fi>>b.fi>>a.se>>b.se>>n;
    if (a.se>b.se) swap(a,b);
    cout<<max(0,n-a.fi*(a.se-1)-b.fi*(b.se-1))<<" ";
    if (n>a.fi*a.se) cout<<(n-a.fi*a.se)/b.se+a.fi;
    else cout<<n/a.se;
    return 0;
}