#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5 + 5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll mod;

bool bad(ll x){
    for(int i = 2; i * i <= x; i++)if(x % i == 0)return 1;
    return 0;
}

ll st[N], ob[N];

ll mul(ll a, ll b){
    return (a * b) % mod;
}

ll add(ll a, ll b){
    return (a + b >= mod ? a + b - mod : a + b);
}

void u(ll &a, ll b){
    a = mul(a, b);
}

ll bp(ll a, ll n){
    ll res = 1;
    while(n){
        if(n & 1)u(res, a);
        u(a, a);
        n >>= 1;
    }
    return res;
}

ll pref[MAXN];

ll get(ll l, ll r){
    ll val = pref[r] - pref[l - 1];
    if(val < 0)val += mod;
    val = mul(val, ob[l]);
    return val;
}

ll kolL[MAXN], kolR[MAXN];

string Rev(string s){
    reverse(all(s));
    return s;
}

struct node{
    ll kol;
    node *p[26];
    node(): kol(0) {
        for(int i = 0; i < 26; i++)p[i] = nullptr;
    }
};

node *root = new node(), *root1 = new node();

void addB(string s, node *T){
    node *q = T;
    for(auto i : s){
        if(q -> p[i - 'a'] == nullptr){
            q -> p[i - 'a'] = new node();
        }
        q = q -> p[i - 'a'];
    }
    q -> kol++;
}

ll f(string s, node *T){
    node *q = T;
    ll ans = 0;
    for(auto i : s){
        if(q -> p[i - 'a'] == nullptr)break;
        ans += q -> kol;
        q = q -> p[i - 'a'];
    }
    ans += q -> kol;
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    mod = rnd() % 100 + 1e9;
    while(bad(mod))mod++;
    string t;
    cin >> t;
    ll n = t.size();
    ll m;
    cin >> m;
    vector <string> s(m);

    st[0] = 1;
    ob[0] = 1;

    for(int i = 1; i < N; i++){
        st[i] = mul(st[i - 1], 31);
        ob[i] = bp(st[i], mod - 2);
    }

    for(int i = 0; i < m; i++)cin >> s[i];

    for(int i = 1; i <= n; i++){
        pref[i] = add(pref[i - 1], mul(st[i], t[i - 1] - 'a' + 1));
    }

    ll k = sqrt(2e5);
    while(sqr(k) < 2e5)k++;

    for(auto i : s)if(i.size() >= k){
        ll Hash = 0;
        for(int j = 1; j <= i.size(); j++){
            Hash = add(Hash, mul(st[j - 1], i[j - 1] - 'a' + 1));
        }
        for(int j = 1; j <= n - i.size() + 1; j++)if(get(j, j + i.size() - 1) == Hash){
            kolR[j]++;
            kolL[j + i.size() - 1]++;
        }
    }

    for(auto i : s)if(i.size() < k){
        addB(i, root);
        addB(Rev(i), root1);
    }

    for(int i = 1; i < n; i++){
        string S;
        for(int j = i; j > 0; j--){
            S += t[j - 1];
            if(S.size() + 1 == k)break;
        }
        kolL[i] += f(S, root1);
        S.clear();
    }

    for(int i = 2; i <= n; i++){
        string S;
        for(int j = i; j <= n; j++){
            S += t[j - 1];
            if(S.size() + 1 == k)break;
        }
        kolR[i] += f(S, root);
        S.clear();
    }

    ll ans = 0;

    for(int i = 1; i < n; i++)ans += kolL[i] * kolR[i + 1];

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}