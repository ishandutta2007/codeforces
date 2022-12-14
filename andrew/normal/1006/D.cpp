#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

ll last = 0;
map <char,ll> mp;
map <char,ll> mp1;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    ll sc = 0, ans = 0;
    for(int i = 1; i < n / 2 + 1; i++){
        ll l = i, r = n - i + 1;
        l--,r--;
        if(s1[l] == s1[r] && s2[l] == s2[r])continue;
        if(s2[l] == s2[r] && s1[l] != s2[r]){
            ans++;
            continue;
        }
        mp.clear();
        mp[s2[l]]++, mp[s2[r]]++;
        mp[s1[l]]--;
        if(mp[s1[l]] == -1)ans++;
        if(mp[s1[r]] < 1)ans++;
    }
    ll kek = n / 2;
    if(n % 2 && s1[kek] != s2[kek])ans++;
    cout << ans << "\n";
}