#include <bits/stdc++.h>

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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 2e5;
const int inf = 1e9;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct prefix_tree{
    struct node{
        node *p[2];
        pii val;
        node(){
            p[0] = p[1] = nullptr;
            val = {-1e9, -1};
        }
    };
    node *root;

    prefix_tree(){
        root = new node();
    }

    void add(int x, pii val){
        int to;
        node *q = root;
        for(int i = 29; i > -1; i--){
            to = 0;
            if((pw(i) & x)) to = 1;
            if(q -> p[to] == nullptr){
                q -> p[to] = new node();                
            }            
            q = q -> p[to];
            q -> val = max(q -> val, val);            
        }        
    }

    void f(int v, int k, pii &val){
        int to, x, y;
        node *q = root;
        for(int i = 29; i > -1; i--){
            x = (pw(i) & v) ? 1 : 0;
            y = (pw(i) & k) ? 1 : 0;
            to = x ^ y;
            if(!y){
                if(q -> p[to ^ 1] != 0){
                    val = max(val, q -> p[to ^ 1] -> val);
                }
            }
            if(q -> p[to] == nullptr){
                return;
            }
            q = q -> p[to];
        }
        val = max(val, q -> val);
    }

};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;

    prefix_tree t = *new prefix_tree();

    if(!k) {
        cout << n << "\n";
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
        return 0;
    }

    map <int, int> mp;

    vector <int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i + 1;
    }

    sort(all(a));   

    vector <pii> dp(n);

    for(int i = 0; i < n; i++){
        dp[i] = {1, -1};
        t.f(a[i], k, dp[i]);
        t.add(a[i], {dp[i].fi + 1, i});        
    }

    pii mx = *max_element(all(dp));

    if(mx.fi < 2) {
        cout << "-1\n";
        return 0;
    }

    cout << mx.fi << "\n";    

    vector <int> ans;

    int x = max_element(all(dp)) - dp.begin();

    while(x >= 0){
        ans.p_b(mp[a[x]]);
        x = dp[x].se;        
    }

    assert(sz(ans) == mx.fi);
    sort(all(ans));

    for(auto i : ans) cout << i << " ";
    cout << "\n";
    
    return 0;
}