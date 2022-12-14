#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
set <ll> s[MAXN];
ll n, m, k;
ll kol[MAXN];
ll ans;
bool fl[MAXN];
pll a[MAXN];

queue <ll> q;

void add(ll x){
    if(fl[x])return;
    ans--;
    fl[x] = 1;
    q.push(x);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    ans = n;
    vector <ll> res(m);
    for(int i = 0; i < m; i++){
        cin >> a[i].fi >> a[i].se;
        kol[a[i].fi]++;
        kol[a[i].se]++;
        s[a[i].fi].insert(a[i].se);
        s[a[i].se].insert(a[i].fi);
    }
    for(int i = 1; i <= n; i++)if(!fl[i] && kol[i] < k){
        add(i);
        while(!q.empty()){
            ll x = q.front();
            q.pop();
            for(auto i : s[x]){
                kol[i]--;
                if(kol[i] < k)add(i);
            }
        }
    }
    for(int i = m - 1; i >= 0; i--){
        res[i] = ans;
        if(!fl[a[i].fi] && !fl[a[i].se]){
            kol[a[i].fi]--;
            kol[a[i].se]--;
            s[a[i].fi].erase(a[i].se);
            s[a[i].se].erase(a[i].fi);
            if(kol[a[i].fi] < k)add(a[i].fi);
            if(kol[a[i].se] < k)add(a[i].se);
            while(!q.empty()){
            ll x = q.front();
            q.pop();
            for(auto i : s[x]){
                kol[i]--;
                if(kol[i] < k)add(i);
            }
        }
        }
    }
    for(auto i : res)cout << i << "\n";
    return 0;
}