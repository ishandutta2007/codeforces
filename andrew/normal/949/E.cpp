#include <bits/stdc++.h>

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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> ans;
vector <ll> now;

void dfs(ll deep, vector <ll> a){
    if(deep > 20){
        if(sz(a) == 1 && a.back() == 0){
            if(ans.empty() || sz(ans) > sz(now)){
                ans = now;
            }
        }
        return;
    }
    bool f = 0;
    for(auto i : a)if((abs(i) & 1))f = 1;
    if(!f){
        for(auto &i : a)i >>= 1;
        dfs(deep + 1, a);
    }else{
        ll x = pw(deep);
        now.p_b(x);
        vector <ll> b;
        for(auto i : a){
            if((abs(i) & 1)){
                b.p_b((i - 1) >> 1);
            }else{
                b.p_b(i >> 1);
            }
        }
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        dfs(deep + 1, b);
        now.pop_back();

        b.clear();
        now.p_b(-pw(deep));
        for(auto i : a){
            if((abs(i) & 1)){
                b.p_b((i + 1) >> 1);
            }else{
                b.p_b(i >> 1);
            }
        }
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        dfs(deep + 1, b);
        now.pop_back();
    }
}

void main_solve(){
    ll n;
    ans.clear();
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    dfs(0, a);
    cout << sz(ans) << "\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        for(int id = 1; id <= t; id++){
            cout << "Test number " << id << ":\n";
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL



    return 0;
}