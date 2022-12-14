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
ll ku[MAXN];
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
bool check(ll l, ll r){
    ll j;
    for(j = l; j <= r; j++)if(ku[j] && ku[j] < i)return 1;
    return 0;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for(i = 1; i <= n; i++){
        cin >> x;
        a[i] = x;
        v[x].p_b(i);
        if(!ku[x])ku[x] = i;
    }
    for(i = 1; i <= n; i++)if(!b[a[i]]){
        ll r = a[i], l = max(0ll, a[i] - k + 1);
        while(check(l, r))l++;
        r = min(255ll, l + k - 1);
        while(check(l, r))r--;
        for(j = l; j <= a[i]; j++)ku[j] = i;
        for(j = l; j <= r; j++)c[j] = l, b[j] = 1;

    }
    for(i = 1; i <= n; i++)cout << c[a[i]] << " " ;
    cout << endl;
    return 0;
}