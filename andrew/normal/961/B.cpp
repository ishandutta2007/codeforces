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

vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll pref[MAXN];
ll get(ll l, ll r){
    return b[r] - b[l - 1];
}
ll get1(ll l, ll r){
    return pref[r] - pref[l - 1];
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 1; i <= n; i++){
        cin >> x;
        b[i] = b[i - 1];
        if(x == 1)b[i] += a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for(i = 1; i <= n - k + 1; i++)ans = max(ans, b[n] - get(i, i + k - 1) + get1(i, i + k - 1));
    vout(ans);
    return 0;
}