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
const ld INF=1e18;
const int N=2e5+5, mod=1e9+7;
vector<pair<pii, ll> > V;
ld sect(int A1, ll B1, int A2, ll B2){
    ld t=B1-B2;
    t/=A1-A2;
    return -t;
}
vi H;
vector<ld> H2;
vl dp;
void add(int i){
    ld t=INF;
    while(!H.empty()){
        t=sect(-V[H.back()].st.st, dp[H.back()], -V[i].st.st, dp[i]);
        if(t>H2.back()){
            H.pop_back();
            H2.pop_back();
        }
        else break;
    }
    H.pb(i);
    H2.pb(t);
    //cout<<t<<" "<<H.size()<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    V.resize(n+1);
    ll ans=0;
    for(int i=1; i<=n; i++){
        cin>>V[i].st.st>>V[i].st.nd>>V[i].nd;
        //V[i].nd=0;
        //V[i].st.st=i;
        //V[i].st.nd=n+1-i;
    }
    sort(all(V));
    dp.pb(0);
    add(0);
    int wsk=0;
    for(int i=1; i<=n; i++){
        ll a=V[i].st.st*1ll*V[i].st.nd-V[i].nd;
        //deb(a, V[i].st.st, V[i].st.nd, V[i].nd);
        while(wsk<H.size() && H2[wsk]>V[i].st.nd)wsk++;
        wsk--;
        a=a-V[H[wsk]].st.st*1ll*V[i].st.nd+dp[H[wsk]];
        //cout<<i<<" "<<H[k]<<"\n";
        ans=max(ans, a);
        //cout<<a<<" "<<wsk<<"\n";
        dp.pb(a);
        add(i);
    }
    cout<<ans;
}