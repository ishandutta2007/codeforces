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
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
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
#define F first
#define S second
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

int minDfn[5005];

void constructTheBinaryTree(){
    int n,d;
    cin>>n>>d;
    minDfn[0] = 0;
    minDfn[1] = 0;
    int nodo = 2;
    int nivel = 1;
    int enEsteNivel = 2;
    int conte = 0;
    while(nodo <= 5000){
        minDfn[nodo] = minDfn[nodo-1] + nivel;
        conte++;
        if(conte == enEsteNivel){
            conte = 0;
            enEsteNivel *= 2;
            nivel++;
        }
        nodo++;
    }

    if(d < minDfn[n] or d > n*(n-1)/2){
        cout<<"NO\n";
        return;
    }

    vi padre(n+1);
    vector<tuple<int,int,int>> pendiente;
    pendiente.pb(mt(1,n,d));
    int l,r,sum,nn;
    while(!pendiente.empty()){
        tie(l,r,d) = pendiente.back();
        pendiente.pop_back();
        n = r-l;
        int n1 = 0;
        while(minDfn[n1] + minDfn[n-n1] > d-n) n1++;
        int n2 = n-n1;
        int l1 = l+1;
        int r1 = l+n1;
        int d1 = minDfn[n1];
        while(d1+n2*(n2-1)/2 < d - n) d1++;
        if(l1 < r1) pendiente.pb(mt(l1,r1,d1));
        int d2 = d-n-d1;
        int l2 = r1+1;
        int r2 = r;
        padre[l1] = l;
        if(l2 <= r2) padre[l2] = l;
        if(l2 < r2) pendiente.pb(mt(l2,r2,d2));
    }
    cout<<"YES\n";
    REP(i,2,padre.size()-1) cout<<padre[i]<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../c2.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) constructTheBinaryTree();
    return 0;
}