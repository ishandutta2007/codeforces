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
//#define pb push_back
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007
#define PI acos(-1.0)

/*
bool sacar(pll izq, pll p, pll der){
    ll x1 = izq.first; ll y1 = izq.second;
    ll x2 = p.first; ll y2 = p.second;
    ll x3 = der.first; ll y3 = der.second;
    ll ym = y1 * (x3 - x2) + y3 * (x2 - x1);
    y2 *= (x3 - x1);
    return y2 <= ym;
}

bool sacarIzq(set<pll>& ch, pll p){
    auto it = ch.find(p);
    if(it != ch.begin()){
        auto itizq = it;
        itizq--;
        if(itizq != ch.begin()){
            auto itizqizq = itizq;
            itizqizq--;
            if(sacar(*itizqizq,*itizq,*it)) {
                ch.erase(itizq);
                return true;
            }
        }
    }
    return false;
}

bool sacarDer(set<pll>& ch, pll p){
    auto it = ch.find(p);
    auto itder = it;
    itder++;
    if(itder != ch.end()){
        auto itderder = itder;
        itderder++;
        if(itderder != ch.end() and sacar(*it,*itder,*itderder)){
            ch.erase(itder);
            return true;
        }
    }
    return false;
}

void meter(set<pll>& ch, pll p){
    auto it = ch.lower_bound(mp(p.first,-INF));
    if(it != ch.end() and it->first == p.first and it->second >= p.second) return;
    else ch.insert(p);
    auto itizq = ch.find(p);
    if(itizq != ch.begin()){
        itizq--;
        auto itder = ch.find(p);
        itder++;
        if(itder != ch.end() and sacar(*itizq,p,*itder)){
            ch.erase(p);
            return;
        }
    }

    while(sacarIzq(ch,p));
    while(sacarDer(ch,p));
}
*/

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi sinAparecer(n+1,-1);
    vi ultAparicion(n+1,-1);
    F0(i,n){
        maxi(sinAparecer[a[i]],i - ultAparicion[a[i]]);
        ultAparicion[a[i]] = i;
    }
    F1(i,n){
        maxi(sinAparecer[i],n - ultAparicion[i]);
    }

    vi res(n+2,2*n);
    F1(i,n) if(sinAparecer[i] >= 0) mini(res[sinAparecer[i]],i);
    F1(i,n) mini(res[i],res[i-1]);
    F1(i,n) if(res[i] > n) res[i] = -1;
    F1(i,n) cout<<res[i]<<' ';
    cout<<'\n';
}

void b(){
    int n;
    cin>>n;
    vll a(n+1);
    F1(i,n) cin>>a[i];
    ll suma = 0;
    F1(i,n) suma += a[i];
    if(suma % n != 0){
        cout<<"-1\n";
        return;
    }
    ll obj = suma / n;
    vi resi,resj,resx;

    REP(j,2,n){
        resi.pb(1);
        resj.pb(j);
        ll x = j - (a[j] % j);
        if(x == j) x = 0;
        resx.eb(x);
        a[j] += x;
        a[1] -= x;

        resi.pb(j);
        resj.pb(1);
        resx.pb(a[j] / j);
        a[1] += a[j];
        a[j] = 0;
    }

    REP(j,2,n){
        resi.pb(1);
        resj.pb(j);
        resx.pb(obj);
    }

    cout<<resi.size()<<'\n';
    F0(i,resi.size()){
        cout<<resi[i]<<' '<<resj[i]<<' '<<resx[i]<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    F1(x,t) {
        b();
    }
    return 0;
}