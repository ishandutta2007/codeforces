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


void e(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi ceros(n);
    F0(i,n) if(s[i] == '0') ceros[i]++;
    F1(i,n-1) ceros[i] += ceros[i-1];
    F0(i,n) {
        if(s[i] == '1') s[i] = '0';
        else s[i] = '1';
    }
    int k1 = min(21,k);
    while(k1 > 0 and (1<<(k1-1)) > n-k+1) k1--;

    vb dp((1<<k1),false);
    int val = 0;
    REP(i,k-k1,k-1){
        val *= 2;
        if(s[i] == '1') val++;
    }
    if(k-k1-1 < 0 or ceros[k-k1-1] == 0) dp[val] = true;
    int r = k;
    while(r < n){
        val *= 2;
        val %= (1<<k1);
        if(s[r] == '1') val++;
        r++;
        if(ceros[r-k1-1] - ceros[r-k-1] == 0) dp[val] = true;
    }

    F0(val,(1<<k1)){
        if(!dp[val]){
            vc res(k,'0');
            F0(j,k1) {
                if((val & (1<<j)) != 0) res[j] = '1';
            }
            cout<<"YES\n";
            F0R(i,k) cout<<res[i];
            cout<<'\n';
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) e();
    return 0;
}