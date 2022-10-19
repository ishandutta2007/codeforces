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
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 1000000007;
const ll INF  = 1e9;
const double eps = 0.000000001;

int n,k;

void complemento(int n, int k){
    k = n-k;
    int d = 0;
    while(k*d < n or (k*d-n)%2) d++;
    int res = 0;
    int x;

    int sobra = k*d-n;
    int uso = sobra/2;
    int voy = uso+1;
    F0(it,d){
        cout<<"? ";
        vb novan(n+1,false);
        F0(i,k){
            if(it < 2 and i < uso) novan[i+1] = true;
            else {
                novan[voy] = true;
                voy++;
                if(voy > n) voy = 1;
            }
        }
        F1(i,n) if(!novan[i]) cout<<i<<' ';
        cout<<'\n';
        cin>>x;
        res = res ^ x;
    }
    cout<<"! "<<res<<'\n';
}

void b(){
    cin>>n>>k;

    if(n%2==1 and k%2 == 0){
        cout<<"-1\n";
        return;
    }

    int d = 0;
    while(k*d < n or (k*d-n)%2) d++;

    int res = 0;
    int x;

    if(d == 2 and k*d != n){
        if(k%2 == 0){
            int rep = (3*k-n)/2;
            int voy = rep+1;
            F1(i,3){
                cout<<"? ";
                F1(j,rep) cout<<j<<' ';
                F1(j,k-rep) {
                    cout<<voy<<' ';
                    voy++;
                }
                cout<<'\n';
                cin>>x;
                res = res ^ x;
            }
            cout<<"! "<<res<<'\n';
        }
        else {
            complemento(n,k);
        }
        return;
    }

    int sobra = k*d-n;
    int uso = sobra/2;
    int voy = uso+1;
    F0(it,d){
        cout<<"? ";
        F0(i,k){
            if(it < 2 and i < uso) cout<<i+1<<' ';
            else {
                cout<<voy<<' ';
                voy++;
                if(voy > n) voy = 1;
            }
        }
        cout<<'\n';
        cin>>x;
        res = res ^ x;
    }
    cout<<"! "<<res<<'\n';
}

void test(){
    F1(n,500){
        F1(k,n){
            if(n%2==1 and k%2 == 0) continue;
            int d = 0;
            while(k*d < n or (k*d-n)%2) d++;
            if(k*d != n and d <= 2) {
                cout<<n<<' '<<k<<'\n';
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    b();
    return 0;
}