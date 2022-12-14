#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

vector <int> v[MAXN];
ll ans[MAXN];
int c[MAXN], mx[MAXN], p[MAXN];
map < int, int > mp[MAXN];
map < int, int > :: iterator it;
ll n;
ll q1 = 1;

void dfs(ll x, ll pr){
    ll i, nn = v[x].size();
    if(v[x].size() == 0 || v[x].size() == 1 && pr){
        ans[x] = c[x];
        p[x] = q1++;
        mp[p[x]][c[x]]++;
        mx[p[x]] = 1;
        return;
    }
    ll mxj = 0;
    for(int i = 0; i < nn; i++)if(v[x][i] != pr){
        dfs(v[x][i], x);
        if(mp[p[v[x][mxj]]].size() <= mp[p[v[x][i]]].size())mxj = i;
    }
    ll to = v[x][mxj];
    ans[x] = ans[to];
    p[x] = p[to];
    for(int i = 0; i < nn; i++)if(v[x][i] != pr && i != mxj){
        ll xe = p[v[x][i]];
        it = mp[xe].begin();
        for(; it != mp[xe].end(); ++it){
            mp[p[x]][it -> fi] += it -> se;
            if(mp[p[x]][it -> fi] > mx[p[x]]){
                mx[p[x]] = mp[p[x]][it -> fi];
                ans[x] = 0;
            }
            if(mp[p[x]][it -> fi] == mx[p[x]])ans[x] += it -> fi;

        }
        mp[xe].clear();
    }
    mp[p[x]][c[x]]++;
    if(mp[p[x]][c[x]] > mx[p[x]]){
        mx[p[x]] = mp[p[x]][c[x]];
        ans[x] = 0;
    }
    if(mp[p[x]][c[x]] == mx[p[x]])ans[x] += c[x];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> c[i];
    ll m = n - 1;
    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }
    dfs(1ll, 0ll);
    for(int i = 1; i <= n; i++)cout << ans[i] << "\n";
    return 0;
}