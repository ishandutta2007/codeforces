#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ordered_set <ll> s[MAXN], s1[MAXN];
const ll N = 2e5 + 4;

ll f(ll x, ll r){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i)res += s[i].order_of_key(r);
    return res;
}

void _insert(ll pos, ll val){
    for(int i = pos; i <= N; i += i & -i)s[i].insert(val);
}

void _erase(ll pos, ll val){
    for(int i = pos; i <= N; i += i & -i)s[i].erase(val);
}

ll f1(ll x, ll r){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i)res += s1[i].order_of_key(r);
    return res;
}

void _insert1(ll pos, ll val){
    for(int i = pos; i <= N; i += i & -i)s1[i].insert(val);
}

void _erase1(ll pos, ll val){
    for(int i = pos; i <= N; i += i & -i)s1[i].erase(val);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, ans = 0;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)a[i] = i;

    for(int i = 1; i <= n; i++)_insert(i, -a[i]);
    for(int i = 1; i <= n; i++)_insert1(n - i + 1, a[i]);

    ll q;
    cin >> q;

    while(q--){
        ll l, r;
        cin >> l >> r;
        if(l != r){
            if(l > r)swap(l, r);
            ans -= f(l, -a[l]);
            ans -= f1(n - l + 1, a[l]);
            ans -= f(r, -a[r]);
            ans -= f1(n - r + 1, a[r]);

            if(l < r && a[l] < a[r])ans--;
            else ans++;

            _erase(l, -a[l]);
            _insert(r, -a[l]);
            _erase(r, -a[r]);
            _insert(l, -a[r]);

            _erase1(n - l + 1, a[l]);
            _insert1(n - r + 1, a[l]);
            _erase1(n - r + 1, a[r]);
            _insert1(n - l + 1, a[r]);

            swap(a[l], a[r]);
            ans += f(l, -a[l]);
            ans += f1(n - l + 1, a[l]);
            ans += f(r, -a[r]);
            ans += f1(n - r + 1, a[r]);

        }
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}