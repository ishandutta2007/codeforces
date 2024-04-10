// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, p, r;
    cin >> n >> p;
    r=n;
    for(ll e, i = 0;i<p;i++){
        cin >> e;
        if(!a[e]) r--;
        a[e]=1;
    }
    cin >> p;
    for(ll e, i = 0;i<p;i++){
        cin >> e;
        if(!a[e]) r--;
        a[e]=1;
    }
    if(r) cout<<"Oh, my keyboard!";
    else cout<<"I become the guy.";
}