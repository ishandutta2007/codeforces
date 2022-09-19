#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;

ll nex[MAXN];

ll vis[MAXN];
ll ind[MAXN];
vector<ll> vi;

vector<ll> an;

ll m2[MAXN];

int main(){
    m2[0] = 1;
    for(int i =1;i<MAXN;i++) m2[i] = (m2[i-1] * 2ll) % MOD;

    fill(ind, ind+MAXN, -1);
    ll n;
    cin >> n;
    ll g = n;
    for(int i =0;i<n;i++) cin >> nex[i];
    ll po =0;
    ll l = 0;
    while(true){
        po = l;
        while(vis[po] == 1 and po < n)po++;
        l = po;
        if(po == n)break;
        while(true){
            //debug(n);
            if(ind[po] != -1){
                an.pb(vi.size() - ind[po]);
                g -= (vi.size() - ind[po]);
                break;
            } else {
                if(vis[po] == 1) break;
                ind[po] = vi.size();
                vi.pb(po);
                vis[po] = 1;
                po = nex[po] - 1;
            }
        }
        while(vi.size() > 0) {
            ind[vi.back()] = -1;
            vi.pop_back();
        }
    }
    //debug(g);
    ll ans = m2[g];
    while(an.size() > 0){
        //debug(an.back());
        ans = (((ans * (m2[an.back()] - 2ll))%MOD) + MOD)%MOD;
        an.pop_back();
    }
    cout << ans;
    return 0;
}

/*
*/