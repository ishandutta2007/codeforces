#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll f(){
    return (rand() << 16) + rand();
}

struct node{
    int key, ans, prior;
    bool fl;
    node *l, *r;
    node(int x) : key(1), ans(x), prior(f()), l(r=nullptr), fl(0) {}
};

node *root;

int kval(node *T){
    if(T == nullptr)return 0;
    return T -> key;
}


void push(node *T){
    if(T -> fl){
        swap(T -> l, T -> r);
        T -> fl = 0;
        if(T -> l != nullptr)(T -> l) -> fl ^= 1;
        if(T -> r != nullptr)(T -> r) -> fl ^= 1;
    }
}

void unite(node *t){
    t -> key = 1 + kval(t -> l) + kval(t -> r);
    return;
}

pair <node *, node *> split(node *T, int key){
    if(T == nullptr)return {nullptr, nullptr};
    push(T);
    if(kval(T -> l) + 1 < key){
        pair <node *, node *> tk = split(T -> r, key - kval(T -> l) - 1);
        T -> r = tk.fi;
        unite(T);
        return {T, tk.se};
    }else{
        pair <node *, node *> tk = split(T -> l, key);
        T -> l = tk.se;
        unite(T);
        return {tk.fi, T};
    }
}


node *merge(node *a, node *b){
    if(a == nullptr)return b;
    if(b == nullptr)return a;
    push(a);
    push(b);
    if(a -> prior > b -> prior){
        a -> r = merge(a -> r, b);
        unite(a);
        return a;
    }
    b -> l = merge(a, b -> l);
    unite(b);
    return b;
}

void insert(int x, int val){
    pair <node *, node *> tk = split(root, x + 1);
    node *tt = new node(val);
    root = merge(merge(tk.fi, tt), tk.se);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, q, m;
    cin >> n >> q >> m;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++)insert(i - 1, a[i]);
    while(q--){
        ll t, l, r;
        cin >> t >> l >> r;

        if(t == 1){
            pair <node *, node *> tk = split(root, l);
            pair <node *, node *> te = split(tk.se, r - l + 2);
            pair <node *, node *> kek = split(te.fi, r - l + 1);
            root = merge(merge(tk.fi, merge(kek.se, kek.fi)), te.se);
        }else{
            pair <node *, node *> tk = split(root, l);
            pair <node *, node *> te = split(tk.se, r - l + 2);
            te.fi -> fl ^= 1;
            push(te.fi);
            root = merge(tk.fi, merge(te.fi, te.se));
        }
    }

    while(m--){
        ll x;
        cin >> x;
        pair <node *, node *> tk = split(root, x);
        pair <node *, node *> te = split(tk.se, 2);
        cout << te.fi -> ans << " ";
        root = merge(tk.fi, merge(te.fi, te.se));
    }
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}