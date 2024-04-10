// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], eac=0;
map<ll, ll> cnt;
pll ea[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        eac=0;
        cnt.clear();
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(auto i : cnt){
            ea[eac++]={i.y, i.x};
        }
        sort(ea, ea+eac);
        ll summ=n;
        ll res=n;
        for(ll i = 0;i<eac;i++){
            if(i&&ea[i].x==ea[i-1].x){
                summ-=ea[i].x;
                continue;
            }
            res=min(res, n-summ+summ-ea[i].x*(eac-i));
            summ-=ea[i].x;
        }
        cout<<res<<'\n';
    }
}