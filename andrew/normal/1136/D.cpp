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

vector <ll> v[MAXN], v1[MAXN];

ll p[MAXN], pz[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)cin >> p[i];
    for(int i = 1; i <= n; i++)pz[p[i]] = i;


    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v1[b].p_b(a);
    }

    set <ll> s;

    for(auto i : v1[p[n]])s.insert(pz[i]);



    while(!s.empty()){
        ll pos = *(--s.end()), arr = p[pos];
        s.erase(--s.end());
        vector <ll> d;

        for(auto i : v[arr])if(i != p[n])d.p_b(pz[i]);

        sort(all(d));

        for(auto i : d){
            ll x = i;
            if(x - 1 == pos){
                swap(pz[p[x]], pz[p[x - 1]]);
                swap(p[x], p[x - 1]);
                if(s.find(x) != s.end()){
                    s.erase(x);
                    s.insert(x - 1);
                }
                pos++;
            }
        }
    }
    ll pos = n, arr = p[pos];
    vector <ll> d;

    for(auto i : v1[arr])d.p_b(pz[i]);

    sort(all(d));
    reverse(all(d));

    ll ans = 0;

    for(auto i : d){
        ll x = i;
        if(x + 1 == pos){
            pos--;
            ans++;
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}