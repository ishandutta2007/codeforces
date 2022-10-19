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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

int n,k;

void e(){
    cin>>n>>k;
    vll a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));

    vll suf(n+1);
    F0R(i,n) suf[i] = suf[i+1] + a[i];

    vll esc(n+1);
    F0R(i,n) esc[i] = esc[i+1] + suf[i];

    ll eq = 0;

    ll res = esc[1];

    F0(i,n-1){
        ll pos = i / (k+1);
        eq += a[i] * pos;
        pos = (i+k) / (k+1);
        maxi(res,eq + esc[i+2] + suf[i+1] * pos);
    }

    ll pos = (n-1) / (k+1);
    eq += a.back() * pos;
    maxi(res,eq);

    cout<<res<<'\n';

}

void e2(){
    cin>>n>>k;
    vll a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));
    reverse(todo(a));

    priority_queue<ll> q;
    F0(i,k+1) q.push(0);

    ll res = 0;
    F0(i,n) {
        ll x = q.top();
        q.pop();
        res += x;
        q.push(x + a[i]);
    }

    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    e2();
    return 0;
}