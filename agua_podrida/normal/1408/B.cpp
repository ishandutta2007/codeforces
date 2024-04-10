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
    vi a(n),b(n),c(n);
    F0(i,n) cin>>a[i];
    F0(i,n) cin>>b[i];
    F0(i,n) cin>>c[i];
    vi p(n);
    p[0] = a[0];
    F1(i,n-2){
        if(a[i] == p[i-1]) p[i] = b[i];
        else p[i] = a[i];
    }
    if(a.back() != p[0] and a.back() != p[n-2]) p[n-1] = a.back();
    else if(b.back() != p[0] and b.back() != p[n-2]) p[n-1] = b.back();
    else p[n-1] = c.back();

    F0(i,n) cout<<p[i]<<' ';
    cout<<'\n';
}

void b(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    F0(i,n) cin>>a[i];
    int diferentes = 1;
    F1(i,n-1) if(a[i] != a[i-1]) diferentes++;

    if(k == 1 and diferentes != 1) {
        cout<<"-1\n";
        return;
    }
    int res = 1;
    diferentes -= k;
    while(diferentes > 0){
        res++;
        diferentes -= k-1;
    }
    cout<<res<<'\n';
}

void c(){
    int n;
    ll l;
    cin>>n>>l;
    vll a(n);
    F0(i,n) cin>>a[i];
    double izq = 0;
    double izqVel = 1;
    double der = l;
    double derVel = 1;
    int i = 0;
    int j = n-1;
    double time = 0.0;
    while(i <= j){
        double ti = (double) (a[i] - izq) / (double) izqVel;
        double tj = (double) (der - a[j]) / (double) derVel;
        if(ti < tj){
            izq = a[i];
            i++;
            izqVel++;
            der -= ti*derVel;
            time += ti;
        }
        else {
            der = a[j];
            j--;
            derVel++;
            izq += tj*izqVel;
            time += tj;
        }
    }
    time += (der-izq) / (izqVel + derVel);
    cout<<setprecision(9)<<fixed<<time<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    F1(x,t){
        b();
    }
    return 0;
}