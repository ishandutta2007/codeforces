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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007
#define PI acos(-1.0)

void e(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi pos = {0};
    int unos = 0;
    F0(i,n) {
        if(a[i] == 1) unos++;
        else pos.pb(unos);
    }
    int ceros = n-unos;
    int maxmov = n*(n-1)/2;
    vvvi dp(ceros+1,vvi(unos+2,vi(maxmov+1,INF)));
    F0(j,unos+2) F0(mov,maxmov+1) dp[0][j][mov] = 0;
    F1(i,ceros){
        F1(j,unos+1){
            F0(mov,maxmov+1){
                int movp = mov;
                int ip = i;
                while(movp >= 0 and ip >= 0){
                    mini(dp[i][j][mov],dp[ip][j-1][movp] + (i-ip)*(i-ip-1)/2);
                    movp -= abs(pos[ip]-(j-1));
                    ip--;
                }
            }
        }
    }
    vi res(maxmov+1);
    F0(mov,maxmov+1) res[mov] = dp[ceros][unos+1][mov];
    F1(mov,maxmov) mini(res[mov],res[mov-1]);
    F0(mov,maxmov+1) res[mov] = ceros*(ceros-1)/2 - res[mov];
    for(auto r : res) cout<<r<<' ';
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    e();
    return 0;
}