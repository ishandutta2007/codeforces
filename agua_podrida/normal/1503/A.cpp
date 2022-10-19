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
const ll mod = 998244353;

void flip(char& c){
    if(c == '(') c = ')';
    else c = '(';
}

void a(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cant_ceros = 0;
    for(auto c : s) if(c == '0') cant_ceros++;
    if(cant_ceros % 2){
        cout<<"NO\n";
        return;
    }
    if(s[0] == '0' or s[n-1] == '0'){
        cout<<"NO\n";
        return;
    }
    vc a,b;

    int sa = 0, sb = 0;
    F0(i,n-1){
        if(s[i] == '1'){
            if(min(sa,sb) == 0 or max(sa,sb) == 1) {
                a.pb('('), b.pb('(');
                sa++, sb++;
            }
            else {
                a.pb(')'), b.pb(')');
                sa--, sb--;
            }
        }
        else {
            if(sa < sb){
                a.pb('('), b.pb(')');
                sa++, sb--;
            }
            else {
                a.pb(')'), b.pb('(');
                sa--, sb++;
            }
        }
    }
    a.pb(')'), b.pb(')');


    cout<<"YES\n";
    for(auto c : a) cout<<c;
    cout<<'\n';
    for(auto c : b) cout<<c;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) a();
}