#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    cin >> s;
    ll n = s.size();
    vector <ll> dp(n);
    dp[0] = 1e18;
    vector <pll> ans;
    for(int i = 1, l = 0, r = 0; i < n; i++){
        dp[i] = 0;
        if(i <= r)dp[i] = min(dp[i - l], ll(r - i + 1));
        while(i + dp[i] < n && s[dp[i]] == s[i + dp[i]])dp[i]++;
        if(i + dp[i] > r){
            l = i;
            r = i + dp[i] - 1;
        }
    }
    multiset <ll> a;
    for(int i = 0; i < n; i++)a.insert(dp[i]);
    for(int i = 0; i < n; i++){
        while(*(a.begin()) <= i)a.erase(a.begin());
        if(dp[n - i - 1] > i){
            ans.p_b({i + 1, ll(a.size())});
        }
    }
    cout << ans.size() << "\n";
    for(auto i : ans)cout << i.fi << " " << i.se << "\n";
    return 0;
}