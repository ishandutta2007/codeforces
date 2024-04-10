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
const ll MAXN = 1000001;

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

const ll MOD = 1e9;

map<int,int> mp[MAXN];
int n, k;
vector <int> v[MAXN];
int a[MAXN], ans[MAXN], p[MAXN], deep[MAXN];
int stn = 1;
map <int,int> :: iterator it;
void dfs(int x, int gl, int pr){
    deep[x] = gl;
    ans[x] = gl;
    bool fl = 0;
    int mxj = 0, nn = v[x].size();
    for(int i = 0; i < nn; i++)if(v[x][i] != pr){
        fl = 1;
        dfs(v[x][i], gl + 1, x);
        if(mp[p[v[x][i]]].size() >= mp[p[v[x][mxj]]].size())mxj = i;
    }
    if(!fl){
        p[x] = stn++;
        mp[p[x]][gl]++;
        ans[x] = deep[x];
        return;
    }
    ans[x] = ans[v[x][mxj]];
    p[x] = p[v[x][mxj]];
    int val = mp[p[x]][ans[x]];
    for(int i = 0; i < nn; i++)if(v[x][i] != pr){
        if(i == mxj)continue;
        int xe = v[x][i];
        it = mp[p[xe]].begin();
        for(; it != mp[p[xe]].end(); ++it){
            int val1 = it -> fi;
            mp[p[x]][val1] += it -> se;
            if(mp[p[x]][val1] >= val){
                if(mp[p[x]][val1] > val)ans[x] = val1; else
                ans[x] = min(ans[x], val1);
                val = mp[p[x]][val1];
            }
        }
        mp[p[xe]].clear();
    }
    mp[p[x]][gl]++;
    if(mp[p[x]][gl] >= val)ans[x] = gl;

}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int m = n - 1;
    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }
    dfs(1, 1, 0);
    for(int i = 1; i <= n; i++)cout << ans[i] - deep[i] << "\n";
    return 0;
}