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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<ll> V(n);
    for(int i=0; i<n; i++){
        cin>>V[i];
    }
    if(n==1){
        cout<<"1 1\n"<<-V[0]<<"\n 1 1\n 0\n 1 1\n 0";
        return 0;
    }
    long long k=n;
    cout<<1<<" "<<n<<"\n";
    for(int i=0; i<n; i++){
        int t=((V[i]%(n-1))+n-1)%(n-1);
        V[i]-=t*k;
        cout<<-t*k<<" ";
    }
    cout<<"\n";
    cout<<1<<" "<<n-1<<"\n";
    for(int i=0; i<n-1;i++){
        cout<<-V[i]<<" ";
    }
    cout<<"\n";
    cout<<n<<" "<<n<<"\n"<<-V[n-1];
}