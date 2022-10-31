// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef long double ld;
const ll N = 1e5+1488;
const ld PI = 3.1415926535897932384626433832795;
ll a[N];
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> uid(1ll, 148814881489ll);
struct dk{
    ll x, y, v, mpd;
    dk *l = nullptr, *r = nullptr;
    dk(ll x, ll v) : x(x), y(uid(gen)), v(v), mpd(v) {}
    void upd(){
        mpd = v;
        if(l) mpd=max(mpd, l->mpd);
        if(r) mpd=max(mpd, r->mpd);
    }
};
dk* merge(dk *a, dk *b){
    if(!a) return b;
    if(!b) return a;
    if(a->y>b->y){
        a->r=merge(a->r, b);
        a->upd();
        return a;
    }else{
        b->l=merge(a, b->l);
        b->upd();
        return b;
    }
}
pair<dk*, dk*> split(dk *a, ll k){ // strict less k
    if(!a) return {nullptr, nullptr};
    if(a->x<k){
        auto p = split(a->r, k);
        a->r = p.first;
        a->upd();
        return {a, p.second};
    }else{
        auto p = split(a->l, k);
        a->l = p.second;
        a->upd();
        return {p.first, a};
    }
}
dk *root;
void insert(ll ob, ll dp){
    dk *v = new dk(ob, dp);
    auto p1 = split(root, ob);
    root = merge(p1.first, merge(v, p1.second));
}
ll getmax(ll r){
    auto p = split(root, r);
    ll s=0;
    if(p.first) s=p.first->mpd;
    root=merge(p.first, p.second);
    return s;
}
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        ll aa, b;
        cin >> aa >> b;
        a[i]=aa*aa*b;
        ll v = getmax(a[i])+a[i];
        insert(a[i], v);
    }
    ld v = root->mpd;
    v*=PI;
    cout<<fixed<<setprecision(10)<<v;
}