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

bool fl[1001];
bool rb[1001][1001];
ll r[1001];
ll pod[1001];
vector <ll> v[MAXN];
ll kol;

void dfs(ll x){
    if(fl[x])return;
    fl[x] = kol;
    r[kol] = max(r[kol], x);
    for(auto i : v[x])if(!rb[x][i])dfs(i);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n;
    m = n - 1;
    vector <pll> a(m + 1);
    set <ll> s;
    for(int i = 1; i <= n; i++)s.insert(i);
    for(int i = 1; i <= m; i++){
        cin >> a[i].fi >> a[i].se;
        s.erase(a[i].fi);
        s.erase(a[i].se);
    }
//    if(s.empty()){
//        for(int i = 1; i <= m; i++){
//            ll ra = a[i].fi, rb = a[i].se;
//            v[ra].p_b(rb);
//            v[rb].p_b(ra);
//        }
//        for(int i = 1; i <= m; i++){
//            for(int j = 1; j <= n; j++)fl[j] = 0;
//            rb[a[i].fi][a[i].se] = 1;
//            rb[a[i].se][a[i].fi] = 1;
//            r[1] = r[2] = 0;
//            kol = 0;
//            for(int j = 1; j <= n; j++)if(!fl[j]){
//                kol++;
//                dfs(j);
//            }
//            rb[a[i].fi][a[i].se] = 0;
//            rb[a[i].se][a[i].fi] = 0;
//            if(min(r[1], r[2]) != min(a[i].fi, a[i].se) || max(r[1], r[2]) != max(a[i].fi, a[i].se))vout("NO\n");
//        }
//        cout << "YES\n";
//        for(auto j : a)cout << j.fi << " " << j.se << "\n";
//        return 0;
//    }
    if(s.find(n) != s.end())vout("NO");
    for(int i = 1; i <= m; i++)if(max(a[i].fi, a[i].se) != n || a[i].fi == a[i].se)vout("NO");
    for(int i = 1; i <= m; i++)pod[min(a[i].fi, a[i].se)]++;
    vector <pll> ans;
    for(int i = 1; i <= n; i++)if(pod[i]){
        ll cont = pod[i];
        ll last = n;
        set <ll> :: iterator it;
        for(int j = 1; j < pod[i]; j++){
            if(s.empty())vout("NO");
            ans.p_b({last, *s.begin()});
            if(*s.begin() > i)vout("NO");
            last = *s.begin();
            s.erase(s.begin());
        }
        ans.p_b({last, i});
    }
    cout << "YES\n";
    for(auto i : ans)cout << i.fi << " " << i.se << "\n";
    return 0;
}