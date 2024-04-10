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
    int n, k;
    cin>>n>>k;
    int K=299;
    for(int i=1; i<3*K; i++){
        cout<<"? "<<(K*i)%n+1<<endl;
        int x;
        cin>>x;
        if(x!=k){
            int t=(K*i)%n+1;
            int l=1;
            if(x>k)l=-1;
            for(int j=(t+l+n-1)%n+1; ;j=(j+l+n-1)%n+1){
                cout<<"? "<<j<<endl;
                int x;
                cin>>x;
                if(x==k){
                    cout<<"! "<<j;
                    return 0;
                }
            }
        }
    }
}