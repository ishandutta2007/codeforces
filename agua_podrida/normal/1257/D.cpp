#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void b(){
    int x,y;
    cin>>x>>y;
    if(x == 1){
        if(y == 1) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    if(x <= 3){
        if(y <= 3) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

void c(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi ultAparicion(n+1,-n-5);
    int res = n+1;
    F0(i,n) {
        res = min(res,i-ultAparicion[a[i]]);
        ultAparicion[a[i]] = i;
    }

    if(res >= n) cout<<-1<<'\n';
    else cout<<res+1<<'\n';
}

struct segmentMax{
    segmentMax(vi& values);
    segmentMax(int nn);

    void asignar(int i, int x);

    int maxr(int a, int b);

    int& operator[](int i){
        return tree[i];
    }

    int n;
    vi tree;
};

segmentMax::segmentMax(int nn) {
    n = nn;
    tree = vi(2*n);
}

segmentMax::segmentMax(vi& values) {
    n = values.size();
    tree = vi(2*n);
    F0(i,n) tree[n+i] = values[i];
    F1R(i,n-1) tree[i] = max(tree[2*i],tree[2*i+1]);
}

void segmentMax::asignar(int i, int x) {
    i += n;
    if(tree[i] >= x)
        return;
    tree[i] = x;
    for(i /= 2; i >= 1; i /= 2) tree[i] = max(tree[2*i],tree[2*i+1]);
}

int segmentMax::maxr(int a, int b) {
    a += n; b += n;
    int maximo = -INF;
    while(a <= b){
        if(a % 2 == 1) maxi(maximo,tree[a++]);
        if(b % 2 == 0) maxi(maximo,tree[b--]);
        a /= 2; b /= 2;
    }
    return maximo;
}

int n,m;

void d(){
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    cin>>m;
    segmentMax powPorEnd(n+1);
    int pow,end;
    F0(i,m) {
        cin>>pow>>end;
        powPorEnd.asignar(end,pow);
    }

    int maxMounstro = 0;
    F0(i,n) maxi(maxMounstro,a[i]);
    if(powPorEnd.maxr(0,n) < maxMounstro){
        cout<<"-1\n";
        return;
    }

    int res = 0;
    int i = 0;
    while(i < n){
        int endUsada = 1;
        int maxVisto = a[i];
        while(i < n){
            maxVisto = max(maxVisto,a[i]);
            if(powPorEnd.maxr(endUsada,n) < maxVisto) break;
            endUsada++;
            i++;
        }
        res++;
    }

    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) d();
    return 0;
}