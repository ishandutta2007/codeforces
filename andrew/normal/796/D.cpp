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
const ll N = 2e6;
const ll inf = 2e9;
const ll M = 300000;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <pii> v[MAXN];
bool f[MAXN];
int pr[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int n, k, d;
    cin >> n >> k >> d;

    vector <int> s;

    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        s.p_b(x);
    }

    queue <int> q;

    for(int i : s){
        if(f[i])continue;
        f[i] = 1;
        q.push(i);
    }

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].p_b({b, i});
        v[b].p_b({a, i});
    }

    set <int> res;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(pii to : v[x])if(to.fi != pr[x]){
            if(f[to.fi]){
                res.insert(to.se);
            }else{
                q.push(to.fi);
                f[to.fi] = 1;
                pr[to.fi] = x;
            }
        }
    }

    cout << sz(res) << "\n";
    for(int i : res)cout << i << " ";
    cout << "\n";

    return 0;
}