//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> uid(1ll, 148814881489ll);
struct dk{
    ll x, y, v, pd;
    dk *l = nullptr, *r = nullptr;
    dk(ll x, ll v): x(x), y(uid(gen)), v(v), pd(v){}
    void upd(){
        pd = v+(l?l->pd:0)+(r?r->pd:0);
    }
};
dk* merge(dk *a, dk *b){
    if(!a) return b;
    if(!b) return a;
    if(a->y > b->y){
        a->r = merge(a->r, b);
        a->upd();
        return a;
    }else{
        b->l = merge(a, b->l);
        b->upd();
        return b;
    }
}
pair<dk*, dk*> split(dk *a, ll x){
    if(!a) return {nullptr, nullptr};
    if(a->x <= x){
        auto p = split(a->r, x);
        a->r = p.first;
        a->upd();
        return {a, p.second};
    }else{
        auto p = split(a->l, x);
        a->l = p.second;
        a->upd();
        return {p.first, a};
    }
}
ll fl(dk* &a){
    if(a->l && a->l->pd) return fl(a->l);
    if(a->v){
        a->v--;
        a->pd--;
        return a->x;
    }
    if(a->r && a->r->pd) return fl(a->r);
    return -1;
}
dk *root;
ll grof(ll x){
    auto p = split(root, x);
    ll an = -1;
    if(!p.second || !p.second->pd) an = fl(p.first);
    else an = fl(p.second);
    root = merge(p.first, p.second);
    return an;
}
map<ll, ll> ck;
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        ck[a[i]]++;
    }
    for(auto i : ck){
        dk *a = new dk(i.first, i.second);
        root = merge(root, a);
    }
    sort(a, a+n);
    ll ak = 0;
    for(ll i = 0;i<n;i++){
        ll v = grof(a[i]);
        if(v > a[i]) ++ak;
    }
    cout << ak << '\n';
}