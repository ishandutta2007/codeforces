#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
const ll mod = 998244353;

int cant_ceros(string& a){
    int ceros_a = 0;
    for(auto c : a) if(c == '0') ceros_a++;
    return ceros_a;
}

bool por_ceros(string& a, string& b){
    return cant_ceros(a) < cant_ceros(b);
}

void flip_string(string& a){
    F0(i,a.size()){
        if(a[i] == '0') a[i] = '1';
        else a[i] = '0';
    }
}

void flip_vc(vc& a){
    F0(i,a.size()){
        if(a[i] == '0') a[i] = '1';
        else a[i] = '0';
    }
}

void a(){
    int n;
    cin>>n;
    vector<string> a(3);
    F0(i,3) cin>>a[i];
    sort(todo(a),por_ceros);
    vc res;
    if(cant_ceros(a[1]) <= n) {
        int i = 0;
        int j = 0;
        while(i < 2*n and j < 2*n){
            if(a[0][i] == '1' and a[1][j] == '1'){
                res.pb('1');
                i++, j++;
            }
            else if(a[0][i] == '0') res.pb('0'), i++;
            else res.pb('0'), j++;
        }
        while(i < 2*n) res.pb(a[0][i]), i++;
        while(j < 2*n) res.pb(a[1][j]), j++;
        while(res.size() < 3*n) res.pb('0');
    }
    else {
        swap(a[2],a[0]);
        flip_string(a[0]);
        flip_string(a[1]);
        int i = 0;
        int j = 0;
        while(i < 2*n and j < 2*n){
            if(a[0][i] == '1' and a[1][j] == '1'){
                res.pb('1');
                i++, j++;
            }
            else if(a[0][i] == '0') res.pb('0'), i++;
            else res.pb('0'), j++;
        }
        while(i < 2*n) res.pb(a[0][i]), i++;
        while(j < 2*n) res.pb(a[1][j]), j++;
        while(res.size() < 3*n) res.pb('0');
        flip_vc(res);
    }
    for(auto c : res) cout<<c;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    F1(x,t) a();
}