// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll n, a[N], wss[N], tq=0;
vector<ll> an;
ll find_mex(ll with){
    if(with!=-1)an.push_back(with);
    ++tq;
    for(ll i = 0;i<n;i++){
        wss[a[i]]=tq;
    }
    for(ll i =0;i<=n;i++){
        if(wss[i]!=tq) return i;
    }
}
void db(){
    for(ll i = 0;i<n;i++) cerr<<a[i]<<' ';
    cerr<<'\n';
}
bool isok(){
    for(ll i = 1;i<n;i++) if(a[i]<a[i-1]) return 0;
    return 1;
}
bool was[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        an.clear();
        cin >> n;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            was[i]=0;
        }
//        was[n]=0;
//        for(ll i = 0;i<n;i++){
//            if(was[a[i]]){
//                a[i]=find_mex(i);
//            }
//            was[a[i]]=1;
//        }
////        db();
//        ll fz=0;
//        while(fz<n&&a[fz]!=0)fz++;
//        if(fz!=n){
//            a[fz]=find_mex(fz);
//        }
////        db();
//        for(ll qq = 0;qq<n;qq++){
//            if(a[qq]==qq) continue;
//            ll fp=0;
//            while(fp<n&&a[fp]!=qq) fp++;
//            if(fp!=n){
//                a[fp]=n;
//                an.push_back(fp+1);
//            }
//            ll nxt = qq;
//            while(nxt<n){
//                ll nn = a[nxt];
//                a[nxt]=find_mex(nxt);
//                nxt=nn;
//            }
//        }
        for(ll r=0;r<n+n;r++){
            ll mx = find_mex(-1);
            a[mx]=mx;
            if(mx==n) break;
            an.push_back(mx);
        }
        while(!isok()){
            ll fn=0;
            while(a[fn]==fn)fn++;
            ll pfn=0;
            while(a[pfn]!=fn) pfn++;
            a[pfn]=n;
            an.push_back(pfn);
            ll nxt = fn;
            while(nxt<n){
                ll nn = a[nxt];
                a[nxt]=find_mex(nxt);
                nxt=nn;
            }
        }
        cout<<an.size()<<'\n';
        for(auto i :an) cout<<i+1<<' ';
        cout<<'\n';
//        db();
    }
}