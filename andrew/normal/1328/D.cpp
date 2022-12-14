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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    ll n;
    cin >> n;
    vector <ll> a(n), ans(n);
    for(auto &i : a)cin >> i;
    vector <ll> st(1);
    for(int i = 1; i < n; i++){
        if(a[st.back()] == a[i])continue;
        st.p_b(i);
    }
    int fufel = -1;
    if(sz(st) > 1 && a[st.back()] == a[*st.begin()]){
        fufel = st.back();
        st.pop_back();
    }
    if(sz(st) > 1 && (sz(st) % 2) && sz(st) != n){
        map <ll, ll> mp;
        for(auto i : st)mp[i] = 1;
        for(int i = 0; i < n; i++){
            if(!mp[i]){
                st.p_b(i);
                if(i == fufel)fufel = -1;
                break;
            }
        }
        sort(all(st));
    }
    if(sz(st) % 2 && sz(st) > 1){
        for(int i = 0; i < sz(st); i++){
            ans[st[i]] = i % 2 + 1;
        }
        ans[st.back()] = 3;
    }else{
        for(int i = 0; i < sz(st); i++){
            ans[st[i]] = i % 2 + 1;
        }
    }
    if(fufel != -1)ans[fufel] = ans[0];
    cout << *max_element(all(ans)) << "\n";
    ll last = 0;
    for(auto i : ans){
        if(!i)cout << last << " ";
        else{
            cout << i << " ";
            last = i;
        }
    }
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


    while(t--){
        solve();
    }

    return 0;
}