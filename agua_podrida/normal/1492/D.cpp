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
#define INF 1e18
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

void d(){
    int b,a,k;
    cin>>b>>a>>k;
    vi x(a+b);
    vi y(a+b);

    if(b == 0 and k != 0) {
        cout<<"No\n";
        return;
    }
    if(k == 0){
        cout<<"Yes\n";
        F0(j,2){
            F0(i,a) cout<<'1';
            F0(i,b) cout<<'0';
            cout<<'\n';
        }
        return;
    }
    if(a == 1){
        if(k == 0){
            cout<<"Yes\n";
            F0(j,2){
                cout<<'1';
                F0(i,b) cout<<'0';
                cout<<'\n';
            }
        }
        else cout<<"No\n";
        return;
    }
    if(k >= a+b-1){
        cout<<"No\n";
        return;
    }
    x[0] = 0;
    x[k] = 1;
    x[a+b-1] = 1;
    y[0] = 1;
    y[k] = 0;
    y[a+b-1] = 1;
    int quedan = a - 2;
    F0(i,a+b){
        if(i == 0 or i == k or i == a+b-1) continue;
        if(quedan){
            y[i] = 1;
            x[i] = 1;
            quedan--;
        }
        else {
            y[i] = 0;
            x[i] = 0;
        }
    }
    cout<<"Yes\n";
    F0R(i,a+b) cout<<x[i];
    cout<<'\n';
    F0R(i,a+b) cout<<y[i];
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    d();
}