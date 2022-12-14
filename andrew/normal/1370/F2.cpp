#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5 + 2;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <int> v[MAXN], g[MAXN];

pii ask(vector <int> a){
    cout << "? " << sz(a);
    for(auto i : a)cout << " " << i;
    cout << endl;
    pii res;
    cin >> res.fi >> res.se;
    return res;
}

void dfs(int x, int pr = 0, int deep = 0){
    g[deep].p_b(x);
    for(int to : v[x])if(to != pr)dfs(to, x, deep + 1);
}

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    vector <int> a(n);
    iota(all(a), 1);
    pii temp = ask(a);
    int dist = temp.se, root = temp.fi;
    dfs(root);
    int l = (dist + 1) / 2, r = dist;
    pii f = {-1, -1};
    while(l <= r){
        int c = (l + r + 1) >> 1;
        a.clear();
        if(g[c].empty()){
            r = c - 1;
            continue;
        }
        a = g[c];
        temp = ask(a);
        if(temp.se != dist){
            r = c - 1;
        }else{
            l = c + 1;
            f = max(f, m_p(c, temp.fi));
        }
    }

    for(int i = 0; i <= n; i++)g[i].clear();

    root = f.se;
    dfs(root);


    a = g[dist];

    temp = ask(a);

    cout << "! " << root << " " << temp.fi << endl;

    for(int i = 0; i <= n; i++)g[i].clear();
    for(int i = 1; i <= n; i++)v[i].clear();
    string s;
    cin >> s;
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)solve();

    return 0;
}