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

const int N=23, INF=1e9+5, mod=1e9+7;
vii E[N];
int rng[N];
int main(){
    rng[N-1]=1;
    for(int i=N-2; i>0; i--){
        rng[i]=rng[i+1]*2;
        if(i==N-2)rng[i]=1;
        for(int j=N-1; j>i; j--){
            E[i].pb(mp(j, rng[j]));
        }
    }
    int l, r;
    cin>>l>>r;
    int k=r-l;
    E[0].pb(mp(N-1, l));
    for(int i=N; i>=0; i--){
        if(k>=(1<<i)){
            E[0].pb(mp(N-2-i, l));
            k-=(1<<i);
            l+=(1<<i);
        }
    }
    cout<<"YES\n";
    int n=N, m=0;
    for(int i=0; i<N; i++)m+=sz(E[i]);
    cout<<n<<" "<<m<<"\n";
    for(int i=0; i<N; i++)for(pii j:E[i])cout<<i+1<<" "<<j.st+1<<" "<<j.nd<<"\n";
}