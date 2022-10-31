// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll M = 1e9+7;
pll cnt[10];
ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return (a*bpm(a*a, b>>1))%M;
    else return bpm(a*a, b>>1);
}
pair<ll, string> qs[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	for(ll i = 0;i<10;i++) cnt[i]={i, 1};
    string s;
    cin >> s;
    ll q;cin >> q;string es;getline(cin, es);
    for(ll i = 0;i<q;i++){
        getline(cin, es);
        char placeto=es[0];
        string ks;
        for(ll i =3;i<es.size();i++) ks.push_back(es[i]);
        qs[i]={placeto-'0', ks};
    }
    for(ll i = q-1;i>=0;i--){
        string &ks = qs[i].y;
        ll onmod=0;
        ll almod=0;
        for(ll i = ks.size()-1;i>=0;i--){
            ll e = ks[i]-'0';
            ll u = (cnt[e].x*bpm(10, onmod))%M;
            onmod=(onmod+cnt[e].y)%(M-1);
            almod=(almod+u)%M;
        }
        cnt[qs[i].x]={almod, onmod};
    }
    ll onmod=0;
    ll almod=0;
    for(ll i = s.size()-1;i>=0;i--){
        ll e = s[i]-'0';
        ll u = (cnt[e].x*bpm(10, onmod))%M;
        onmod=(onmod+cnt[e].y)%(M-1);
        almod=(almod+u)%M;
    }
    cout<<almod;
}