#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
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
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 100000000
#define todo(v) v.begin(),v.end()

void a(){
    string s;
    cin>>s;
    reverse(todo(s));
    int n = s.size();
    int cerosMenosUnos = 0;
    string res;
    F0(i,n){
        if(cerosMenosUnos == 0 or s[i] == '0') res.pb('0');
        else res.pb('1');
        if(s[i] == '0') cerosMenosUnos++;
        else cerosMenosUnos--;
        maxi(cerosMenosUnos,0);
    }
    reverse(todo(res));
    cout<<res<<'\n';
}

struct segmentMin{
    segmentMin(vpi& values);

    void asignar(int i, pi x);

    pi Minr(int a, int b);

    int n;
    vpi tree;
};

segmentMin::segmentMin(vpi& values) {
    n = values.size();
    tree = vpi(2*n);
    F0(i,n) tree[n+i] = values[i];
    F1R(i,n-1) tree[i] = min(tree[2*i],tree[2*i+1]);
}

void segmentMin::asignar(int i, pi x) {
    i += n;
    tree[i] = x;
    for(i /= 2; i >= 1; i /= 2) tree[i] = min(tree[2*i],tree[2*i+1]);
}

pi segmentMin::Minr(int a, int b) {
    a += n; b += n;
    pi Minimo = mp(INF,INF);
    while(a <= b){
        if(a % 2 == 1) mini(Minimo,tree[a++]);
        if(b % 2 == 0) mini(Minimo,tree[b--]);
        a /= 2; b /= 2;
    }
    return Minimo;
}

void b(){
    int n;
    cin>>n>>n;
    vi colores(n);
    F0(i,n) cin>>colores[i];

    vpi values;
    F0(i,n) values.pb(mp(colores[i],i));
    segmentMin siguienteColor(values);

    vvll dp(n+1,vll(n+1));
    F0(i,n) dp[i][i] = 1;
    F1(i,n){
        dp[i][i-1] = 1;
    }

    F1(len,n-1){
        REP(i,0,n-len-1){
            int j = i+len;
            int m = siguienteColor.Minr(i,j).S;
            ll aux = 0;
            if(m > i){
                REP(k,i,m) {
                    aux += dp[i][max(0,k-1)] * dp[k][m-1];
                    aux %= mod;
                }
            }
            else aux = 1;

            if(m < n-1){
                REP(k,m,j){
                    dp[i][j] += dp[m+1][k] * dp[k+1][j];
                    dp[i][j] %= mod;
                }
            }
            else dp[i][j] = 1;

            dp[i][j] *= aux;
            dp[i][j] %= mod;
        }
    }

    cout<<dp[0][n-1]<<'\n';
}

int main(){
    b();
    return 0;
}