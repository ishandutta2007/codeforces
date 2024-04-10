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
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

struct p3 {
    p3(int a, int b, int c, int i){
        x = a;
        y = b;
        z = c;
        id = i;
    }
    bool operator<(p3 otro) const {
        if(x != otro.x) return x < otro.x;
        if(y != otro.y) return y < otro.y;
        if(z != otro.z) return z < otro.z;
        return id < otro.id;
    }
    int x;
    int y;
    int z;
    int id;
};

void c(){
    int n;
    cin>>n;
    set<p3> puntos;
    int x,y,z;
    F1(i,n){
        cin>>x>>y>>z;
        puntos.insert(p3(x,y,z,i));
    }


}

void d(){
    int n;
    cin>>n;
    vi c(3*n);
    F0(i,n) cin>>c[i];
    F0(i,n) c[i+n] = c[i];
    F0(i,n) c[i+2*n] = c[i];
    multiset<int> adentro;
    int i = 0;
    int j = 0;
    int maxC = c[0];
    vi res;
    while(i < n){
        while(j < 3*n and 2*c[j] >= maxC){
            adentro.insert(c[j]);
            maxi(maxC,c[j]);
            j++;
        }
        if(j == 3*n) res.pb(-1);
        else res.pb(j-i);
        auto it = adentro.find(c[i]);
        adentro.erase(it);
        if(adentro.empty()) maxC = 0;
        else {
            it = adentro.end();
            --it;
            maxC = *it;
        }
        i++;
    }
    F0(k,n){
        cout<<res[k]<<' ';
    }
    cout<<'\n';
}

int main() {
    d();
}