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
const ll MAXN = 3123456;
const ll N = 2e5;
const ll inf = 3e18;
const ll buben = 338;
const ll mod = 1e9 + 7;
const ll step = 200003;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    vector <int> b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        b[i]--;
    }
    if(y == n && x == n - 1)fout("NO");

    vector <int> cnt(n + 1);
    vector < vector <int> > v(n + 1);


    int temp_x = x;
    vector <int> ans(n + 1);

    fill(all(ans), -1);

    ll need = y - x;

    vector <int> temp;

    set <pii> st;


    for(int i = 1; i <= n; i++){
        cnt[b[i]]++;
        v[b[i]].p_b(i);
    }

    for(int i = 0; i <= n; i++){
        st.insert({cnt[i], i});
    }

    while(!st.empty() && temp_x--){
        pii xe = *(--st.end());
        st.erase(xe);
        ans[v[xe.se].back()] = xe.se;
        v[xe.se].pop_back();
        xe.fi--;
        if(xe.fi)st.insert(xe);
    }

    pii xe = *--st.end();

    if((xe.fi - (n - y)) * 2 > y - x)fout("NO");

    for(int i = 0; i <= n; i++){
        for(auto j : v[i]){
            temp.p_b(j);
        }
    }

    for(int step = 0, i = 0, uk = (n - x) / 2; need; i++, uk = (uk + 1) % sz(temp)){
        if(b[temp[i]] != b[temp[uk]] && ans[temp[i]] == -1){
            need--;
            ans[temp[i]] = b[temp[uk]];
        }
    }

    cout << "YES\n";
    int trash = -1;
    for(int i = 0; i <= n; i++)if(!cnt[i])trash = i;

    for(int i = 1; i <= n; i++)if(ans[i] < 0){
        ans[i] = trash;
    }
    for(int i = 1; i <= n; i++)cout << ans[i] + 1 << " ";
    cout << "\n";
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;

    while(t--)solve();

    return 0;
}