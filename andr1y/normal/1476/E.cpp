// ++ //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
typedef long long ll;
using namespace std;
const ll N = 1e5+228;
map<string, ll> ek;
set<ll> d[N], r[N];
vector<ll> res;
bool was[N];
ll it[N];
bool o2=1;
ll pw[N];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, q, k;
    cin >> n >> q >> k;
    for(ll i = 0;i<n;i++){
        string tmp;
        cin >> tmp;
        ek[tmp]=i;
    }
    while(q--){
        string sq;
        cin >> sq;
        vector<ll> ok;
        for(ll mask=0;mask<(1<<k);mask++){
            string ts=sq;
            for(ll i = 0;i<k;i++) if((mask>>i)&1) ts[i]='_';
            if(ek.count(ts)) ok.push_back({ek[ts]});
        }
        ll ep;
        cin >> ep;
        ep--;
        bool o=0;
        for(auto i : ok){
            if(i==ep) o=1;
            else d[ep].insert(i), r[i].insert(ep);
        }
        if(!o){
            cout<<"NO";
            return 0;
        }
    }
    //cerr<<"edges:\n";
    //for(ll i = 0;i<n;i++){
       // for(auto j : d[i]) cerr<<i+1<<' '<<j+1<<'\n';
    //}

    set<pll> st;
    for(ll i = 0;i<n;i++) pw[i]=d[i].size(), st.insert({pw[i], i});
    vector<ll> eee;
    for(ll i = 0;i<n;i++){
        pll e = *st.begin(); st.erase(st.begin());
        eee.push_back(e.y+1);
        if(e.x!=0){
            o2=0;
            break;
        }
        for(auto j : r[e.second]){
            st.erase({pw[j], j});
            --pw[j];
            st.insert({pw[j], j});
        }
    }
    if(!o2) return cout<<"NO", 0;
    cout<<"YES\n";
    for(ll i = n-1;i>=0;i--) cout<<eee[i]<<' ';
}