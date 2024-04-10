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

const int N=2e5+5, mod=1e9+7;
const ll INF=1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi V(n);
        for(int &i:V){
            cin>>i;
        }
        ll s1=0, s2=0, m1=0, m2=0;
        ll ans=0;
        for(int i=0; i<n; i++){

            if(i&1){
                s1+=V[i];
                ans=max(ans, s1-s2-m1);
                m1=min(m1, s1-s2);
            }
            else{
                s2+=V[i];
                ans=max(ans, s1-s2-m2);
                m2=min(m2, s1-s2);
            }//debug(s1, s2, m1, m2, ans);
        }
        cout<<ans+s2<<"\n";
    }
}