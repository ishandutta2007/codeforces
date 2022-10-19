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

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi A(n), B(n), C(n);
        for(int i=0; i<n; i++)cin>>A[i];
        for(int i=0; i<n; i++)cin>>B[i];
        for(int i=0; i<n; i++)cin>>C[i];
        int k=A[0], l=A[0];
        for(int i=1; i<n; i++){
            cout<<k<<" ";
            if(A[i]!=k && A[i]!=l)k=A[i];
            else if(B[i]!=k && B[i]!=l)k=B[i];
            else k=C[i];
        }
        cout<<k<<"\n";
    }
}