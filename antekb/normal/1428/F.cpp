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

const int N=5e5+5, INF=1e9+5, mod=1e9+7;
int pref[N], tab[N];
ll dp[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    str t;
    cin>>t;
    for(int i=0; i<n; i++){
        tab[i+1]=(t[i]=='1');
    }
    int l=0;
    for(int i=1; i<=n; i++){
        if(tab[i])l++;
        else l=0;
        pref[i]=max(pref[i-1], l);
    }
    l=0;
    vii V;
    for(int i=0; i<=n; i++){
        if(tab[i])l++;
        else{
            V.pb(mp(l, i-1));
            l=0;
        }
        if(tab[i]==0){
            dp[i]=dp[i-1];
            continue;
        }
        while(V.size() && l>=V.back().st){
            V.pop_back();
        }
        dp[i]=l*1ll*(l+1)/2;
        if(!V.size()){
            dp[i]+=l*1ll*(i-l);
        }
        else{
            dp[i]=l*1ll*l;
            dp[i]+=dp[V.back().nd];
            dp[i]+=l*1ll*(i-l-V.back().nd);
        }
    }
    ll sum=0;
    for(int i=1; i<=n; i++){
        sum+=dp[i];
        //cout<<dp[i]<<" ";
    }
    cout<<sum;
}