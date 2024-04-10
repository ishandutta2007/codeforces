#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define x first
#define y second
const ll N = 1e5+228;
vector<pll> lft;
vector<pll> rgh;
vector<ll> t[2][4*N];
void build(ll tn, ll v, ll tl, ll tr){
    if(tl==tr){
        t[tn][v].push_back((tn==0?lft[tl]:rgh[tl]).y);
        return;
    }
    ll tm = (tl+tr)>>1;
    build(tn, v+v, tl, tm);
    build(tn, v+v+1, tm+1, tr);
    t[tn][v].resize(tr-tl+1);
    merge(t[tn][v+v].begin(), t[tn][v+v].end(), t[tn][v+v+1].begin(), t[tn][v+v+1].end(), t[tn][v].begin());
}
ll countlessequal(ll tn, ll v, ll tl, ll tr, ll pr, ll lth){
    if(tr<=pr){
        return upper_bound(t[tn][v].begin(), t[tn][v].end(), lth)-t[tn][v].begin();
    }
    ll tm = (tl+tr)>>1;
    if(pr<=tm) return countlessequal(tn, v+v, tl, tm, pr, lth);
    else return countlessequal(tn, v+v, tl, tm, pr, lth) + countlessequal(tn, v+v+1, tm+1, tr, pr, lth);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll h, v;
	cin >> h >> v;
	ll c=1;
	for(ll i = 0;i<h;i++){
        ll y, x1, x2;
        cin >> y >> x1 >> x2;
        if(x1==0&&x2==1000000){
            c++;
        }
        if(x1==0){
            lft.push_back({x2, y});
        }else if(x2==1000000){
            rgh.push_back({1000000-x1, y});
        }
	}
	sort(begin(lft), end(lft), greater<pll>());
	sort(begin(rgh), end(rgh), greater<pll>());
    ll ln = lft.size(), rn=rgh.size();
    if(ln) build(0, 1, 0, ln-1);
    if(rn) build(1, 1, 0, rn-1);
    for(ll i = 0;i<v;i++){
        ll x, y1, y2;
        cin >> x >> y1 >> y2;
        ll e = (y1==0?1:0)+(y2==1000000?1:0);
        if(ln){
            ll l = 0, r = ln;
            while(r-l>1){
                ll m = (l+r)>>1;
                if(lft[m].x<x) r=m;
                else l=m;
            }
            if(lft[l].x>=x){
                e+=countlessequal(0, 1, 0, ln-1, l, y2);
                e-=countlessequal(0, 1, 0, ln-1, l, y1-1);
            }
        }
        if(rn){
            ll l = 0, r = rn;
            ll rk = 1000000-x;
            while(r-l>1){
                ll m = (l+r)>>1;
                if(rgh[m].x<rk) r=m;
                else l=m;
            }
            if(rgh[l].x>=rk){
                e+=countlessequal(1, 1, 0, rn-1, l, y2);
                e-=countlessequal(1, 1, 0, rn-1, l, y1-1);
            }
        }
        c+=e-1;
    }
    cout<<c;
}