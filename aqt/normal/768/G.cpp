#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef gp_hash_table<int, null_type,hash<int>, equal_to<int>, direct_mask_range_hashing<int>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<true>,true>> hash_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb emplace_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 100005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp>>1,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

template<typename T>
struct node{
    T val,sum; int sz; int prior;
    node *l,*r;
    node(T v){
        val = v, sz = 1, sum = val;
        prior = randint(1,1e9);
        l = r = 0;
    }
};

template<typename T>
struct SMTreap{
    node<T> *rt=0;

    inline int gsz(node<T> *&n){return n?n->sz:0;}
    inline void upd_sz(node<T> *&n){if(n)n->sz=gsz(n->l)+gsz(n->r)+1;}
    inline T gsum(node<T> *&n){return n?n->sum:0;}
    inline void upd_sum(node<T> *&n){if(n)n->sum=gsum(n->l)+gsum(n->r)+n->val;}
    inline void upd(node<T> *&n){upd_sz(n);upd_sum(n);}

    inline int size(){return gsz(rt);}

    void split(node<T> *n, T key, node<T> *&l, node<T> *&r){
        if(!n) l = r = 0;
        else if(key < n->val) split(n->l,key,l,n->l), r = n;
        else split(n->r,key,n->r,r), l = n;
        upd(n);
    }
    void merge(node<T> *&n, node<T> *l, node<T> *r){
        if(!l || !r) n = l?l:r;
        else if(l->prior > r->prior) merge(l->r,l->r,r), n = l;
        else merge(r->l,l,r->l), n = r;
        upd(n);
    }
    void insert(node<T> *&n, node<T> *v){
        if(!n) n = v;
        else if(v->prior > n->prior) split(n,v->val,v->l,v->r), n = v;
        else insert(v->val<n->val?n->l:n->r,v);
        upd(n);
    }
    void erase(node<T> *&n, T v){
        if(!n) return;
        if(n->val == v) merge(n,n->l,n->r);
        else erase(v<n->val?n->l:n->r,v);
        upd(n);
    }
    T kth(node<T> *&n, int idx){
        if(gsz(n->l)+1 == idx) return n->val;
        else if(gsz(n->l) >= idx) return kth(n->l,idx);
        return kth(n->r,idx-gsz(n->l)-1);
    }
    bool contains(node<T> *&n, T v){
        if(!n) return false;
        if(n->val == v) return true;
        if(n->val < v) return contains(n->r,v);
        return contains(n->l,v);
    }
    int num_less(node<T> *&n, T v){
        if(!n) return 0;
        if(n->val <= v) return gsz(n->l)+1+num_less(n->r,v);
        return num_less(n->l,v);
    }
    int range_query(int l, int r){
        return num_less(rt,r)-num_less(rt,l-1);
    }
    ll sum_k(node<T> *&n, int k){
        if(!n) return 0;
        if(gsz(n->l)+1 == k) return gsum(n->l)+n->val;
        else if(gsz(n->l)+1 < k) return gsum(n->l)+n->val+sum_k(n->r,k-gsz(n->l)-1);
        return sum_k(n->l,k);
    }
    void print(){
        for(int i=1; i<=gsz(rt); i++)
            printf("%d ",kth(rt,i));
        printf("\n");
    }
};

struct snode{
    int l,r;
    SMTreap<int> s;
};

int N,sz[MAXN],in[MAXN],out[MAXN],cnt,ans[MAXN],tmp[MAXN],rt;
int bit[2*MAXN];
vector<int> adj[MAXN];
snode seg[4*MAXN];
SMTreap<int> s;

inline void update(int pos, int val){
    for(int i=pos ;i<=2*N; i+=i&-i)
        bit[i]+=val;
}

inline int query(int pos){
    int res = 0;
    for(int i=pos ;i>0; i-=i&-i)
        res+=bit[i];
    return res;
}

inline int query(int l, int r){
    return query(r)-query(l-1);
}

void build(int l, int r, int rt){
    seg[rt].l = l, seg[rt].r = r;
    if(l == r) return;
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}

void update(int pos, int rt, int val, int s){
    if(s == 0) seg[rt].s.erase(seg[rt].s.rt,val);
    else seg[rt].s.insert(seg[rt].s.rt,new node<int>(val));
    if(seg[rt].l == seg[rt].r) return;
    int mid = (seg[rt].l+seg[rt].r)>>1;
    if(pos <= mid) update(pos,rt<<1,val,s);
    else update(pos,rt<<1|1,val,s);
}

int query_amnt(int l, int r, int rt, int vl, int vr){
    if(l > r) return 0;
    if(seg[rt].l == l && seg[rt].r == r){
//        seg[rt].s.print();
        return seg[rt].s.range_query(vl,vr);
    }
    int mid = (seg[rt].l+seg[rt].r)>>1;
    if(r <= mid) return query_amnt(l,r,rt<<1,vl,vr);
    else if(l > mid) return query_amnt(l,r,rt<<1|1,vl,vr);
    return query_amnt(l,mid,rt<<1,vl,vr)+query_amnt(mid+1,r,rt<<1|1,vl,vr);
}

void init(int node, int prev){
    in[node] = ++cnt;
    sz[node] = 1;
    for(int check:adj[node]){
        if(check == prev) continue;
        init(check,node);
        sz[node]+=sz[check];
    }
    update(in[node],1,sz[node],1);
    tmp[in[node]] = sz[node];
    out[node] = cnt;
}

void solve(int node, int prev){
    vector<pii> v;
    update(in[node],1,sz[node],0);
    for(int check:adj[node]){
        if(check == prev) continue;
        v.pb(mp(sz[check],check));
    }
    if(node != rt) v.pb(mp(N-sz[node],prev));
    sort(all(v),greater<pii>());
    if(v.empty()) ans[node] = 0;
    else if(v.size() == 1) ans[node] = v[0].first;
    else{
        if(v[0].first == v[1].first) ans[node] = v[0].first;
        else{
            int low = v[1].first, high = v[0].first, res = v[0].first;
            while(low <= high){
                int mid = (low+high)>>1, sum = 0, vl = v[0].first-mid, vr = mid-v.back().first;
                if(vl <= vr){
                    if(v[0].second == prev){
                        sum = query_amnt(1,in[node]-1,1,vl,vr)+query_amnt(out[node]+1,N,1,vl,vr);
                        sum+=query(vl+sz[node],vr+sz[node]);
//                    sum+=s.range_query(vl+sz[node],vr+sz[node]);
                    }else sum = query_amnt(in[v[0].second],out[v[0].second],1,vl,vr);
                }
                if(vl <= vr && sum){
                    res = mid;
                    high = mid-1;
                }else low = mid+1;
            }
            ans[node] = res;
        }
    }
    for(int check:adj[node]){
        if(check == prev) continue;
        update(sz[node],1);
//        s.insert(s.rt,new ::node<int>(sz[node]));
        solve(check,node);
        update(sz[node],-1);
//        s.erase(s.rt,sz[node]);
    }
    update(in[node],1,sz[node],1);
}

int main(){
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        int a,b; scanf(" %d %d",&a,&b);
        if(a == 0) rt = b;
        else{
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }
    build(1,N,1);
    init(rt,-1);
//    for(int i=1; i<=N; i++)
//        cout << tmp[i] << " ";
//    cout << endl;
    solve(rt,-1);
    for(int i=1; i<=N; i++)
        cout << ans[i] << endl;
}