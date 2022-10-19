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

void a(){
    int n,x;
    cin>>n>>x;
    vb a(202,false);
    int b;
    F0(i,n) {
        cin>>b;
        a[b] = true;
    }
    F1(i,201) {
        if(!a[i] and x == 0) {
            cout<<i-1<<'\n';
            return;
        }
        if(a[i]) continue;
        x--;
    }
}

bool puedeSer(vi& ap, int n){
    REP(i,2,n) if(ap[i] > ap[i-1]) return false;
    return ap[1] == 2;
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi ap(n+1);
    F0(i,n) ap[a[i]]++;
    if(!puedeSer(ap,n)){
        cout<<"0\n";
        return;
    }
    int l1 = n;
    while(ap[l1] != 2) l1--;
    int l2 = n-l1;
    vpi res;
    set<int> s;
    F0(i,l1) s.insert(a[i]);
    if(s.size() == l1 and l1 == *s.rbegin()) res.pb({l1,l2});
    s.clear();
    reverse(todo(a));
    F0(i,l1) s.insert(a[i]);
    if(s.size() == l1 and l1 == *s.rbegin() and l1 != l2) res.pb({l2,l1});

    cout<<res.size()<<'\n';
    for(auto p : res) cout<<p.first<<' '<<p.second<<'\n';

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