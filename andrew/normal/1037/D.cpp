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


vector <ll> v[MAXN];
ll n, a[MAXN], pr[MAXN], l;

map <ll, bool> fl;

queue <ll> q;

void dfs(ll x, ll p){
    pr[x] = p;
    for(auto i : v[x])if(i != p)dfs(i, x);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ll m = n - 1;
    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }
    for(int i = 1; i <= n; i++)cin >> a[i];
    dfs(1, 0);
    q.push(1);
    if(a[1] != 1)vout("NO");
    l = 2;
    while(!q.empty()){
        ll x = q.front();
        q.pop();
        fl.clear();
        for(auto i : v[x])if(i != pr[x])fl[i] = 1;
        ll kol = fl.size();
        ll r = l + kol - 1;
        for(int i = l; i <= r; i++){
            if(!fl[a[i]])vout("NO");
            q.push(a[i]);
            fl[a[i]] = 0;
        }
        l = r + 1;
    }
    vout("YES");
    return 0;
}