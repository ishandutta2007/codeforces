#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define next ku
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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    set <ll> clr;
    ll n, m, k;
    cin >> n >> m;
    vector <ll> mp(m);
    vector <ll> v[m];
    vector <ll> a(n);
    k = n / m;
    for(int i = 0; i < n; i++){
                             ll x;
                             cin >> x;
                             a[i] = x;
                             x %= m;
                             mp[x]++;
                             v[x].p_b(i);
    }
    for(int i = 0; i < m; i++)if(mp[i] < k)clr.insert(i);
    ll ans = 0;
    for(int i = m - 1; i >= 0; i--)while(mp[i] > k){
                             mp[i]--;
                             set <ll> :: iterator it = clr.upper_bound(i);
                             if(it == clr.end())it = clr.begin();
                             ll kol = 0;
                             if(*it > i)kol += *it - i; else kol += *it + m - i;
                             ans += kol;
                             a[v[i].back()] += kol;
                             v[i].pop_back();
                             mp[*it]++;
                             if(mp[*it] == k)clr.erase(it);
    }
    cout << ans << "\n";
    for(int i = 0; i < n; i++)cout << a[i] << " ";
    return cout << "\n", 0;
 }