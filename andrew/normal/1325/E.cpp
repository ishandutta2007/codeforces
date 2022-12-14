#include <bits/stdc++.h>

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
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) { cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool f[MAXN];
ll zp[MAXN];

vector <ll> v[MAXN];
map <ll, ll> dp_m[MAXN];
ll zapros;

ll sc[MAXN], tp[MAXN];
ll last[MAXN];

ll dp[MAXN], pr[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    last[1] = 1;


    for(int i = 2; i <= N; i++)if(!last[i]){
        last[i] = i;
        if(ll(i) * ll(i) <= N)for(int j = i * i; j <= N; j += i)last[j] = i;
    }


    ll n;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];
    map <set <ll>, ll> mp;

    for(int i = 1; i <= n; i++){
        ll x = sqrt(a[i]);
        while(x * x < a[i])x++;
        while(x * x > a[i])x--;
        if(sqr(x) == a[i])vout(1);
        map <ll, ll> p;
        x = a[i];
        while(x != 1){
            p[last[x]]++;
            x /= last[x];
        }
        set <ll> s;
        for(auto i : p){
            if(i.se % 2)s.insert(i.fi);
        }
        mp[s]++;
    }

    for(auto i : mp)if(i.se > 1)vout(2);

    for(auto i : mp){
        if(sz(i.fi) == 1){
            f[*i.fi.begin()] = 1;
            v[1].p_b(*i.fi.begin());
            v[*i.fi.begin()].p_b(1);
        }
        else{
            v[*i.fi.begin()].p_b(*(++i.fi.begin()));
            v[*(++i.fi.begin())].p_b(*i.fi.begin());
        }
    }

    ll ans = inf;

    for(int i = 1; i <= 1000; i++){
        zapros++;
        queue <ll> q;
        pr[i] = 0;
        q.push(i);
        dp[i] = 0;
        tp[i] = zapros;
        while(!q.empty()){
            ll x = q.front();
            q.pop();
            for(auto to : v[x])if(to != pr[x]){
                if(tp[to] == zapros){
                    ans = min(dp[to] + dp[x] + 1, ans);
                }
                else {
                    tp[to] = zapros;
                    dp[to] = dp[x] + 1;
                    pr[to] = x;
                    q.push(to);
                }
            }
        }
    }

    if(ans == inf)ans = -1;
    vout(ans);

    return 0;
}