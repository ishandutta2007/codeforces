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

vector <ll> c;

vector <ll> v[MAXN];

ll dist[MAXN], f[MAXN], k;

void find_cycle(ll x){
    if(f[x] == 2)return;
    if(f[x] == 1){
        if(sz(c) - dist[x] >= k){
            vector <ll> ans;
            while(!c.empty() && c.back() != x){
                ans.p_b(c.back());
                c.pop_back();
            }
            ans.p_b(x);
            cout << "2\n";
            cout << sz(ans) << "\n";
            for(auto i : ans)cout << i << " ";
            cout << "\n";
            exit(0);
        }
        return;
    }
    dist[x] = sz(c);
    c.p_b(x);
    f[x] = 1;
    for(auto to : v[x])find_cycle(to);
    f[x] = 2;
    c.pop_back();
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;
    k = sqrt(n);
    while(k * k > n)k--;
    while(k * k < n)k++;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    for(int i = 1; i <= n; i++)shuffle(all(v[i]), rnd);

    for(int i = 1; i <= n; i++)find_cycle(i);

    vector <pll> fufel;

    for(int i = 1; i <= n; i++)fufel.p_b({sz(v[i]), i});
    fill(f + 1, f + n + 1, 0);
    sort(all(fufel));

    vector <ll> ans;

    for(auto kek : fufel){
        ll i = kek.se;
        if(f[i])continue;
        if(sz(ans) < k)ans.p_b(i);
        f[i] = 1;
        for(auto j : v[i])f[j] = 1;
    }

    cout << "1\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";

    return 0;
}