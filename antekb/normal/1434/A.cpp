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

    vi S(6);
    for(int &i:S)cin>>i;
    int n;
    cin>>n;
    vi V(n), ile(n);
    for(int &i:V)cin>>i;
    vii V2;
    for(int i=0; i<6; i++){
        for(int j=0; j<n; j++){
            V2.pb(mp(V[j]-S[i], j));
        }
    }
    sort(all(V2));
    int wsk1=0, wsk2=0, k=0, ans=INF;
    while(wsk2<=V2.size()){
        //deb(wsk1, wsk2, k, ans);
        if(k==n){
            ans=min(ans, V2[wsk2-1].st-V2[wsk1].st);
            if(!--ile[V2[wsk1++].nd])k--;
        }
        else{
            if(wsk2==V2.size())break;
            if(!ile[V2[wsk2++].nd]++)k++;
        }
    }
    cout<<ans;
}