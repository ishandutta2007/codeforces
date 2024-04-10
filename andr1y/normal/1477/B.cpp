// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
pll a[N];
string s, f;
ll t[4*N], w[4*N];
void push(ll v, ll tl, ll tm, ll tr){
    if(tl==tr) return;
    if(w[v]){
        w[v]--;
        t[v+v] = w[v]*(tm-tl+1);
        t[v+v+1] = w[v]*(tr-tm);
        w[v+v] = w[v]+1;
        w[v+v+1] = w[v]+1;
        w[v]=0;
    }
}
void build(ll v, ll tl, ll tr){
    w[v]=0;
    if(tl==tr){
        t[v]=(f[tl]-'0');
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v+v, tl, tm);
    build(v+v+1, tm+1, tr);
    t[v]=t[v+v]+t[v+v+1];
}
void upd(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(tl>=l&&tr<=r){
        t[v] = val*(tr-tl+1);
        w[v] = val+1;
        return;
    }
    ll tm = (tl+tr)>>1;
    push(v, tl, tm, tr);
    if(tl<=r&&l<=tm) upd(v+v, tl, tm, l, r, val);
    if(tm+1<=r&&l<=tr) upd(v+v+1, tm+1, tr, l, r, val);
    t[v]=t[v+v]+t[v+v+1];
}
ll sum(ll v, ll tl, ll tr, ll l, ll r){
    if(tl>=l&&tr<=r){
        return t[v];
    }
    ll tm = (tl+tr)>>1;
    push(v, tl, tm, tr);
    ll e=0;
    if(tl<=r&&l<=tm) e+=sum(v+v, tl, tm, l, r);
    if(tm+1<=r&&l<=tr) e+=sum(v+v+1, tm+1, tr, l, r);
    return e;
}
bool check(ll v, ll tl, ll tr){
    if(tl==tr){
        return t[v]==s[tl]-'0';
    }
    ll tm = (tl+tr)>>1;
    push(v, tl, tm, tr);
    return check(v+v, tl, tm)&&check(v+v+1, tm+1, tr);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, qq;
        cin >> n >> qq >> s >> f;
        for(ll i = 0;i<qq;i++){
            cin >> a[i].x >> a[i].y;
            --a[i].x, a[i].y--;
        }
        build(1, 0, n-1);
        bool ok =1;
        for(ll i = qq-1;i>=0&&ok;i--){
            ll st = sum(1, 0, n-1, a[i].x, a[i].y);
            if(st+st==a[i].y-a[i].x+1) ok=0;
            if(st+st<a[i].y-a[i].x+1){
                upd(1, 0, n-1, a[i].x, a[i].y, 0);
            }else upd(1, 0, n-1, a[i].x, a[i].y, 1);
        }
        ok=ok&&check(1, 0, n-1);
        if(ok) cout<<"yes\n";
        else cout<<"no\n";
    }
}