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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define mod 1000000007
#define PI acos(-1.0)


void a(){
    int n;
    cin>>n;
    string res;
    F0(i,n){
        if(i == 0) res.pb('9');
        if(i == 1) res.pb('8');
        if(i == 2) res.pb('9');
        if(i >= 3) res.pb((char) ((int) '0' + (((int) res.back() - (int) '0' + 1) % 10)));
    }
    cout<<res<<'\n';
}

bool hay3seguidos(vb& v){
    int i = 2;
    while(i < v.size() and !(v[i] and v[i-1] and v[i-2])) i++;
    return i < v.size();
}

bool hay2seguidos(vb& v){
    int i = 1;
    while(i < v.size() and !(v[i] and v[i-1])) i++;
    return i < v.size();
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    int res = 0;
    vb esmalo(n,false);
    REP(i,1,n-2){
        if(a[i] > a[i-1] and a[i] > a[i+1]) esmalo[i] = true;
        if(a[i] < a[i-1] and a[i] < a[i+1]) esmalo[i] = true;
        if(esmalo[i]) res++;
    }
    int desc = 0;
    F0(i,n){
        int d = 0;
        if(esmalo[i]) d++;
        if(i > 0){
            if(esmalo[i-1]) d++;
            if(i+1 < n and esmalo[i+1]) d++;
            if(i+2 < n and a[i+1] < a[i-1] and a[i+1] < a[i+2]) d--;
            if(i+2 < n and a[i+1] > a[i-1] and a[i+1] > a[i+2]) d--;
            maxi(desc,d);
        }
        d = 0;
        if(esmalo[i]) d++;
        if(i+1 < n){
            if(esmalo[i+1]) d++;
            if(i > 0 and esmalo[i-1]) d++;
            if(i >= 2 and a[i-1] > a[i+1] and a[i-1] > a[i-2]) d--;
            if(i >= 2 and a[i-1] < a[i+1] and a[i-1] < a[i-2]) d--;
            maxi(desc,d);
        }
    }
    res -= desc;
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) b();
    return 0;
}