#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
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
vi V(1<<20), czy(1<<20);
int h, g;
bool check(int i){
    if(i>=(1<<g))return V[i]>0;
    if(V[2*i]>V[2*i+1])return check(2*i);
    else return check(2*i+1);
}
int propagate(int i){
    int k=V[i];
    V[i]=0;
    if(i< (1<<(h-1))){
        if(V[2*i]>V[2*i+1])V[i]=propagate(2*i);
        else V[i]=propagate(2*i+1);
    }
    return k;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        cin>>h>>g;
        ll ans=0;
        for(int i=1; i<(1<<h); i++){cin>>V[i];ans+=V[i];}
        int r=1;
        vi V2;
        for(;r<(1<<g);r++){
            //cout<<"\n"<<r<<"\n";
            while(check(r)){
                //cout<<"a";
                V2.pb(r);
                ans-=V[r];
                propagate(r);
            }
        }
        cout<<ans<<"\n";
        for(int i:V2)cout<<i<<" ";
        cout<<"\n";
    }
}