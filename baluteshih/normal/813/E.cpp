#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

struct node {
    int val, lazy;
    node *l, *r;
    node():val(0), lazy(0), l(0), r(0){}
    void up() {
        val = l -> val + r -> val;
    }
}*root[100005];

int n;

void down(int L, int R, node *&p) {
    if (!p -> lazy) return;
    p -> l = new node(*p -> l);
    p -> r = new node(*p -> r);
    int mid = (L + R) >> 1;
    p -> l -> val += p -> lazy * (mid - L + 1);
    p -> r -> val += p -> lazy * (R - mid);
    p -> l -> lazy += p -> lazy;
    p -> r -> lazy += p -> lazy;
    p -> lazy = 0;
}

node* build(int l, int r) {
    node *p = new node();
    if (l == r)
        return p;
    int mid = (l + r) >> 1;
    p -> l = build(l, mid), p -> r = build(mid + 1, r);
    return p;
}

node *modify(int L, int R, int l, int r, node *p) {
    p = new node(*p);
    if (l != r) down(l, r, p);
    if (L <= l && R >= r)
        return p -> val += (r - l + 1), p -> lazy += 1, p;
    int mid = (l + r) >> 1;
    if (L <= mid) p -> l = modify(L, R, l, mid, p -> l);
    if (R > mid) p -> r = modify(L, R, mid + 1, r, p -> r);
    p -> up();
    return p;
}

int query(int L, int R, int l, int r, node *p) {
    if (l != r) down(l, r, p);
    if (L <= l && R >= r)
        return p -> val;
    int mid = (l + r) >> 1;
    if (R <= mid) return query(L, R, l, mid, p -> l);
    if (L > mid) return query(L, R, mid + 1, r, p -> r);
    return query(L, R, l, mid, p -> l) + query(L, R, mid + 1, r, p -> r); 
}

const int MAXC = 100000;
vector<int> pl[100005];
int arr[100005];

int main() {
    IOS();
    int k, q, ans = 0, l, r;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    root[0] = build(1, n);
    for (int i = 1; i <= n; ++i) {
        if (SZ(pl[arr[i]]) >= k)
            root[i] = modify(pl[arr[i]][SZ(pl[arr[i]]) - k] + 1, i, 1, n, root[i - 1]);
        else
            root[i] = modify(1, i, 1, n, root[i - 1]);
        pl[arr[i]].pb(i);
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        l = (l + ans) % n + 1;
        r = (r + ans) % n + 1;
        if (l > r)
            swap(l, r);
        cout << (ans = query(l, l, 1, n, root[r])) << "\n";
    }
}