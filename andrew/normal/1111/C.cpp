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

ll A, B;

vector <ll> s;

ll add(ll tl, ll tr){
    ll kol = upper_bound(all(s), tr) - lower_bound(all(s), tl);
    if(!kol)return A;
    if(tl == tr)return B * kol;
    ll ans = kol * B * (tr - tl + 1);
    ll tm = (tl + tr) >> 1;
    ans = min(ans, add(tl, tm) + add(tm + 1, tr));
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, k;
    cin >> n >> k >> A >> B;

    for(int i = 1; i <= k; i++){
        ll pos;
        cin >> pos;
        s.p_b(pos);
    }

    sort(all(s));

    cout << add(1, 1ll << n) << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}