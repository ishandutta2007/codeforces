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

int pos(int i, int j){
    if(i%2 == 0) return 10*i+j;
    return 10*i+9-j;
}

int main() {
    vd dp(100);//destino es 0
    vd dpposta(100);
    vi escaleraA(100);

    vvi input(10,vi(10));
    F0(i,10) F0(j,10) cin>>input[i][j];

    F0(i,10) F0(j,10){
        if(input[i][j] == 0){
            escaleraA[pos(i,j)] = -1;
            continue;
        }
        int destino = pos(i-input[i][j],j);
        escaleraA[pos(i,j)] = destino;
    }

    F1(i,99){
        F1(d,6) {
            if(i-d < 0) break;
            dp[i] += dp[i-d]/6.0;
        }
        dp[i] += 1.0;
        if(i < 6) {
            double factor = 1.0 - double(6 - i) / double(6);
            dp[i] /= factor;
        }
        dpposta[i] = dp[i];

        if(escaleraA[i] != -1 and dpposta[escaleraA[i]] < dp[i]) {
            dp[i] = dpposta[escaleraA[i]];
        }
    }

    cout<<setprecision(8)<<fixed<<dp[99]<<'\n';

    return 0;
}