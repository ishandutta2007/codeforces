#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
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
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string t;
    cin>>t;
    int n=t.size();
    ll ans=0;
    ll sum=0;
    for(int i=0; i<n; i++)sum+=t[i]-'0';
    ll pot=1;
    ll wsp=0;
    for(int i=n-1; i>=0; i--){
        ans+=((sum*wsp)%mod)*pot;
        ans%=mod;
        if(i!=n-1)pot=(pot*10)%mod;
        ans+=((((t[i]-'0')*pot)%mod)*((i*1ll*(i+1)/2)%mod))%mod;
        ans%=mod;
        sum-=t[i]-'0';
        wsp++;
    }
    cout<<ans;
}