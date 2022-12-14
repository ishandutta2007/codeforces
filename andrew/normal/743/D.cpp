#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define ull unsigned long long

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

const ll MOD = 1e9 + 7;

ll f(ll &a, ll b){
    a = (a + b) % MOD;
    return a;
}

vector <ll> v[MAXN];
ll a[MAXN], ans = -1e18, res[MAXN], sum[MAXN];

void dfs(ll x, ll pr = 0){
    multiset <ll> s;
    for(auto i : v[x])if(i != pr){
        dfs(i, x);
        s.insert(res[i]);
        sum[x] += sum[i];
    }
    if(s.empty()){
        res[x] = a[x];
        sum[x] = a[x];
        return;
    }
    if(s.size() > 1){
        multiset <ll> :: iterator it, it1;
        it = it1 = s.end();
        --it;

        --it1;
        --it1;
        ans = max(ans, *it + *it1);
    }
    sum[x] += a[x];
    res[x] = max(sum[x], *(--s.end()));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    ll m = n - 1;
    for(int i = 1; i <= n; i++)cin >> a[i];
    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }
    dfs(1);
    if(ans == -1e18)vout("Impossible");
    vout(ans);
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}