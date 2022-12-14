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

ll col[MAXN], p[MAXN], x;

vector <ll> c[MAXN];

ll get(ll x){
    if(p[x] == x)return x;
    return get(p[x]);
}

void unite(ll a, ll b){
    if(c[a].size() > c[b].size()){
        for(auto j : c[b])c[a].p_b(j);
        c[b].clear();
        p[b] = a;
    }else{
        for(auto j : c[a])c[b].p_b(j);
        c[a].clear();
        p[a] = b;
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        c[i].p_b(i);
        p[i] = i;
    }

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        ll ra = get(a), rb = get(b);

        unite(ra, rb);

    }

    ll x = get(1);

    for(auto i : c[x])cout << i << " ";
    cout << "\n";




    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}