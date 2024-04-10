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
int r[N];
int find(int v){
    if(r[v]==v)return v;
    return r[v]=find(r[v]);
}
int main(){
    int n, m;
    cin>>n>>m;
    vi c(n+m);
    for(int i=0; i<n+m; i++){
        cin>>c[i];
        r[i+1]=i+1;
    }
    vector<pair<int, pii> > E;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        for(int j=0; j<k; j++){
            int l;
            cin>>l;
            E.pb(mp(c[i]+c[l+n-1], mp(i+1, l+n)));
        }
    }
    sort(all(E));
    reverse(all(E));
    ll sum=0;
    for(auto i:E){
        //cout<<i.st<<"\n";
        sum+=i.st;
        if(find(i.nd.st)!=find(i.nd.nd)){
            r[find(i.nd.st)]=find(i.nd.nd);
            sum-=i.st;
        }
    }
    cout<<sum;
}