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
ll mod = 998244353;

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
#define eps 0.000000001

void a(){
    //MarcosK si me hackeas de nuevo vas a ver!!
    int n,k;
    cin>>n>>k;
    if((n+k)%2 == 1){
        cout<<"NO\n";
        return;
    }
    ll sumaMin = 0;
    for(int i = 1; i < 2*k and sumaMin <= n; i += 2) sumaMin += (ll) i;
    if(sumaMin <= n){
        cout<<"YES\n";
    }
    else cout<<"NO\n";

}

void b(){
    int n;
    cin>>n;
    vvi grafo(n+1);
    int k;
    F1(i,n){
        cin>>k;
        grafo[i] = vi(k);
        F0(j,k) cin>>grafo[i][j];
    }

    vb libre(n+1,true);
    int soltera = -1;
    F1(i,n){
        bool consiguio = false;
        F0(j,grafo[i].size()){
            int prince = grafo[i][j];
            if(!libre[prince]){
                continue;
            }
            libre[prince] = false;
            consiguio = true;
            break;
        }
        if(!consiguio){
            soltera = i;
        }
    }
    if(soltera > 0){
        int k = 1;
        while(!libre[k]) k++;
        cout<<"IMPROVE\n";
        cout<<soltera<<' '<<k<<'\n';
        return;
    }
    cout<<"OPTIMAL\n";
}

void c(){
    int n,m,k;
    cin>>n>>m>>k;
    int aux;
    F0(i,4*k) cin>>aux;
    int l = 0;

    vc res;
    F0(i,n-1) res.pb('U');
    l += n-1;
    F0(i,m-1) res.pb('L');
    l += m-1;
    F0(i,n) {
        if(i%2 == 0){
            F0(j,m-1){
                res.pb('R');
                l++;
            }
        }
        else {
            F0(j,m-1){
                res.pb('L');
                l++;
            }
        }
        res.pb('D');
        l++;
    }
    cout<<res.size()<<'\n';
    F0(i,res.size()) cout<<res[i];
    cout<<'\n';
}

void e(){
    int n;
    cin>>n;
    if(n == 1) {
        cout<<10<<'\n';
        return;
    }
    vll pot10(n+1);
    pot10[0] = 1;
    F1(i,n) pot10[i] = (pot10[i-1]*10)%mod;

    vll res(n+1);
    F1(l,n-2){
        res[l] = (10*81*pot10[n-2-l]*(n-2-l+1) + 10*9*pot10[n-1-l]*2)%mod;
    }
    res[n-1] = 10*9*2;
    res[n] = 10;
    F1(l,n) cout<<res[l]<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    e();
    return 0;
}