#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
//#define int long long
#define left left228
#define right right228
//#define x1 x1228                                
//#define y1 y1228
#define Matrix vector<vector<int> >
#define all(x) x.begin(), x.end()

using namespace std;

typedef long double ld; 
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rnd(time(0));
    
const int maxn = 1e5 + 7, mod = 1e9 + 7, inf = 1e9;
const double eps = 1e-9, pi = acos(-1);

struct Have {
    int x, l, r, iq;
    Have(int x, int l, int r, int iq) : x(x), l(l), r(r), iq(iq) {}
    Have() : x(0), l(0), r(0), iq(0) {}    
};

int n, k; 
Have cnt[maxn];

bool cmp(Have p1, Have p2) {
    return p1.x < p2.x;
}

struct node {
    int val, l, r; 
    node(int val, int l, int r) : val(val), l(l), r(r) {}
    node() : val(0), l(-1), r(-1) {}
};

struct Tree {
    vector<int> x;///L 
    vector<int> y;///Id

    int len = 1;
    vector<int> root;
    vector<node> tree; 

    int add(int l, int r, int l1, int r1, int rt) {
        if (l >= l1 && r <= r1) {
            node p1 = {tree[rt].val + 1, -1, -1}; 
            tree.pb(p1); 
            return tree.size() - 1;
        }   

        if (max(l, l1) > min(r, r1)) return rt; 

        int tm1 = (l + r) / 2;
        int left = add(l, tm1, l1, r1, tree[rt].l); 
        int right = add(tm1 + 1, r, l1, r1, tree[rt].r); 

        node p = {tree[left].val + tree[right].val, left, right};
        tree.pb(p);
        return tree.size() - 1;  
    } 

    int get_sum(int l, int r, int l1, int r1, int rt) {
        int tm1 = (l + r) / 2;
        if (l >= l1 && r <= r1) return tree[rt].val; 
        if (max(l, l1) > min(r, r1)) return 0; 
        else return get_sum(l, tm1, l1, r1, tree[rt].l) + get_sum(tm1 + 1, r, l1, r1, tree[rt].r); 
    }

    void build(vector<pii>& add1) {
        for (int i = 0; i < add1.size(); ++i) {
            y.pb(add1[i].ss);
        }
        
        sort(all(add1));

        for (int i = 0; i < add1.size(); ++i) x.pb(add1[i].ff);       

        root.resize(x.size() + 1); 
        
        while (len < y.size()) len<<=1; 
        tree.resize(len + len - 1);
        
        for (int i = len - 2; i >= 0; --i) {
            tree[i].l = i * 2 + 1;
            tree[i].r = i * 2 + 2;
        }

        root[0] = 0; 
        for (int i = 1; i <= add1.size(); ++i) {
            int id1 = lower_bound(all(y), add1[i - 1].ss) - y.begin();
            add(0, len - 1, id1, id1, root[i - 1]); 
            root[i] = tree.size() - 1;
        }
    }

    int get(int x1, int y1) {
        x1 = upper_bound(all(x), x1) - x.begin() - 1; 
        y1 = upper_bound(all(y), y1) - y.begin() - 1; 

        if (x1 == -1 || y1 == -1) return 0;
        return get_sum(0, len - 1, 0, y1, root[x1 + 1]);
    }

    int Get(int x1, int y1, int x2, int y2) {
        return get(x1, y1) - get(x2, y2); 
    }
}; 

vector<int> iq;

vector<pii> IQ[maxn];
Tree IQ1[maxn]; 

set<int> kek;
vector<int> x; 

ll ans = 0;   

void solve() {         
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x, d, q; cin >> x >> d >> q;
        kek.insert(q);
        cnt[i] = {x, x - d, x + d, q};         
        iq.pb(cnt[i].iq);
    }    
    sort(cnt, cnt + n, cmp); 

    for (int i = 0; i < n; ++i) x.pb(cnt[i].x);

    sort(all(iq)); iq.erase(unique(all(iq)), iq.end()); 

    for (int i = 0; i < n; ++i) {
        int id = lower_bound(all(iq), cnt[i].iq) - iq.begin();
        IQ[id].pb({cnt[i].l, i});  
    }
    
    for (int i = 0; i < maxn; ++i) {
        if (IQ[i].size()) IQ1[i].build(IQ[i]); 
    }

    for (int i = 0; i < n - 1; ++i) {
        int left = i; 
        int right = upper_bound(all(x), cnt[i].r) - x.begin() - 1; 
        for (int k1 = 0; k1 <= k; ++k1) {
            int iq1 = cnt[i].iq + k1; 
            if (kek.count(iq1) == 0) continue;
            int id = lower_bound(all(iq), iq1) - iq.begin();             
            ans += IQ1[id].Get(cnt[i].x, right, cnt[i].x, left);                            
        }

        for (int k1 = -k; k1 < 0; ++k1) {
            int iq1 = cnt[i].iq + k1; 
            if (kek.count(iq1) == 0) continue;
            int id = lower_bound(all(iq), iq1) - iq.begin(); 
            ans += IQ1[id].Get(cnt[i].x, right, cnt[i].x, left); 
        }  
    }
    cout << ans; 
}
            
signed main() {
//  freopen("", "r", stdin);
//  freopen("", "w", stdout);
#ifdef offline_judge
    freopen("TASK.in", "r", stdin);
    freopen("TASK.out", "w", stdout);
#endif
    srand(time(0));
    cout.precision(10);
    cout << fixed;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();                        
    return 0;
}