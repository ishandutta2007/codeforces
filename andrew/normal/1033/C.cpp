#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

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
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
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
ll what[MAXN];
vector <char> res;

void dfs(ll x){
    bool fl = 0;
    if(f[x])return;
    f[x] = 1;
    for(auto i : v[x]){
        dfs(i);
        fl = 1;
        if(what[i] == 1)what[x] = 2;
    }
    if(!what[x])what[x] = 1;
    if(what[x] == 2)res[x] = 'A'; else res[x] = 'B';
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <pll> b(n);
    res.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i].fi = a[i];
        b[i].se = i;
    }
    sort(all(b));
    reverse(all(b));
    for(int i = 0; i < n; i++){
        ll x = b[i].se;
        for(int j = 1; j <= n; j++)if(x + a[x] * j < n){
            if(a[x + a[x] * j] > a[x]){
                v[x].p_b(x + a[x] * j);
            }

        }else break;

        for(int j = 1; j <= n; j++)if(x - a[x] * j >= 0){
            if(a[x - a[x] * j] > a[x]){
                v[x].p_b(x - a[x] * j);
            }

        }else break;
    }
    for(int i = n - 1; i >= 0; i--)if(!f[b[i].se]){
            ll x = b[i].se;
            dfs(x);
    }
    for(auto i : res)cout << i;
    cout << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}