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

const int N=1e5+5, INF=1e9+5, mod=1e9+7;
int main(){
    int n, m, d;
    cin>>n>>d>>m;
    vector<int> V, V2;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        if(k<=m)V.pb(k);
        else V2.pb(k);
    }
    sort(all(V));
    sort(all(V2));
    reverse(all(V2));
    ll sum=0;
    for(int i:V)sum+=i;
    int k=0, l=V.size(), w=0;
    ll ans=0;
    while(l<=n+d){
        ans=max(ans, sum);
        if(k==V2.size())break;
        l+=d+1;
        sum+=V2[k++];
        if(l<=n+d)continue;
        while(l>n+d && w<V.size()){
            sum-=V[w];
            w++;
            l--;
        }
    }
    cout<<ans;
}