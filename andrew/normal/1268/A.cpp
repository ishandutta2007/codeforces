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
 
bool Cless(vector <ll> a, vector <ll> b){
    for(int i = 0; i < sz(a); i++){
        if(a[i] < b[i])return 1;
        if(a[i] > b[i])return 0;
    }
    return 1;
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
 
    ll n, k;
    cin >> n >> k;
 
    vector <ll> a(n + 1), b(n + 1);
 
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] = c - '0';
    }
 
    for(int i = 1; i <= n; i++){
        if(i <= k)b[i] = a[i];
        else b[i] = b[i - k];
    }
 
    if(Cless(a, b)){
        cout << n << "\n";
        for(int i = 1; i <= n; i++)cout << b[i];
        cout << "\n";
        return 0;
    }
 
    vector <ll> c;
    for(int i = k; i > 0; i--)c.p_b(b[i]);
    c.p_b(0);
    ll uk = 0;
    while(1){
        if(c[uk] == 9){
            c[uk] = 0;
            uk++;
        }else{
            c[uk]++;
            break;
        }
    }
 
    ll len = n;
 
    if(c.back() == 0)c.pop_back();
    else len++;
 
    reverse(all(c));
 
    cout << len << endl;
 
    for(int i = 1; i <= len; i++){
        ll uk = i;
        uk %= k;
        if(!uk)uk = k;
        cout << c[uk - 1];
    }
    cout << "\n";
 
 
    return 0;
}