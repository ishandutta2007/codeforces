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

vector <ll> v[MAXN];

bool f[MAXN];

set <ll> s;

vector <ll> ans;

void add(ll x){
    ans.p_b(x);
    f[x] = 1;
    for(auto i : v[x])if(!f[i])s.insert(i);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("complexity.in","r",stdin);
    //freopen("complexity.out","w",stdout);

    ll n, m;
    cin >> n >> m;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);

    }

    add(1);

    while(!s.empty()){
        ll x = *s.begin();
        s.erase(s.begin());
        add(x);
    }

    for(auto i : ans)cout << i << " ";cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}