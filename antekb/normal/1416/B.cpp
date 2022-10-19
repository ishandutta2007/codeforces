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
long long tab[N];
vector<pair<pii, int> > V;
void update(int i, int j, long long x){
    if(x==0)return;
    V.pb(mp(mp(i, j), x));
    tab[i]-=i*x;
    tab[j]+=i*x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
        for(int i=1; i<=n; i++){
            cin>>tab[i];
            sum+=tab[i];
        }
        if(sum%n){
            cout<<"-1\n";
            continue;
        }
        sum/=n;
        vector<pii> V2;
        bool b=0;
        for(int i=2; i<=n; i++){
            if(tab[i]%i){
                update(1, i, i-tab[i]%i);
                if(tab[1]<0)b=1;
            }
            update(i, 1, tab[i]/i);
        }
        for(int i=2; i<=n; i++){
            update(1, i, sum);
        }
        if(b){
            cout<<"-1\n";
            continue;
        }
        cout<<V.size()<<"\n";
        for(auto i:V){
            cout<<i.st.st<<" "<<i.st.nd<<" "<<i.nd<<"\n";
        }
        V.clear();
    }
}