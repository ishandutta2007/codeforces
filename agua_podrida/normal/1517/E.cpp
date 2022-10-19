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

const int N = 2e5;

ll pref[N],par[N],impar[N],a[N];

ll spref(int i){
    if(i < 0) return 0;
    return pref[i];
}

ll spar(int i){
    if(i < 0) return 0;
    return par[i];
}

ll simpar(int i){
    if(i < 0) return 0;
    return impar[i];
}

ll total,tope;

int n;

ll opcion_facil(){
    int i = n-2;
    ll suma = a[n-1];
    ll res = 0;
    while(i >= 2){
        suma += a[i];
        if(suma < tope) res++;
        i--;
    }
    return res;
}

ll c_par(int l, int r, ll suma){
    if(r-l < 4) return 0;
    int i = l+2;
    suma += a[i-2] + a[i-1];
    if(suma >= tope) return 0;
    ll res = 0;
    int j = i;
    while(j+2 <= r-2 and suma + a[j+1] < tope) suma += a[j+1], j += 2;
    while(i <= j){
        res += (ll) (j-i)/2 + 1;
        suma += a[i];
        i += 2;
        while(j > 0 and suma >= tope) j -= 2, suma -= a[j+1];
    }
    return res;
}

ll c_impar(int l, int r, ll suma){
    if(r-l < 5) return 0;
    int i = l+3;
    suma += a[i-3] + a[i-2] + a[i-1];
    if(suma >= tope) return 0;
    ll res = 0;
    int j = i;
    while(j+2 <= r-2 and suma + a[j+1] < tope) suma += a[j+1], j += 2;
    while(i <= j){
        res += (ll) (j-i)/2 + 1;
        suma += a[i];
        i += 2;
        while(j > 0 and suma >= tope) j -= 2, suma -= a[j+1];
    }
    return res;
}

ll dificil_aux(int l, int r, ll suma){
    ll res = c_par(l,r,suma);
    res += c_impar(l,r,suma);
    return res;
}

ll opcion_dificil(){
    ll res = 0;
    int l,r;
    ll suma;
    F0(bit,4){
        suma = 0;
        if(bit & 1) l = 1;
        else l = 0;
        if(bit & 2) r = n-1, suma = a[n-1];
        else r = n;
        res += dificil_aux(l,r,suma);
    }
    return res;
}

ll de_las_dos(){
    ll res = opcion_facil();
    res += opcion_dificil();
    return res;
}

ll c_aux(int l, int r){
    int i = r;
    ll suma = spref(r-1) - spref(l-1);
    ll res = 0;
    while(i >= l+2){
        if(suma < tope) res++;
        i -= 2;
        if(i >= 0) suma -= a[i];
    }
    return res;
}

ll solo_c(){
    int l,r;
    ll res = 0;
    F0(bit,4){
        if(bit & 1) l = 1;
        else l = 0;
        if(bit & 2) r = n;
        else r = n-1;
        res += c_aux(l,r);
    }
    return res;
}

ll p_aux(int l, int r, ll suma){
    int i = l;
    ll res = 0;
    while(i+2 <= r){
        if(suma < tope) res++;
        i += 2;
        if(i <= n) suma += a[i-1];
    }
    return res;
}

ll solo_p(){
    int l,r;
    ll res = 0;
    ll suma;
    F0(bit,4){
        suma = 0;
        if(bit & 1) l = 1, suma += a[0];
        else l = 0;
        if(bit & 2) r = n-1, suma += a[n-1];
        else r = n;
        res += p_aux(l,r,suma);
    }
    return res;
}

ll alternancia(){
    if(simpar(n-1) == spar(n-1)) return 0;
    return 1;
}

void e(){
    cin>>n;
    F0(i,n) cin>>a[i];

    pref[0] = a[0];
    F1(i,n-1) pref[i] = pref[i-1] + a[i];
    total = pref[n-1];

    par[0] = a[0];
    F1(i,n-1){
        par[i] = par[i-1];
        if(i % 2 == 0) par[i] += a[i];
    }

    impar[0] = 0;
    F1(i,n-1){
        impar[i] = impar[i-1];
        if(i % 2 == 1) impar[i] += a[i];
    }

    ll res = 0;
    tope = (total+1)/2;

    res += de_las_dos();
    res += solo_c();
    res += solo_p();
    res += alternancia();

    res %= mod;
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--) e();
}