#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin>>n>>k;
    vi V(n), cnt(n, 1);
    for(int &i:V)cin>>i;
    priority_queue<pair<ll, int> > Q;
    for(int i=0; i<sz(V); i++){
        ll act=(V[i]/cnt[i]+1)*1ll*(V[i]/cnt[i]+1)*(V[i]%cnt[i])+(V[i]/cnt[i])*1ll*(V[i]/cnt[i])*(cnt[i]-(V[i]%cnt[i]));
        cnt[i]++;
        ll nxt=(V[i]/cnt[i]+1)*1ll*(V[i]/cnt[i]+1)*(V[i]%cnt[i])+(V[i]/cnt[i])*1ll*(V[i]/cnt[i])*(cnt[i]-(V[i]%cnt[i]));
        cnt[i]--;
        Q.push(mp(-nxt+act, i));
    }
    while(k>n){
        int i=Q.top().nd;
        Q.pop();
        cnt[i]++;
        ll act=(V[i]/cnt[i]+1)*1ll*(V[i]/cnt[i]+1)*(V[i]%cnt[i])+(V[i]/cnt[i])*1ll*(V[i]/cnt[i])*(cnt[i]-(V[i]%cnt[i]));
        cnt[i]++;
        ll nxt=(V[i]/cnt[i]+1)*1ll*(V[i]/cnt[i]+1)*(V[i]%cnt[i])+(V[i]/cnt[i])*1ll*(V[i]/cnt[i])*(cnt[i]-(V[i]%cnt[i]));
        cnt[i]--;
        Q.push(mp(-nxt+act, i));
        k--;
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        //cout<<cnt[i]<<"\n";
        ans+=(V[i]/cnt[i]+1)*1ll*(V[i]/cnt[i]+1)*(V[i]%cnt[i]);
        //cout<<ans<<" ";
        ans+=(V[i]/cnt[i])*1ll*(V[i]/cnt[i])*(cnt[i]-(V[i]%cnt[i]));
    }
    cout<<ans;
}