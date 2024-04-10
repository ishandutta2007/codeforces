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

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}

vector <ll> v[MAXN];

ll ans = 0, n, m, a[MAXN];

void dfs(ll x, ll deep, ll pr = 0){
    if(a[x])deep++; else deep = 0;
    if(deep > m)return;

    bool fl = 0;

    for(auto to : v[x])if(to != pr){
        fl = 1;
        dfs(to, deep, x);
    }

    if(!fl)ans++;

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)cin >> a[i];

    ll m = n - 1;
    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1, 0ll);

    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}