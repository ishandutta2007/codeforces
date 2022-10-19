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
#define mod 998244353
/*
struct node {
    node* left;
    node* right;
    int weight, size;
    int val;
    node(int a){
        left = right = NULL;
        weight = rand();
        size = 1;
        val = a;
    }
};

int size(node* treap){
    if(treap == NULL) return 0;
    return treap->size;
}

void split(node* treap, node*& left, node*& right, int k){
    if(treap == NULL) left = right = NULL;
    else {
        if(size(treap->left) < k){
            split(treap->right,treap->right,right,k-size(treap->left)-1);
            left = treap;
        }
        else {
            split(treap->left,left,treap->left,k);
            right = treap;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
    }
}

void merge(node*& treap, node* left, node* right){
    if(left == NULL) treap = right;
    else if(right == NULL) treap = left;
    else {
        if(left->weight < right->weight){
            merge(left->right,left->right,right);
            treap = left;
        }
        else {
            merge(right->left,left,right->left);
            treap = right;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
    }
}

node* vi_to_treap(vi& s){
    node* treap = NULL;
    F0(i,s.size()) merge(treap,treap,new node(s[i]));
    return treap;
}

vi treap_to_vi(node* treap){
    if(treap == NULL) return {};
    vi res = treap_to_vi(treap->left);
    res.pb(treap->val);
    vi resd = treap_to_vi(treap->right);
    F0(i,resd.size()) res.pb(resd[i]);
    return res;
}

void k(){
    string s;
    cin>>s;
    vi v(s.size());
    F0(i,s.size()) v[i] = (int) s[i] - (int) 'a';
    node* treap = vi_to_treap(v);
    node* a = NULL;
    node* b = NULL;
    node* c = NULL;
    node* d = NULL;
    node* e = NULL;
    int n,i,j,k,l;
    cin>>n;
    while(n--){
        cin>>i>>j>>k>>l;
        split(treap,a,b,i-1);
        split(b,b,c,j-i+1);
        split(c,c,d,k-j-1);
        split(d,d,e,l-k+1);

        invertir(b); incrementar(b,1);
        invertir(d); incrementar(d,1);

        treap = NULL;
        merge(treap,treap,a);
        merge(treap,treap,d);
        merge(treap,treap,c);
        merge(treap,treap,b);
        merge(treap,treap,e);
    }

    v = treap_to_vi(treap);
    F0(i,v.size()) cout<<(char) (v[i]%26 + (int) 'a');
    cout<<'\n';
}
*/
void a(){
    int y,r,b;
    cin>>y>>b>>r;
    b--;
    r--; r--;
    int res = min(y,r);
    mini(res,b);
    res *= 3;
    res += 3;
    cout<<res<<'\n';
}

void b(){
    int n;
    cin>>n;
    vpll a(n);
    F0(i,n) cin>>a[i].first>>a[i].second;
    vpll b(n);
    F0(i,n) cin>>b[i].first>>b[i].second;
    ll x = 0, y = 0;
    F0(i,n) x += a[i].first;
    F0(i,n) x += b[i].first;
    F0(i,n) y += a[i].second;
    F0(i,n) y += b[i].second;
    x /= n;
    y /= n;
    cout<<x<<' '<<y<<'\n';
}

void c(){
    ll n;
    cin>>n;
    vll div;
    ll x = 1;
    while(x*x <= n){
        if(n % x == 0) {
            div.pb(x);
            if(x*x != n) div.pb(n/x);
        }
        x++;
    }

    sort(todo(div));
    reverse(todo(div));
    int m = div.size();
    vll res(m);
    F0(i,m){
        res[i] = n / div[i] * (n-div[i]) / 2;
        res[i] += n/div[i];
    }

    for(auto r : res) cout<<r<<' ';
    cout<<'\n';
}

ll pot(ll a, int exp){
    if(exp == 0) return 1;
    ll b = pot(a,exp/2);
    b *= b;
    b %= mod;
    if(exp%2) b *= a;
    b %= mod;
    return b;
}

const int N = 1000000;
ll fact[N+1];

void calcfact(){
    fact[0] = 1;
    F1(i,N) fact[i] = (fact[i-1] * (ll) i) % mod;
}

ll inv(ll a){
    return pot(a,mod-2);
}

void d(){
    ll n;
    cin>>n;
    ll res = fact[n];
    F1(i,n-2){
        ll prod = (fact[n] * inv(fact[n-i]))%mod;
        prod *= (fact[n-i]-1);
        prod %= mod;
        res += prod;
        res %= mod;
    }
    cout<<res<<'\n';
}

bool s(vll d){
    while(!d.empty()){
        sort(todo(d));
        if(d.back() < 0) return false;
        if(d.back() >= d.size()) return false;
        REP(i,d.size()-d.back()-1,d.size()-2) d[i]--;
        d.pop_back();
    }
    return true;
}

void e(){
    int n;
    cin>>n;
    vll d(n);
    F0(i,n) cin>>d[i];
    sort(todo(d));
    d.pb(0);
    reverse(todo(d));
    vll pref(n+1);
    F1(i,n) pref[i] = d[i]+pref[i-1];
    if(d[1] == n and d.back() == 0) {
        cout<<"-1\n";
        return;
    }
    vll dp(n+2);
    vll suf(n+3);
    suf[n+1] = 0;
    F0R(i,n+1) suf[i] = d[i]+suf[i+1];
    ll l1 = n+1;
    ll l2 = n+1;
    for(ll k = 1; k <= n; k++){
        while(l1-1 > k and d[l1-1] <= k) l1--;
        while(l2-1 > k and d[l2-1] <= k+1) l2--;
        maxi(l1,k+1);
        maxi(l2,k+1);
        //d > dk
        ll hi = k*(k+1) + (l2 - k - 1) * (k+1) + suf[l2] - pref[k];
        mini(hi,(ll) n);
        if(hi > d[k]){
            dp[d[k]+1]++;
            dp[hi+1]--;
        }
        //d < dk
        ll lo = pref[k] - k*(k-1) - (l1 - k - 1) * k - suf[l1];
        maxi(lo,0ll);
        if(k >= lo and lo < d[k]){
            dp[lo]++;
            dp[d[k]]--;
        }
        //d == dk
        if(k >= lo and d[k] <= hi and d[k] >= lo) {
            dp[d[k]]++;
            dp[d[k]+1]--;
        }
    }
    F1(i,n) dp[i] += dp[i-1];

    ll m = 0;
    for(auto di : d) m += di;
    ll lo = 0;
    ll hi = n;
    F1(i,n) if(d[i] == 0) hi--;
    F1(i,n) if(d[i] == n) lo++;
    vll res;
    ll k = 0;
    l1 = n+1;
    l2 = n+1;
    F0R(di,n+1){
        while(k < n and d[k+1] >= di) k++;
        while(l1-1 > k and d[l1-1] <= k) l1--;
        while(l2-1 > k and d[l2-1] <= k+1) l2--;
        maxi(l1,k+1);
        maxi(l2,k+1);

        if(k > 0 and pref[k] > k*(k-1) + suf[l1] + (l1-k-1)*k + min((ll) di,k)) continue;
        if(pref[k] + (ll) di > k*(k+1) + suf[l2] + (l2-k-1)*(k+1)) continue;

        if((di+m) % 2) continue;
        if(di < lo) continue;
        if(di > hi) continue;
        if(dp[di] != n) continue;

        res.eb(di);
    }
    reverse(todo(res));
    if(res.empty()) cout<<"-1\n";
    else {
        for(auto di : res) cout<<di<<' ';
        cout<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    calcfact();
    e();
    return 0;
}