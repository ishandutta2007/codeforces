#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace std;

const ll maxn=4e5+500;
const ll mod=1e9+7;
const ll inf=1e18+500;
int ali;
ll a[maxn];

int main()
{ali++;
    ll n;
    cin>>n;ali++;
    for(ll i=0;i<2*n;i++){
        cin>>a[i];ali++;
    }
    sort(a,a+2*n);
    ll ans=inf;ali++;
    multiset<ll> stx;ali++;
    multiset<ll> sty;
    for(ll i=0;i<n;i++){ali++;
        stx.insert(a[i]);
    }
    for(ll i=n;i<2*n;i++){
        sty.insert(a[i]);ali++;
    }
    for(ll i=0;i<n;i++){ali++;
        ans=min(ans,((*stx.rbegin())-(*stx.begin()))*((*sty.rbegin())-(*sty.begin())));
        stx.erase(stx.find(a[i]));ali++;
        stx.insert(a[i+n]);ali++;

        sty.erase(sty.find(a[i+n]));ali++;
        sty.insert(a[i]);ali++;
    }

    cout<<ans;ali++;
}