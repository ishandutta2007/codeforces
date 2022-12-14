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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int tin[MAXN], tout[MAXN], deep[MAXN], stn, p[MAXN];
vector <int> v[MAXN];

bool cmp(int a, int b){
    return (m_p(deep[a], a) > m_p(deep[b], b));
}

void dfs(int x, int pr = 0){
    p[x] = pr;
    deep[x] = deep[pr] + 1;
    tin[x] = ++stn;
    for(int to : v[x])if(to != pr)dfs(to, x);
    tout[x] = stn;
}

bool is_less(int a, int b){
    return tin[b] <= tin[a] && tout[a] <= tout[b];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    tout[0] = 1e9;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int n, m;

    cin >> n >> m;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1);

    while(m--){
        int k;
        cin >> k;
        vector <int> a(k);
        for(auto &i : a)cin >> i;
        sort(all(a), cmp);
        int temp = a[0];
        string ans = "YES";
        pii fufel = {-1, -1};

        for(int i = 1; i < k; i++){
            if(deep[a[i]] != fufel.fi && fufel.fi != -1){
                temp = fufel.se;
                fufel = {-1, -1};
            }
            if(is_less(temp, a[i])){
                fufel = {deep[a[i]], a[i]};
            }
            if(!is_less(temp, p[a[i]]))ans = "NO";
        }
        cout << ans << "\n";
    }

    return 0;
}