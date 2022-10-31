// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll minv[4*N], maxv[4*N];
vector<ll> tops;
vector<pll> ass;
ll n;
ll ss=0;
ll mx[4*N][2];
ll bc(ll v, ll tl, ll tr){
    if(tr-tl==1) return 0;
    ll tm = (tl+tr)>>1;
    return bc(v+v, tl, tm)+bc(v+v+1, tm, tr)+min(tm-tl, tr-tm);
}
void build(ll v, ll tl, ll tr){
    if(tr-tl==1) {minv[v]=0, maxv[v]=0;return;}
    ll tm = (tl+tr)>>1;
    build(v+v, tl, tm);
    build(v+v+1, tm, tr);
    ll e = min(tm-tl, tr-tm);
    minv[v]=e, maxv[v]=tr-tl-1;
    tops.push_back(v);
    ss+=minv[v];
    mx[v][0]=tm-tl;
    mx[v][1]=tr-tm;
}
ll off=0;
string s;
vector<ll> restore(ll v, ll tl, ll tr){
    if(tr-tl==1) return {tl};
    ll tm = (tl+tr)>>1;
    vector<ll> v1=restore(v+v, tl, tm);
    vector<ll> v2=restore(v+v+1, tm, tr);
    /*for(auto &i : v2){
        i+=tm-tl;
    }*/
    vector<ll> v3(tr-tl);
    ll si = 0, sj=0, sk=0;
    for(ll i = ass[off].x;i<=ass[off].y;i++){
        if(s[i]=='0') v3[sk++]=v1[si++];
        else v3[sk++]=v2[sj++];
    }
    while(si<v1.size()){
        v3[sk++]=v1[si++];
    }
    while(sj<v2.size()){
        v3[sk++]=v2[sj++];
    }
    off++;
    return v3;
}
signed main(){
    //freopen("a.txt", "r", stdin);
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    /*for(ll i = 65530, j=0;j<20;i++, j++){
        ss=0;
        build(1, 0, i);
        cout<<ss<<' ';
    }*/
    cin>>s;

    for(n = 2;n<=1000;n++){
        ss=0, off=0, tops.clear(), ass.clear();
        build(1, 0, n);
        ll free=s.length()-ss;
        if(free<0) continue;
        ll pos=0;
        for(auto i : tops){
            ll lt = minv[i];
            ll ct = min(free, maxv[i]-minv[i]);
            ll c0=mx[i][0], c1=mx[i][1];
            for(ll j=0;j<lt;j++){
                if(s[pos+j]=='0') c0--;
                else c1--;
            }
            while(ct&&c0&&c1){
                if((s[pos+lt]=='0'&&c0)||(s[pos+lt]=='1'&&c1)){
                    if(s[pos+lt]=='0') c0--;
                    else c1--;
                    lt++;
                    ct--;
                    free--;
                }else break;
            }
            ass.push_back({pos, pos+lt-1});
            pos+=lt;
        }
        ll en = ass.size();
        ll pushto = s.length()-1;
        bool CAN = 1;
        for(ll i = en-1;i>=0&&CAN;i--){
            ll c0=mx[tops[i]][0], c1=mx[tops[i]][1];
            for(ll j=ass[i].x;j<=ass[i].y;j++){
                if(s[j]=='0') c0--;
                else c1--;
            }
            while(ass[i].y<pushto){
                ass[i].y++;
                if(s[ass[i].y]=='0') c0--;
                else c1--;
            }
            while(!(c0>=0&&c1>=0&&c0+c1>0&&( (s[ass[i].y]=='1'&&!c1) || (s[ass[i].y]=='0'&&!c0) )) && ass[i].x<=ass[i].y){
                if(s[ass[i].x]=='0') c0++;
                else c1++;
                ass[i].x++;
            }
            if(ass[i].x>ass[i].y) CAN=0;
            pushto=ass[i].x-1;
        }
        if(!CAN||ass[0].x>0) continue;
        vector<ll> res1 = restore(1, 0, n);
        vector<ll> res(n);
        for(ll i = 0;i<n;i++) res[res1[i]]=i;
        for(auto &i :res) i++;
        cout<<res.size()<<'\n';
        for(auto i:res)cout<<i<<' ';
        break;
    }
}