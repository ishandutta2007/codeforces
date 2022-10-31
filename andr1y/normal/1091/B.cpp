#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define pb push_back
#define mp make_pair
pair<ll, ll> a[1000];
vector<pair<ll, ll> > b[1000];
int main(){
    ll n, e, r;
    cin >> n;
    for(ll i=0;i<n;i++) cin >> a[i].x >> a[i].y;
    for(ll i=0;i<n;i++){
        cin >> e >> r;
        if(i==0)
            for(ll j=0;j<n;j++) b[i].pb(mp(a[j].x + e, a[j].y+r));
        else
            for(ll j=0;j<n;j++)
                if(find(b[i-1].begin(), b[i-1].end(), mp(a[j].x + e, a[j].y+r)) != b[i-1].end()) b[i].pb(mp(a[j].x + e, a[j].y+r));

    }
    cout << b[n-1][0].x << " " << b[n-1][0].y;
}