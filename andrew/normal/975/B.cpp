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
set <vector<ll>> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll pref[MAXN];
ll get(ll l, ll r){
    return pref[r] - pref[l - 1];
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    n = 14;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 1; i <= n; i++)b[i] = a[i];
    for(ll mxj = 1; mxj <= n; mxj++)if(b[mxj] > 0){
        for(i = 1; i <= n; i++)a[i] = b[i];
        k = a[mxj];
        for(j = mxj + 1; j <= n; j++){
            if(k == 0)break;
            k--;
            a[j]++;
        }
        a[mxj] = 0;
        ll sc = k / n;
        for(j = 1; j <= n; j++)a[j] += sc;
        ll ku = k % n;
        for(j = 1; j <= ku; j++)a[j]++;
    ll pod = 0;
        for(j = 1; j <= n; j++)if(a[j] % 2 == 0){
            pod += a[j];
            a[j] = 0;
        }
        ans = max(ans, pod);
    }
    vout(ans);
    return 0;
}