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
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

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
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n;
    cin>>n;
    set<set<char>> s;
    string a;
    F0(i,n){
        set<char> t;
        cin>>a;
        for(auto c : a) t.insert(c);
        s.insert(t);
    }
    cout<<s.size()<<'\n';
}

ll coso(vll a, int i){
    ll aux = a[i];
    a[i] = 0;
    F0(j,14) a[j] += aux/14;
    aux -= (aux/14)*14;
    int j = i;
    while(aux > 0){
        j++;
        if(j == 14) j = 0;
        aux--;
        a[j]++;
    }
    ll res = 0;
    for(auto ai : a) if(ai%2==0) res += ai;
    return res;
}

void b(){
    vll a(14);
    F0(i,14) cin>>a[i];
    ll res = 0;
    F0(i,14) maxi(res,coso(a,i));
    cout<<res<<'\n';
}

void c(){
    int n,q;
    cin>>n>>q;
    vll a(n);
    F0(i,n) cin>>a[i];
    vll k(q);
    F0(i,q) cin>>k[i];

    vll pref(n);
    pref[0] = a[0];
    F1(i,n-1) pref[i] = pref[i-1]+a[i];

    int i = 0;//primer soldado vivo
    ll dano = 0;//dano que le hizo al primer soldado vivo

    F0(j,q){
        if(dano + k[j] < a[i]) {
            dano += k[j];
            cout<<n-i<<'\n';
            continue;
        }
        else {
            k[j] -= a[i] - dano;
            i++;
            dano = 0;
            if(pref[n-1] - pref[i-1] <= k[j]) {
                cout<<n<<'\n';
                i = 0;
                continue;
            }
            int hi = n-1;//>k[j]
            int lo = i-1;//<= k[j]
            while(lo+1 != hi){
                int m = (lo+hi)/2;
                if(pref[m] - pref[i-1] <= k[j]) lo = m;
                else hi = m;
            }
            dano = -pref[lo] + pref[i-1] + k[j];
            i = hi;
            cout<<n-i<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    b();
    return 0;
}