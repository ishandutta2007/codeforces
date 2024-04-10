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

bool fl[MAXN];
ll n;
vector <ll> v[MAXN], a;

void dfs(ll x){
    if(fl[x])return;
    fl[x] = 1;
    a.p_b(x);
    if(x == n){
        for(auto i : a)cout << i << " ";
        exit(0);
    }
    for(auto i : v[x])dfs(i);
    a.pop_back();
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(int i = 2; i <= n; i++){
        ll x;
        cin >> x;
        v[x].p_b(i);
    }
    dfs(1ll);
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}