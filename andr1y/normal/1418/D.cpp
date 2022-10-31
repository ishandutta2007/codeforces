// keep calm and eat pizza.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 1e5+228;
multiset<ll, greater<ll>> dsts;
yree ks;
ll n, q;

void insert(ll p){
    if(!n){
        ks.insert(p);
        return;
    }

    ll pk = ks.order_of_key(p);
    if(pk-1>=0&&pk<ks.size()){
        ll vl = *ks.find_by_order(pk-1);
        ll vr = *ks.find_by_order(pk);
        dsts.erase(dsts.find(vr-vl));
        ks.insert(p);
        dsts.insert(p-vl);
        dsts.insert(vr-p);
    }else if(pk-1>=0&&pk==ks.size()){
        ll vl = *ks.find_by_order(pk-1);
        ks.insert(p);
        dsts.insert(p-vl);
    }else if(pk-1<0&&pk<ks.size()){
        ll vr = *ks.find_by_order(pk);
        ks.insert(p);
        dsts.insert(vr-p);
    }
}
void erase(ll p){
    ll pk = ks.order_of_key(p);
    ll pl = -1, pr = -1;
    if(pk-1>=0){
        ll vl = *ks.find_by_order(pk-1);
        ll vr = *ks.find_by_order(pk);
        dsts.erase(dsts.find(vr-vl));
        pl = vl;
    }
    if(pk+1<ks.size()){
        ll vl = *ks.find_by_order(pk);
        ll vr = *ks.find_by_order(pk+1);
        dsts.erase(dsts.find(vr-vl));
        pr = vr;
    }
    if(pl>=0&&pr>=0) dsts.insert(pr-pl);
    ks.erase(p);
}
ll find_res(){
    ll vl = *ks.find_by_order(0);
    ll vr = *ks.find_by_order(ks.size()-1);
    return vr-vl-*dsts.begin();
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for(ll a, i=0;i<n;i++){
        cin >> a;
        if(i) insert(a);
        else ks.insert(a);
    }
    cout<<find_res()<<'\n';
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a) insert(b), n++;
        else erase(b), n--;
        cout<<find_res()<<'\n';
    }
}