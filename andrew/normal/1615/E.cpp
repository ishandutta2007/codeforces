#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
//const int MAXN = 100;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int tin[MAXN], tout[MAXN], is_deleted[MAXN], stn, deep[MAXN], wh[MAXN], pr[MAXN];
int t[MAXN], t1[MAXN];

vector <int> v[MAXN];

void dfs(int x, int p){
    tin[x] = ++stn;
    deep[x] = deep[p] + 1;
    pr[x] = p;
    wh[tin[x]] = x;
    for(auto to : v[x]) if(to != p){
        dfs(to, x);
    }
    tout[x] = stn;
}   

void push(int x){
    if(t1[x]){
        t[x << 1] += t1[x];
        t1[x << 1] += t1[x];
        t[x << 1 | 1] += t1[x];
        t1[x << 1 | 1] += t1[x];
        t1[x] = 0;
    }
}

void modify(int v, int tl, int tr, int l, int r, int val){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v] += val;
        t1[v] += val;
    }else{
        int tm = (tl + tr) >> 1;
        push(v);
        modify(v << 1, tl, tm, l, min(r, tm), val);
        modify(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

ll ans, pos;

void f(int v, int tl, int tr){
    if(tl == tr){
        ans = t[v];
        t[v] = 0;
        pos = wh[tl];
    }else{
        int tm = (tl + tr) >> 1;
        push(v);
        if(t[v << 1] > t[v << 1 | 1]){
            f(v << 1, tl, tm);
        }else{
            f(v << 1 | 1, tm + 1, tr);
        }
    }
}


int main(){

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++){
        modify(1, 1, n, tin[i], tin[i], deep[i]);        
    }

    vector <pair <int, int>> c;

    for(int i = 1; i <= n; i++){
        f(1, 1, n);
        c.p_b({ans, pos});
        int x = pos;
        while(x != 0){
            if(is_deleted[x]){
                break;
            }else{    
                modify(1, 1, n, tin[x], tout[x], -1);
                is_deleted[x] = 1;
                x = pr[x];
            }
        }
    }

    ll w = 0, r = 0, b = 0, ans = -1e18;

    for(int i = 0; i < k; i++){
        if(c[i].fi == 0) break;
        w += c[i].fi - 1;
        r++;            
    }

    if(r == k && c[r].fi != 0){
        ll b = n - (w + r);
        ans = w * (r - b);
        for(int i = 0; i <= b; i++){
            ll b1 = b - i, w1 = n - (r + b1), r1 = r;        
            ans = min(ans, w1 * (r1 - b1));
        }
    }else{
        for(int i = r; i <= k; i++){
            ll b1 = 0, w1 = n - i, r1 = i;
            ans = max(ans, w1 * (r1 - b1));
        }
    }

    cout << ans << "\n";


    return 0;
}