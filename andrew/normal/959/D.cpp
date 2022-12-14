#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
//#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 1e6;

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

vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s, ss;
char cc;
bool f[3 * MAXN];
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
bool fl = 0;
void go(ll x){
    ll j;
    j = x;
    while(j <= 2 * MAXN){
        s.erase(j);
        j += x;
    }
}
void check(ll x){
    for(j = 2; j * j <= x; j++)if(x % j == 0){
        if(s.find(j) != s.end())go(j);
       // cout << x << " " << j << endl;
        if(s.find(x / j) != s.end())go(x / j);
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 2; i <= 2 * MAXN; i++)s.insert(i);
    go(a[1]);
    check(a[1]);
    set <ll> :: iterator it, it1;
    for(i = 2; i <= n; i++){
        if(fl)it = s.begin(); else
        it = s.lower_bound(a[i]);
        x = *it;
        check(x);
        if(x != a[i])fl = 1;
        a[i] = x;
        go(x);
    }
    for(i = 1; i <= n; i++)cout << a[i] << " ";
    cout << endl;
    return 0;
}