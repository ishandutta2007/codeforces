#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define pll pair<ll, ll>
#define m_p make_pair
#define p_b push_back
#define all(v) v.begin(), v.end()
#define sqr(x)  (x) * (x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

bool check(vector <ll> &c){
    ll n = c.size();
    for(int i = 1; i < ll(c.size()) - 1; i++){
        for(int j = 1; j <= min((ll)i, n - i - 1); j++)
            if(c[i + j] == c[i - j] && c[i] == c[i + j])return 1;
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    string s;
    cin >> s;
    ll n = s.size(), ans = 0;
    for(int i = 1; i <= n - 2; i++){
        vector <ll> c;
        for(int j = i; j <= n; j++){
            c.p_b(s[j - 1] - '0');
            if(check(c)){
                ans += n - j + 1;
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}