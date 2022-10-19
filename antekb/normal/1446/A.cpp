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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        ll w;
        cin>>n>>w;
        vector<pair<ll, int> > V(n);
        for(int i=0; i<n; i++){
            cin>>V[i].st;
            V[i].nd=i;
        }
        sort(all(V));
        rev(V);
        ll s=0;
        vi V2;
        for(int i=0; i<n; i++){
            if(s+V[i].st<=w){
                s+=V[i].st;
                V2.pb(V[i].nd);
            }
        }
        if(s>=(w+1)/2){
            sor(V2);
            cout<<sz(V2)<<"\n";
            for(int i:V2)cout<<i+1<<" ";
            cout<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
}