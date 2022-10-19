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
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const int mod = 1e9+7;
const int INF  = 1e9;
const double eps = 0.00000001;

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    int suma = 0;
    for(auto x : a) suma += x;
    if(suma % n) cout<<"1\n";
    else cout<<"0\n";
}


//cant < l que tengan encendido el bit i
int cuantos(int l, int i){
    int res = l / (1<<(i+1));
    res *= (1<<i);
    res += max(0,l % (1<<(i+1)) - (1<<i));
    return res;
}

void b(){
    int l,r;
    cin>>l>>r;
    int res = 0;
    F0(i,20){
        maxi(res,cuantos(r+1,i) - cuantos(l,i));
    }
    res = r-l+1-res;
    cout<<res<<'\n';
}

void c(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    if(a == b){
        cout<<"0\n";
        return;
    }
    if(a == string(n,'0')){
        cout<<"-1\n";
        return;
    }
    int unosa = 0, unosb = 0;
    for(auto c : a) if(c == '1') unosa++;
    for(auto c : b) if(c == '1') unosb++;

    if(unosb != unosa and unosb != 1 + n - unosa){
        cout<<"-1\n";
        return;
    }

    int res = n+1;

    if(unosb == unosa){
        int dif = 0;
        F0(i,n){
            if(a[i] != b[i]) dif++;
        }
        mini(res,dif);
    }

    if(unosb == 1 + n - unosa){
        int ig = 0;
        F0(i,n){
            if(a[i] == b[i]) ig++;
        }
        mini(res,ig);
    }

    cout<<res<<'\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) c();
}