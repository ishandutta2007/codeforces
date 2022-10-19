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

int n,m;
vvi a;

bool probar(int i1, int i2, int l, int r){ //igual a  a[i1][!=l !=r] o a[i2][l o r]
    F0(i,n){
        int difs = 0;
        F0(j,m) {
            if(j == l or j == r) if(a[i][j] != a[i2][j]) difs++;
            if(j != l and j != r) if(a[i][j] != a[i1][j]) difs++;
        }
        if(difs > 2) return false;
    }
    return true;
}

bool probar3(int i1, int i2, int j1, int j2, int j3, int& coso){
    F0(i,n){
        int difs = 0;
        F0(j,m){
            if(j == j3) continue;
            if(j == j1) {
                if(a[i][j] != a[i2][j]) difs++;
            }
            else if(a[i][j] != a[i1][j]) difs++;
        }
        if(difs > 2) return false;
        if(difs == 2) {
            if(coso == -1 or coso == a[i][j3]) coso = a[i][j3];
            else return false;
        }
    }
    return true;
}

void almost_fault(){
    cin>>n>>m;
    a = vvi(n,vi(m));
    F0(i,n) F0(j,m) cin>>a[i][j];

    F1(i,n-1){
        vi difs;
        F0(j,m) if(a[0][j] != a[i][j]) difs.pb(j);
        if(difs.size() >= 5) {
            cout<<"No\n";
            return;
        }
        if(difs.size() == 4){
            F0(i1,3) {
                REP(i2,i1+1,3){
                    int l = difs[i1], r = difs[i2];
                    if(probar(0,i,l,r)) {
                        cout<<"Yes\n";
                        F0(j,m) {
                            if(j == l or j == r) cout<<a[i][j]<<' ';
                            else cout<<a[0][j]<<' ';
                        }
                        cout<<'\n';
                        return;
                    }
                }
            }
            cout<<"No\n";
            return;
        }
        if(difs.size() == 3){
            do {
                int coso = -1;
                if(probar3(0,i,difs[0],difs[1],difs[2],coso)){
                    cout<<"Yes\n";
                    F0(j,m){
                        if(coso == -1) coso = 1;
                        if(j == difs[0]) cout<<a[i][j]<<' ';
                        else if(j == difs[1]) cout<<a[0][j]<<' ';
                        else if(j == difs[2]) cout<<coso<<' ';
                        else cout<<a[0][j]<<' ';
                    }
                    cout<<'\n';
                    return;
                }
            } while(next_permutation(todo(difs)));
            F0(i1,2){
                REP(i2,i1+1,2){
                    int l = difs[i1], r = difs[i2];
                    if(probar(0,i,l,r)) {
                        cout<<"Yes\n";
                        F0(j,m) {
                            if(j == l or j == r) cout<<a[i][j]<<' ';
                            else cout<<a[0][j]<<' ';
                        }
                        cout<<'\n';
                        return;
                    }
                    if(probar(i,0,l,r)) {
                        cout<<"Yes\n";
                        F0(j,m) {
                            if(j == l or j == r) cout<<a[0][j]<<' ';
                            else cout<<a[i][j]<<' ';
                        }
                        cout<<'\n';
                        return;
                    }
                }
            }
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
    F0(j,m) cout<<a[0][j]<<' ';
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    almost_fault();
}