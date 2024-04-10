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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
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

const int N = 1e5;
int a[N],subeIzq[N],subeDer[N],bajaIzq[N],bajaDer[N];
int acSubeIzq[N],acSubeDer[N];
int n;


void b(){
    cin>>n;
    F0(i,n) cin>>a[i];
    subeIzq[0] = 0;
    F1(i,n-1){
        if(a[i-1] > a[i]) subeIzq[i] = subeIzq[i-1]+1;
        else subeIzq[i] = 0;
    }
    subeDer[n-1] = 0;
    F0R(i,n-1){
        if(a[i+1] > a[i]) subeDer[i] = subeDer[i+1]+1;
        else subeDer[i] = 0;
    }
    bajaIzq[0] = 0;
    F1(i,n-1){
        if(a[i-1] < a[i]) bajaIzq[i] = bajaIzq[i-1]+1;
        else bajaIzq[i] = 0;
    }
    bajaDer[n-1] = 0;
    F0R(i,n-1){
        if(a[i+1] < a[i]) bajaDer[i] = bajaDer[i+1]+1;
        else bajaDer[i] = 0;
    }
    int res = 0;
    acSubeIzq[n-1] = subeIzq[n-1];
    F0R(i,n-1) acSubeIzq[i] = max(acSubeIzq[i+1],subeIzq[i]);
    acSubeDer[0] = subeDer[0];
    F1(i,n-1) acSubeDer[i] = max(acSubeDer[i-1],subeDer[i]);
    F0R(i,n-1) maxi(subeDer[i],subeDer[i+1]);
    F1(i,n-1) maxi(subeIzq[i],subeIzq[i-1]);
    F0(i,n){
        if(i == 0 or i+1 == n) continue;
        if(bajaIzq[i] == 0) continue;
        if(bajaDer[i] == 0) continue;
        if(bajaIzq[i] != bajaDer[i]) continue;
        if(bajaIzq[i] % 2) continue;
        if(bajaIzq[i] <= subeIzq[i-1]) continue;
        if(bajaIzq[i] <= subeDer[i+1]) continue;
        int l = i - bajaIzq[i];
        if(l > 0 and acSubeDer[l-1] >= bajaIzq[i]) continue;
        int r = i + bajaDer[i];
        if(r+1 < n and acSubeIzq[r+1] >= bajaIzq[i]) continue;
        res++;
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    b();
}