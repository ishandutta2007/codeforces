// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], up[N], res[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll s=0;
    for(ll i =0;i<n;i++) {cin >> a[i];s+=a[i];}
    priority_queue<pair<ll, ll>> pq;
    for(ll i = 0;i<n;i++){
        up[i] = 1;
        res[i]=a[i]*a[i];
        ll p = a[i]/2;
        ll p1 = a[i]%2;
        ll rc = res[i] - (p*p*(2-p1)+(p+1)*(p+1)*p1);
        pq.push({rc, i});
    }
    while(k-n){
        pair<ll, ll> e = pq.top(); pq.pop();
        ll rc = e.first, i = e.second;
        up[i]++;
        res[i]-=rc;
        ll p = a[i]/(up[i]+1);
        ll p1 = a[i]%(up[i]+1);
        rc = res[i] - (p*p*(up[i]+1-p1)+(p+1)*(p+1)*p1);
        pq.push({rc, i});
        n++;
    }
    ll er=0;
    for(ll i = 0;i<n;i++) er+=res[i];
    cout<<er;
}