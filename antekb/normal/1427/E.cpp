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
const int K=50;
vl b(K), b2(K);
vll V;
vi V2;
constexpr int bits(ll x) { return 63-__builtin_clzll(x); }
void out(){
    cout<<V.size()<<"\n";
    //return;
    for(int k=0; k<V.size(); k++){
        cout<<V[k].st;
        if(V2[k])cout<<" + ";
        else cout<<" ^ ";
        cout<<V[k].nd<<"\n";
    }
}
void get(ll n, ll k){
    if(k==1)return;
    get(n, k/2);
    V.pb(mp(n*(k/2), n*(k/2)));
    V2.pb(1);
    if(k&1){
        V.pb(mp(n*(k-1), n));
        V2.pb(1);
    }
}
void gen(ll n){
    //cout<<n<<"\n";
    if(n==1){
        out();
        return;
    }
    ll m=1;
    while(m<n)m*=2;
    for(int i=0; i<K; i++){
        ll t=((m-1)/n)*n+n;
        if(((t+n)^t^(2*n)^n)<n && ((t+n)^t^(2*n)^n)){
            //cout<<t<<" "<<i<<" "<<m<<"\n";
            get(n, (m-1)/n+1);
            V2.pb(1);V2.pb(0);V2.pb(0);
            V.pb(mp(t, n));
            V.pb(mp(t+n, t));
            V.pb(mp(2*n, (t+n)^t));
            t=(t+n)^t^(2*n);
            if(t<n)gen(t);
            else{
                V2.pb(0);
                V.pb(mp(t, n));
                t^=n;
                int j=0;
                while(bits(t<<j)<bits(n)){
                    V2.pb(1);
                    V.pb(mp(t<<j, t<<j));
                    j++;
                }
                for(;j>=0; j--){
                    if((n^(t<<j))<n){
                        V2.pb(0);
                        V.pb(mp(n, t<<j));
                        n^=(t<<j);
                    }
                }
                gen(n);
            }
            return;
        }
        if(bits(m)>60)break;
        m*=2;
    }
    for(int i=2; i<n; i++){
        ll t=((i+1)*n)^(i*n);
        if((t^n)<n && (t^n)){
            get(n, i+1);
            V.pb(mp(i*n, (i+1)*n));
            V2.pb(0);

            if(t<n)gen(t);
            else{
                V2.pb(0);
                V.pb(mp(t, n));
                t^=n;
                int j=0;
                //cout<<t<<" "<<n<<"\n";
                while(bits(t<<j)<bits(n)){
                    //cout<<"b";
                    V2.pb(1);
                    V.pb(mp(t<<j, t<<j));
                    j++;
                }
                for(;j>=0; j--){
                    if((n^(t<<j))<n){
                        V2.pb(0);
                        V.pb(mp(n, t<<j));
                        n^=(t<<j);
                    }
                }
                gen(n);
                return;
            }
        }
    }
}
int main(){
    ll n;
    cin>>n;
    gen(n);
}