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

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi b(32);
    F0(i,n) {
        F0(j,31){
            if(a[i] & (1<<j)) b[j]++;
        }
    }

    int res = 0;
    int resi = 0;
    int prim = 0;
    F0(i,n){
        resi = 0;
        F0(j,32){
            if(a[i] & (1<<j) and b[j] == 1) resi += (1<<j);
        }
        if(resi > res) {
            res = resi;
            prim = i;
        }
    }

    cout<<a[prim];
    F0(i,n){
        if(i == prim) continue;
        cout<<' '<<a[i];
    }
    cout<<'\n';
}

void b(){
    int n;
    cin>>n;
    vll x(n);
    vll y(n);
    F0(i,n) cin>>x[i]>>y[i];

    vll lx(n);
    vll ly(n);
    lx[0] = x[0] - x[n-1];
    ly[0] = y[0] - y[n-1];
    F1(i,n-1){
        lx[i] = x[i] - x[i-1];
        ly[i] = y[i] - y[i-1];
    }

    if(n%2 != 0){
        cout<<"NO\n";
        return;
    }

    F0(i,n/2){
        if(lx[i] != -lx[i+n/2]){
            cout<<"NO\n";
            return;
        }
        if(ly[i] != -ly[i+n/2]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    b();
    return 0;
}