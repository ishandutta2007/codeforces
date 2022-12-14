#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e5 + 100;
const int inf = -1e9;
const ll M = 300000;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct node{
    int dp[21][2][2];
    int sum;

    void clear(){
        for(int i = 0; i < 21; i++)
        for(int j = 0; j < 2; j++){
            dp[i][j][0] = dp[i][j][1] = inf;
        }
        dp[0][0][0] = 0;
    }

};

void u(int &a, int b){
    a = max(a, b);
}

int a[MAXN];

node t[4 * N], res;

node merge(node a, node b){
    res.clear();
    res.sum = a.sum + b.sum;
    for(int i = 0; i < 21; i++){
        for(int j = 0; j + i < 22 && j < 21; j++){
            for(int f = 0; f < 2; f++)
                for(int s = 0; s < 2; s++)
                for(int f1 = 0; f1 < 2; f1++)
            for(int s1 = 0; s1 < 2; s1++)if(i + j - (s && f1) < 21){
                u(res.dp[i + j - (s && f1)][f][s1], a.dp[i][f][s] + b.dp[j][f1][s1]);
            }
        }
    }

    return res;
}

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v].clear();
        t[v].dp[1][1][1] = a[tl];
        t[v].sum = a[tl];
    }else{
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

void modify(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        a[tl] = val;
        t[v].clear();
        t[v].dp[1][1][1] = a[tl];
        t[v].sum = a[tl];
    }else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            modify(v << 1, tl, tm, pos, val);
        }else{
            modify(v << 1 | 1, tm + 1, tr, pos, val);
        }
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

node result;
bool f = 0;

void get(int v, int tl, int tr, int l, int r){
    if(l > r)return;
    if(tl == l && tr == r){
        if(!f){
            result = t[v];
            f = 1;
            return;
        }
        result = merge(result, t[v]);
        return;
    }
    int tm = (tl + tr) >> 1;
    get(v << 1, tl, tm, l, min(r, tm));
    get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)cin >> a[i];

    build(1, 1, n);

    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 0){
            ll pos, val;
            cin >> pos >> val;
            modify(1, 1, n, pos, val);
        }else{
            f = 0;
            int l, r, k;
            cin >> l >> r >> k;
            get(1, 1, n, l, r);
            int ans = 0;
            for(int i = 1; i <= k; i++)
                for(int j = 0; j < 2; j++)
                for(int i1 = 0; i1 < 2; i1++)ans = max(ans, result.dp[i][j][i1]);
            cout << ans << "\n";
        }
    }


    return 0;
}