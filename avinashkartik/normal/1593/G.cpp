#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, q, a[N];
string s;

struct NODE{
    ll f, s, l;
    NODE(): f(-1), s(-1), l(0) {}
    NODE(int x): f(x), s(x), l(1) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
    if (a.l == 0) {
        return b;
    } 
    if (b.l == 0) {
        return a;
    }
    NODE c;
    c.l = a.l + b.l;
    c.f = a.f;
    c.s = b.s;
    if (a.s == b.f) {
        c.l -= 2 * min(a.l, b.l);
        if (c.l == 0) {
            return NODE();
        } else if (a.l > b.l) {
            if (c.l % 2 == 0) c.s = 1 ^ a.f;
            else c.s = a.f;
        } else {
            if (c.l % 2 == 0) c.f = 1 ^ b.s;
            else c.f = b.s;
        }
    }
    return c;
}

void build(int node, int start, int end){
    if(start == end){
        tree[node] = NODE(a[start]);
    }
    else{
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }
}

NODE query(int node, int start, int end, int l, int r){
    if(start > end or start > r or end < l)
        return NODE();
    if(l <= start and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    NODE p1 = query(2*node, start, mid, l, r);
    NODE p2 = query(2*node+1, mid+1, end, l, r);
    return combine(p1, p2);
}

void solve() {
    cin >> s;
    n = s.size();
    s = '#' + s + '#';
    for (int i = 1; i <= n; i++) {
        if (s[i] == '[' || s[i] == ']') a[i] = 1;
        else a[i] = 0;
    }
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        NODE Q = query(1, 1, n, l, r);
        deb1(Q.l / 2)
    }
}

int main() {
    GODSPEED;
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        solve();
    }
}