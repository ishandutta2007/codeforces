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

const int N = 1000000;
ll lp[N+1];
vector<ll> pr;

void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back ((ll) i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void actualizar(vb& ok, int& espero, ll p, int n){
    int i = 1;
    while(i*p <= n){
        if(ok[i*p]){
            ok[i*p] = false;
            espero--;
        }
        i++;
    }
}

void e(){
    int n;
    cin>>n;
    int magic = 100;
    int i = 0;
    int it = 1;
    int res;
    int espero = n;
    vb ok(n+1,true);
    while(pr[i] <= n){
        if(i == it*magic) {
            cout<<"A 1\n";
            cin>>res;
            if(res != espero) break;
            it++;
        }
        cout<<"B "<<pr[i]<<'\n';
        cin>>res;
        actualizar(ok,espero,pr[i],n);
        i++;
    }
    ll x = 1;
    i = (it-1)*magic;
    while(pr[i] <= n){
        while(x*pr[i] <= n){
            cout<<"A "<<x*pr[i]<<'\n';
            cin>>res;
            if(res == 1) x *= pr[i];
            else break;
        }
        i++;
    }
    cout<<"C "<<x<<'\n';
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    criba();
    e();
}