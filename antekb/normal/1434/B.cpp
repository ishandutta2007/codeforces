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
    vii Ev;
    for(int i=0; i<2*n; i++){
        char c;
        cin>>c;
        int k;
        if(c=='-'){
            cin>>k;
            Ev.pb(mp(-1, k));
        }
        else Ev.pb(mp(1, 0));
    }
    set<int> S;
    vi V;
    for(int i=2*n-1; i>=0; i--){
        if(Ev[i].st==1){
            if(S.empty()){
                cout<<"NO";
                return 0;
            }
            V.pb(*S.begin());
            S.erase(S.begin());
        }
        else{
            S.insert(Ev[i].nd);
        }
    }
    reverse(all(V));
    int wsk=0;
    for(int i=0; i<2*n; i++){
        if(Ev[i].st==1){
            S.insert(V[wsk++]);
        }
        else{
            if(*S.begin()!=Ev[i].nd){
                cout<<"NO";
                return 0;
            }
            S.erase(S.begin());
        }
    }
    cout<<"YES\n";
    for(int i:V)cout<<i<<" ";
}