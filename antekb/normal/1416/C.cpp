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

const int N=(1<<19), INF=1e9+5, mod=1e9+7;
int tab[2*N];
int upd(int a){
    int sum=0;
    for(a+=N; a>0; a/=2){
        if((a&1)==0){sum+=tab[a+1];}
        tab[a]++;
    }
    return sum;
}
void Clear(){
    for(int i=0; i<2*N; i++)tab[i]=0;
}
ll Count(vi V){
    vector<pii> V2;
    for(int i=0; i<V.size(); i++){
        V2.push_back(mp(V[i], i));
    }
    sort(all(V2));
    ll ans=0;
    for(int i=0; i<V.size(); i++){
        //cout<<V2[i].nd<<" ";
        ans+=upd(V2[i].nd);
    }
    //cout<<"\n";
    Clear();
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vi V(n);
    for(int i=0; i<n; i++){
        cin>>V[i];
    }
    int ans=0;
    ll akt=Count(V);
    for(int x=(1<<30); x>0; x/=2){
        for(int i=0; i<n; i++)V[i]^=x;
        ll k=Count(V);
        if(k>=akt)for(int i=0; i<n; i++)V[i]^=x;
        else {akt=k; ans^=x;}
    }
    cout<<akt<<" "<<ans;
}