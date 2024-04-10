// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll type[N];
ll convert(string s){
    if(s[0]=='l') return 0;
    if(s[0]=='u') return 1;
    if(s[0]=='r') return 2;
    if(s[0]=='o') return 3;
    if(s[0]=='y') return 4;
    if(s[0]=='g') return 5;
    if(s[0]=='b') return 6;
    if(s[0]=='i') return 7;
    if(s[0]=='v') return 8;
}
string convert(ll a){
    if(a==0) return "lock";
    if(a==1) return "unlock";
    if(a==2) return "red";
    if(a==3) return "orange";
    if(a==4) return "yellow";
    if(a==5) return "green";
    if(a==6) return "blue";
    if(a==7) return "indigo";
    if(a==8) return "violet";
}
ll t[4*N][2];
ll last[4*N][2];
void comb(ll v){
    t[v][0]=t[v+v][0];
    if(last[v+v][0]>last[v+v][1]){
        if(t[v+v+1][1]!=-1) t[v][0]=t[v+v+1][1];
    }else{
        if(t[v+v+1][0]!=-1) t[v][0]=t[v+v+1][0];
    }

    t[v][1]=t[v+v][1];
    if(last[v+v][0]>last[v+v][1]||last[v+v][1]==-1){
        if(t[v+v+1][1]!=-1) t[v][1]=t[v+v+1][1];
    }else{
        if(t[v+v+1][0]!=-1) t[v][1]=t[v+v+1][0];
    }

    last[v][0]=max(last[v+v][0], last[v+v+1][0]);
    last[v][1]=max(last[v+v][1], last[v+v+1][1]);
}
void build(ll v, ll tl, ll tr){
    if(tl==tr){
        t[v][0]=-1, t[v][1]=-1;
        last[v][0]=-1, last[v][1]=-1;
        if(type[tl]==0)last[v][0]=tl;
        else if(type[tl]==1) last[v][1]=tl;
        else{
            t[v][0]=type[tl];
            t[v][1]=-1;
        }
        return;
    }
    ll tm= (tl+tr)>>1;
    build(v+v, tl, tm);
    build(v+v+1, tm+1, tr);
    comb(v);
}
void upd(ll v, ll tl, ll tr, ll pos){
    if(tl==tr){
        t[v][0]=-1, t[v][1]=-1;
        last[v][0]=-1, last[v][1]=-1;
        if(type[tl]==0)last[v][0]=tl;
        else if(type[tl]==1) last[v][1]=tl;
        else{
            t[v][0]=type[tl];
            t[v][1]=-1;
        }
        return;
    }
    ll tm= (tl+tr)>>1;
    if(pos<=tm) upd(v+v, tl, tm, pos);
    else upd(v+v+1, tm+1, tr, pos);
    comb(v);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
    //vals.insert(0);
    type[0]=6;
    for(ll i = 1;i<=n;i++){
        string s;cin>>s;
        type[i]=convert(s);
        /*if(type[i]==0) lk.insert(i);
        else if(type[i]==1) ulk.insert(i);
        else vals.insert(i);*/
    }
    build(1, 0, n);
    cout<<convert(t[1][0])<<'\n';
    ll q;
    cin >> q;
    while(q--){
        ll pos;string s;cin>>pos>>s;
        type[pos]=convert(s);
        upd(1, 0, n, pos);
        cout<<convert(t[1][0])<<'\n';
    }
}