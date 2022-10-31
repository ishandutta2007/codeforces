// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 150005;
const ll inf = 0x3fff3fff3fff3fff;
pll a[N], b[N], c[N], d[N];
ll pa[N], pb[N], pc[N], pd[N];
vector<ll> dab[N], dbc[N], dcd[N];
pll dpd[N], dpc[N], dpb[N], dpa[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    for(ll i = 0;i<n1;i++) {a[i].y=i; cin >> a[i].x;}
    for(ll i = 0;i<n2;i++) {b[i].y=i; cin >> b[i].x;}
    for(ll i = 0;i<n3;i++) {c[i].y=i; cin >> c[i].x;}
    for(ll i = 0;i<n4;i++) {d[i].y=i; cin >> d[i].x;}
    //sort(a, a+n1, greater<pll>());
    //sort(b, b+n2, greater<pll>());
    //sort(c, c+n3, greater<pll>());
    sort(d, d+n4);
    //for(ll i = 0;i<n1;i++) pa[a[i].y]=i;
    //for(ll i = 0;i<n2;i++) pb[b[i].y]=i;
    //for(ll i = 0;i<n3;i++) pc[c[i].y]=i;
    for(ll i = 0;i<n4;i++) pd[d[i].y]=i;
    ll m1, m2, m3;
    cin >> m1;for(ll ba, bb, i = 0;i<m1;i++){cin >> ba >> bb; --ba, --bb; dab[ba].push_back(bb);}
    cin >> m2;for(ll bb, bc, i = 0;i<m2;i++){cin >> bb >> bc; --bb, --bc; dbc[bb].push_back(bc);}
    cin >> m3;for(ll bc, bd, i = 0;i<m3;i++){cin >> bc >> bd; --bc, --bd; dcd[bc].push_back(bd);}
    for(ll i = 0;i<n4;i++) dpd[i] = d[i];
    for(ll i = 0;i<n3;i++){
        sort(begin(dcd[i]), end(dcd[i]), [](ll a, ll b){
            return pd[a]<pd[b];
        });
        dpc[i].y=i;
        ll r=0;
        for(auto j : dcd[i]){
            if(dpd[r].y==j) r++;
            else break;
        }
        if(r==n4) dpc[i].x=inf;
        else dpc[i].x=c[i].x+dpd[r].x;
    }
    sort(dpc, dpc+n3);
    for(ll i = 0;i<n3;i++) pc[dpc[i].y]=i;
    for(ll i = 0;i<n2;i++){
        sort(begin(dbc[i]), end(dbc[i]), [](ll a, ll b){
            return pc[a]<pc[b];
        });
        dpb[i].y=i;
        ll r=0;
        for(auto j : dbc[i]){
            if(dpc[r].y==j) r++;
            else break;
        }
        if(r==n3) dpb[i].x=inf;
        else dpb[i].x=b[i].x+dpc[r].x;
    }
    sort(dpb, dpb+n2);
    for(ll i = 0;i<n2;i++) pb[dpb[i].y]=i;
    for(ll i = 0;i<n1;i++){
        sort(begin(dab[i]), end(dab[i]), [](ll a, ll b){
            return pb[a]<pb[b];
        });
        dpa[i].y=i;
        ll r=0;
        for(auto j : dab[i]){
            if(dpb[r].y==j) r++;
            else break;
        }
        if(r==n2) dpa[i].x=inf;
        else dpa[i].x=a[i].x+dpb[r].x;
    }
    sort(dpa, dpa+n1);
    if(dpa[0].x>=inf) cout<<-1;
    else cout<<dpa[0].x<<'\n';
}