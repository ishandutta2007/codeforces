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
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 70;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, q;
    cin >> n >> q;

    vector <int> p(n + 1), r(n + 1), nxt(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        r[p[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        int x = i;
        for(int j = 0; j < N; j++){
            x = p[x];
        }
        nxt[i] = x;
    }    

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int a, b;
            cin >> a >> b;
            vector <int> qry;
            int x = a;
            for(int i = 0; i < N; i++){
                qry.p_b(x);
                x = r[x];
            }
            x = b;
            for(int i = 0; i < N; i++){
                qry.p_b(x);
                x = r[x];
            }
            swap(p[a], p[b]);
            swap(r[p[a]], r[p[b]]);
            for(auto i : qry){
                int x = i;
                for(int j = 0; j < N; j++){
                    x = p[x];
                }
                nxt[i] = x;
            }
        }else{
            int x, k;
            cin >> x >> k;
            for(int i = 0; i < k / N; i++)x = nxt[x];
            for(int i = 0; i < k % N; i++)x = p[x];
            cout << x << "\n";
        }
    }

    return 0;
}