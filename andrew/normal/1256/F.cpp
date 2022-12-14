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


string sol(){
    string s, t;
    ll n;
    cin >> n;
    cin >> s >> t;
    map <ll, ll> mp, mp1;

    for(auto i : s)mp[i - 'a']++;
    for(auto i : t)mp1[i - 'a']++;

    if(mp != mp1)return "NO";

    for(auto i : mp){
        if(i.se > 1)return "YES";
    }

    ll kol = 0;

    for(int i = 0; i < n; i++){
        ll j = i;
        while(s[j] != t[i])j++;
        while(j > i)swap(s[j], s[j - 1]), j--, kol++;
    }

    if(kol % 2)return "NO";
    return "YES";

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll q;

    cin >> q;

    while(q--){
        cout << sol() << "\n";
    }

    return 0;
}