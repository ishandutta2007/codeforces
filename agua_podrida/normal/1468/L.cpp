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

vector<int, int> &
getVector(const unordered_map<ll, int> &trad, vector<map<int, int>> &g, int dst, int &prox, ll res, int v, int i);

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)

ll gcd(ll a, ll b){return a?gcd(b%a, a):b;}

ll mulmod(ll a, ll b, ll c){ //(a*b)%c
    ll x = 0;
    ll y = a%c;
    while(b>0){
        if(b%2==1) x = (x+y)%c;
        y = (y*2) % c;
        b /= 2;
    }
    return x%c;
}

ll expmod(ll b, ll e, ll m){ //O(log b)
    if(!e) return 1;
    ll q = expmod(b, e/2, m);
    q = mulmod(q,q,m);
    return e%2? mulmod(b,q,m) : q;
}

bool es_primo_prob(ll n, int a){
    if(n==a) return true;
    ll s = 0;
    ll d = n-1;
    while(d%2 == 0) s++, d/=2;

    ll x = expmod(a,d,n);
    if((x==1) || (x+1==n)) return true;

    F0(i, s-1){
        x = mulmod(x,x,n);
        if(x==1) return false;
        if(x+1==n) return true;
    }
    return false;
}

bool rabin(ll n){ //true <=> n primo
    if(n==1) return false;
    const int ar[] = {2,3,5,7,11,13,17,19,23};
    F0(j,9){
        if(!es_primo_prob(n,ar[j])) return false;
    }
    return true;
}


ll raiz(ll a){
    ll lo = 0;
    ll hi = 1e9+1;
    while(lo+1 != hi){
        ll m = (lo+hi)/2;
        if(m*m <= a) lo = m;
        else hi = m;
    }
    if(lo*lo == a) return lo;
    return 0;
}

const int N = 1000000;
int lp[N+1];
vector<int> pr;
void criba() {
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

bool pertenece(vll& v, ll x){
    for(auto y : v) if(x == y) return true;
    return false;
}

void l(){
    int n,k;
    cin>>n>>k;
    map<ll,int> s;
    ll x;
    F0(i,n) {
        cin>>x;
        s[x]++;
    }
    if(k == 1) {
        cout<<"0\n";
        return;
    }
    map<ll,vll> f;
    for(auto p : pr){
        ll pot = 1;
        while(pot <= 1e18 / p){
            pot *= p;
            if(s.count(pot)) F0(i,s[pot]) f[p].pb(pot);
        }
    }
    for(auto it : s){
        ll a = it.first;
        if(raiz(a) > 1e6){
            f[raiz(a)].pb(a);
        }
        if(a > 1e6 and rabin(a)) f[a].pb(a);
    }
    int cnt = 0;
    bool hayMayor = false;
    for(auto it : f){
        if(it.second.size() >= 2) cnt += it.second.size();
        if(it.second.size() > 2) hayMayor = true;
    }
    int puedoAgregar = 0;
    int masBarato = 2000;
    ll elmasbarato;
    vll factoresMasBarato;
    vll pasumar;
    for(auto a : s){
        x = a.first;
        vll fact;
        int factores = 0;
        for(auto it : f){
            if(it.second.size() == 1) continue;
            ll p = it.first;
            if(x % p == 0) {
                factores++;
                fact.pb(p);
            }
            while(x % p == 0) x /= p;
        }
        if(x == 1 and factores >= 2) {
            F0(i,a.second) pasumar.pb(a.first);
            puedoAgregar += a.second;
            if(factores < masBarato) {
                mini(masBarato,factores);
                factoresMasBarato = fact;
                elmasbarato = a.first;
            }
        }
    }

    if(cnt >= k){
        if(!hayMayor and k%2 == 1){
            if(masBarato <= k/2){
                for(auto p : factoresMasBarato){
                    for(auto x : f[p]) cout<<x<<' ';
                }
                cout<<elmasbarato<<' ';
                int falta = k-2*masBarato-1;
                for(auto it : f){
                    if(falta == 0) break;
                    if(it.second.size() < 2) continue;
                    ll p = it.first;
                    if(pertenece(factoresMasBarato,p)) continue;
                    for(auto x : it.second) cout<<x<<' ';
                    falta -= 2;
                }
                cout<<'\n';
            }
            else {
                cout<<"0\n";
            }
            return;
        }
        else {
            int falta = k;
            for(auto it : f){
                if(falta == 0) break;
                if(it.second.size() < 2) continue;
                if(it.second.size() == 2 and falta == 3) continue;
                if(it.second.size()+1 == falta){
                    for(auto x : it.second) {
                        if(falta == 2) break;
                        cout<<x<<' ';
                        falta--;
                    }
                }
                else {
                    for(auto x : it.second){
                        if(falta == 0) break;
                        cout<<x<<' ';
                        falta--;
                    }
                }

            }
            cout<<'\n';
        }
    }
    else {
        if(cnt + puedoAgregar >= k){
            int falta = k;
            for(auto it : f){
                if(falta == 0) break;
                if(it.second.size() < 2) continue;
                for(auto x : it.second) {
                    if(falta == 0) break;
                    cout<<x<<' ';
                    falta--;
                }
            }
            for(auto x : pasumar){
                if(falta == 0) break;
                cout<<x<<' ';
                falta--;
            }
            cout<<'\n';
        }
        else cout<<"0\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    criba();
    l();
    return 0;
}