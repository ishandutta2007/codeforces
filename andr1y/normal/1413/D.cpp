// -- //
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
pair<ll, ll> a[N];
vector<ll> rr;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll e, i = 0;i<n+n;i++){
        char c;
        cin >> c;
        if(c=='+') a[i]={1,1};
        else{
            cin >> e;
            a[i]={-1, e};
        }
    }
    set<ll> e;
    for(ll i = n+n-1;i>=0;i--){
        if(a[i].x==1){
            if(e.size()==0) return cout<<"NO", 0;
            rr.push_back(*e.begin());
            e.erase(e.begin());
        }else{
            ll mn = LLONG_MAX;
            if(e.size()) mn=*e.begin();
            if(a[i].y>mn) return cout<<"NO", 0;
            e.insert(a[i].y);
        }
    }
    reverse(begin(rr), end(rr));
    cout<<"YES\n";
    for(auto i :rr) cout<<i<<' ';
}