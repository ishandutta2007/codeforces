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
    int n, m;
    cin>>n>>m;
    vii V(n), V2(m);
    for(int i=0; i<n; i++){
        cin>>V[i].st>>V[i].nd;
    }
    for(int i=0; i<m; i++){
        cin>>V2[i].st>>V2[i].nd;
    }
    vii vec;
    for(pii a:V){
        for(pii b:V2){
            if(a.st<=b.st && a.nd<=b.nd){
                vec.pb(mp(b.st-a.st, b.nd-a.nd));
            }
        }
    }
    sort(all(vec));
    reverse(all(vec));
    int ans=INF, M=-1;
    for(pii i:vec){
        if(i.nd>M){
            ans=min(ans, M+2+i.st);
            M=i.nd;
        }
    }
    ans=min(ans, M+1);
    cout<<ans;
}