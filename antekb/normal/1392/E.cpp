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

const int N=30, INF=1e9+5, mod=1e9+7;
long long tab[N][N];
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!(i&1))tab[i][j]=0;
            else    if(j==0)tab[i][j]=(1ll<<(i-1));
            else tab[i][j]=2*tab[i][j-1];
            cout<<tab[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout.flush();
    int q;
    cin>>q;
    while(q--){
        int x=0, y=0;
        ll k;
        cin>>k;

        while(x<n-1 || y<n-1){
            cout<<x+1<<" "<<y+1<<"\n";
            if(x==n-1)y++;
            else if(y==n-1)x++;
            else{
                if((k&1)^(tab[x+1][y]==0))x++;
                else y++;
                k/=2;
            }
        }
        cout<<n<<" "<<n<<endl;
        //cout.flush();
    }
}