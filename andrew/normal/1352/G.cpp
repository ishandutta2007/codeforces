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

vector <int> ans[MAXN];

void solve(){
    int n;
    cin >> n;
    if(n <= 9){
        for(auto i : ans[n])cout << i << " ";
        cout << "\n";
    }else{
        vector <int> ans;
        if(n % 2 == 1){
            int x = n;
            while(x != -1){
                ans.p_b(x);
                x -= 2;
            }
            ans.p_b(4);
            ans.p_b(2);
            ans.p_b(6);
            x = 8;
            while(x <= n){
                ans.p_b(x);
                x += 2;
            }
            for(auto i : ans)cout << i << " ";
            cout << "\n";
        }else{
            int x = n;
            while(x != 0){
                ans.p_b(x);
                x -= 2;
            }
            ans.p_b(5);
            ans.p_b(1);
            x = 3;
            while(x <= n){
                ans.p_b(x);
                x += 2;
                if(x == 5)x += 2;
            }
            for(auto i : ans)cout << i << " ";
            cout << "\n";
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    for(int m = 1; m <= 9; m++){
        vector <int> p(m);
        iota(all(p), 0);
        ans[m].p_b(-1);
        do{
            bool good = 1;
            for(int i = 1; i < m; i++){
                if(!(2 <= abs(p[i] - p[i - 1]) && abs(p[i] - p[i - 1]) <= 4))good = 0;
            }
            if(good){
                ans[m] = p;
                for(auto &j : ans[m])j++;
            }
        }while(next_permutation(all(p)));
    }
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}