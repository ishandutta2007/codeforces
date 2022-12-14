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

struct zapros{
    ll l, r, number, ans;
};

ll K;

ll a[MAXN];

bool comp(zapros &a, zapros &b){
    if(a.l / K != b.l / K)return a.l / K < b.l / K;
    return a.r < b.r;
}

bool cmp(zapros &a, zapros &b){
    return a.number < b.number;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    K = sqrt(n);
    while(K * K < n)K++;

    ll q;
    cin >> q;

    vector <ll> b(n + 1);

    for(int i = 1; i <= n; i++)cin >> b[i];

    vector <zapros> c(q);

    for(int i = 0; i < q; i++){
        cin >> c[i].l >> c[i].r;
        c[i].number = i;
    }

    ll l = 1, r = 0, ans = 0;

    sort(all(c), comp);

    for(int i = 0; i < q; i++){

        while(r < c[i].r){
            ll x = b[r + 1], old = x * a[x] * a[x];
            a[x]++;
            r++;
            ans += x * a[x] * a[x] - old;
        }

        while(r > c[i].r){
            ll x = b[r], old = x * a[x] * a[x];
            a[x]--;
            r--;
            ans += x * a[x] * a[x] - old;
        }

        while(l > c[i].l){
            ll x = b[l - 1], old = x * a[x] * a[x];
            a[x]++;
            l--;
            ans += x * a[x] * a[x] - old;
        }

        while(l < c[i].l){
            ll x = b[l], old = x * a[x] * a[x];
            a[x]--;
            l++;
            ans += x * a[x] * a[x] - old;
        }

        c[i].ans = ans;

    }

    sort(all(c), cmp);

    for(auto i : c)cout << i.ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}