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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vi V(n);
    vii V2, V3, V4;
    for(int i=0; i<n; i++){
        cin>>V[i];
    }
    int wsk=n;
    for(int i=n-1; i>=0; i--){
        if(V[i]==1){
            V3.pb(mp(wsk, i));
            V2.pb(mp(wsk, i));
            wsk--;
        }
        else{
            if(V[i]==0)continue;
            if(V[i]==2){
                if(V2.empty()){
                    cout<<"-1";
                    return 0;
                }
                V3.pb(mp(V2.back().st, i));
                V2.pop_back();
            }
            else{
                if(V4.empty()){
                    if(V2.empty()){
                        cout<<"-1";
                        return 0;
                    }
                    V3.pb(mp(wsk, V2.back().nd));
                    V3.pb(mp(wsk, i));
                    V2.pop_back();
                }
                else{
                    V3.pb(mp(wsk, V4.back().nd));
                    V3.pb(mp(wsk, i));
                    V4.pop_back();
                }
                wsk--;
            }
            V4.pb(V3.back());
        }
    }
    cout<<V3.size()<<"\n";
    for(auto i:V3){
        cout<<i.st<<" "<<i.nd+1<<"\n";
    }
}