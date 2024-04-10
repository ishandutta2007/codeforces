//password1488
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 5e5+228;
vector<ll> d[N];
pair<ll, ll> b[N];
bool st[N];
ll mv[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll a, b, i = 0;i<m;i++){
        cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    for(ll i = 0;i<n;i++){
        cin >> b[i].first;
        b[i].second = i+1;
        mv[i+1]=0;
    }
    sort(b, b+n);
    bool ok =1;
    for(ll i = 0;i<n&&ok;i++){
        ll vb = b[i].first, p = b[i].second;
        map<ll, bool> fmx;
        for(auto j : d[p]){
            fmx[mv[j]]=1;
        }
        ll mk = 1;
        while(fmx.count(mk)) mk++;
        mv[p]=mk;
        if(mk!=vb){
            ok=0;
            break;
        }
        st[p]=1;
    }
    if(ok) {
        for(ll i = 0;i<n;i++) cout<<b[i].second<<' ';
    }else cout<<"-1";
}