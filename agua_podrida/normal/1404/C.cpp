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
#define PI acos(-1.0)
/*
bool sacar(pll izq, pll p, pll der){
    ll x1 = izq.first; ll y1 = izq.second;
    ll x2 = p.first; ll y2 = p.second;
    ll x3 = der.first; ll y3 = der.second;
    ll ym = y1 * (x3 - x2) + y3 * (x2 - x1);
    y2 *= (x3 - x1);
    return y2 <= ym;
}

bool sacarIzq(set<pll>& ch, pll p){
    auto it = ch.find(p);
    if(it != ch.begin()){
        auto itizq = it;
        itizq--;
        if(itizq != ch.begin()){
            auto itizqizq = itizq;
            itizqizq--;
            if(sacar(*itizqizq,*itizq,*it)) {
                ch.erase(itizq);
                return true;
            }
        }
    }
    return false;
}

bool sacarDer(set<pll>& ch, pll p){
    auto it = ch.find(p);
    auto itder = it;
    itder++;
    if(itder != ch.end()){
        auto itderder = itder;
        itderder++;
        if(itderder != ch.end() and sacar(*it,*itder,*itderder)){
            ch.erase(itder);
            return true;
        }
    }
    return false;
}

void meter(set<pll>& ch, pll p){
    auto it = ch.lower_bound(mp(p.first,-INF));
    if(it != ch.end() and it->first == p.first and it->second >= p.second) return;
    else ch.insert(p);
    auto itizq = ch.find(p);
    if(itizq != ch.begin()){
        itizq--;
        auto itder = ch.find(p);
        itder++;
        if(itder != ch.end() and sacar(*itizq,p,*itder)){
            ch.erase(p);
            return;
        }
    }

    while(sacarIzq(ch,p));
    while(sacarDer(ch,p));
}
*/


struct segmentSum{
    segmentSum(int nn);

    void inc(int i);

    int sumr(int a, int b);

    int total(){
        return tree[1];
    }

    int lo(int s){ //max pos l tal que sumr(l,n-1) da >= s
        int i = 1;
        while(i < n){
            if(tree[2*i+1] >= s) i = 2*i+1;
            else {
                s -= tree[2*i+1];
                i = 2*i;
            }
        }
        return i-n;
    }

    int n;
    vi tree;
};

segmentSum::segmentSum(int nn) {
    n = nn;
    tree = vi(2*n);
}

void segmentSum::inc(int i) {
    i += n;
    tree[i]++;
    for(i /= 2; i >= 1; i /= 2) tree[i] = tree[2*i] + tree[2*i+1];
}

int segmentSum::sumr(int a, int b) {
    a += n; b += n;
    int sum = 0;
    while(a <= b){
        if(a % 2 == 1) sum += tree[a++];
        if(b % 2 == 0) sum += tree[b--];
        a /= 2; b /= 2;
    }
    return sum;
}


struct Q{
    Q(int a, int b, int c){
        l = a;
        r = b;
        i = c;
    }

    bool operator<(Q q) const{
        if(r != q.r) return r < q.r;
        if(l != q.l) return l < q.l;
        return i < q.i;
    }

    int l;
    int r;
    int i;
};

void c(){
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    F1(i,n) cin>>a[i];
    F1(i,n) a[i] = i-a[i];

    vector<Q> querys;
    int x,y;
    F0(i,q){
        cin>>x>>y;
        querys.pb(Q(x+1,n-y,i));
    }

    vi res(q);
    sort(todo(querys));
    int i = 0;
    int r = 0;
    segmentSum s(n+1);
    while(r < n){
        r++;
        if(a[r] == 0) s.inc(r);
        else if(a[r] > 0 and a[r] <= s.total()){
            int lo = 1;
            int hi = r;
            while(lo+1 != hi){
                int m = (lo+hi)/2;
                if(s.sumr(m,n) >= a[r]) lo = m;
                else hi = m;
            }
            s.inc(lo);
        }
        while(i < querys.size() and querys[i].r == r){
            int l = querys[i].l;
            res[querys[i].i] = s.sumr(l,n);
            i++;
        }
    }

    F0(i,q) cout<<res[i]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}