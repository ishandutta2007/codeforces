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

//char sosat_akel[1001][1001];
unordered_map <string, ll> mp;
unordered_map <string, bool> f;

string res;
ll ans = 0;

void dfs(ll i, string &a){
    if(i == a.size()){
        if(!f[res])ans += mp[res];
        f[res] = 1;
        return;
    }
    if(a[i] != '?'){
        res += a[i];
        dfs(i + 1, a);
        res.erase(res.size() - 1);
    }else{
        dfs(i + 1, a);
        for(char c = 'a'; c <= 'e'; c++){
            res += c;
            dfs(i + 1, a);
            res.erase(res.size() - 1);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    ll n;
//    cin >> n;
//    string a;
//    cin >> a;
//    ll kek = 0, mx = 0;
//    for(int i = 0; i < n; i++){
//        if(a[i] == '[')kol++;
//        else kol--;
//        mx = max(mx, kol);
//    }
//    ll m = mx * 2 + 3;
//    for(int i = 0; i < n; i++){
//        c[]
//    }
    ll n, m;
    cin >> n >> m;
    while(n--){
        string a;
        cin >> a;
        mp[a]++;
    }
    while(m--){
        string a;
        ans = 0;
        cin >> a;
        f.clear();
        dfs(0, a);
        cout << ans << "\n";
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}