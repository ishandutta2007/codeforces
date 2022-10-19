#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it : s)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

void e(){
    int n;
    cin>>n;
    vvll a(n,vll(n,1));
    vvll chico(n,vll(n,1));
    vvll grande(n,vll(n,1));
    F0R(j,n-1) chico[n-1][j] = chico[n-1][j+1]+1;
    F0R(j,n-1) grande[n-1][j] = grande[n-1][j+1]+1;
    F0R(i,n-1) chico[i][0] = chico[i+1][0]+1;
    F0R(i,n-1){
        F1(j,n-1){
            ll x = grande[i+1][j-1] - chico[i+1][j] + 1;
            a[i][j] = x;
            chico[i][j] = x + chico[i+1][j];
        }
        grande[i][n-1] = grande[i+1][n-1] + a[i][n-1];
        F0R(j,n-1) grande[i][j] = grande[i][j+1] + a[i][j];
    }

    F0(i,n) {
        F0(j,n) cout<<a[i][j]<<' ';
        cout<<'\n';
    }

    int q;
    cin>>q;
    ll k;
    while(q--){
        cin>>k;
        int i = 0, j = 0;
        cout<<"1 1\n";
        k -= 1;
        while(i != n-1 or j != n-1){
            if(i < n-1 and grande[i+1][j] >= k) i++;
            else j++;
            cout<<i+1<<' '<<j+1<<'\n';
            k -= a[i][j];
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    e();
}