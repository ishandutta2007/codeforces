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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n,m;
    cin>>n>>m;
    cout<<(n*m+1)/2<<'\n';
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));
    F0R(i,n) {
        if(a[i] <= i+1){
            cout<<i+2<<'\n';
            return;
        }
    }
    cout<<1<<'\n';
}

void c(){
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll x = x2-x1;
    ll y = y2-y1;
    ll res = min(x,y)*(min(x,y)+1) + (abs(x-y)-1) * min(x,y);
    res++;
    cout<<res<<'\n';
}

void d(){
    int n;
    ll x;
    cin>>n>>x;
    vll d(2*n);
    F0(i,n) cin>>d[i];
    F0(i,n) d[i+n] = d[i];
    reverse(todo(d));

    ll resto = -x+d[0];
    ll hugs = d[0]*(d[0]+1);
    ll res = 0;
    int l = 0;
    int r = 0;
    while(l < n){
        while(resto < 0){
            r++;
            resto += d[r];
            hugs += d[r]*(d[r]+1);
        }
        maxi(res,hugs - (resto)*(resto+1));
        resto -= d[l];
        hugs -= d[l]*(d[l]+1);
        l++;
    }
    res /= 2;
    cout<<res<<'\n';
}

void e(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,(n+1)/2) cin>>a[i];
    ll x;
    cin>>x;
    REP(i,(n+1)/2,n-1) a[i] = x;
    ll s = 0;
    F0(i,n) s += a[i];

    int k = n;
    int i = 0;
    ll minSegmento = s;
    ll sumaPref = 0;
    while(i < (n+1)/2 and minSegmento <= x* (ll) (n-k)){
        sumaPref += a[i];
        i++;
        mini(minSegmento,s-sumaPref+ x * (ll) i);
        k--;
    }
    if(minSegmento > x * (ll) (n-k)) cout<<k<<'\n';
    else cout<<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    e();
    return 0;
}