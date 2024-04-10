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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    set <ll> s;

    vector <ll> ans;

    map <ll, ll> mp;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        if(x < 0){
            x *= -1;
            if(s.find(x) == s.end())vout(-1);
            s.erase(x);
        }else{
            if(mp[x])vout(-1);
            mp[x] = 1;
            s.insert(x);
        }
        if(s.empty()){
            ans.p_b(i);
            mp.clear();
        }
    }

    if(!s.empty())vout(-1);
    cout << ans.size() << "\n";
    ll last = 0;
    for(auto i : ans){
        cout << i - last << " ";
        last = i;
    }
    cout << "\n";

    return 0;
}