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
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    k = 1;
    for(i = 1; i <= m; i++){
        cin >> x;
        if(b[k] > x){
            b[k] -= x;
            cout << n - k + 1 << endl;
            continue;
        }
        ll l = 1, r = n;
        while(l < r){
            ll c = (l + r) / 2;
            sc = get(k + 1, c) + b[k];
            if(sc > x)r = c; else l = c + 1;
        }
        sc = get(k + 1, l) + b[k];
        if(sc <= x)l++;
        ll ku = get(k + 1, l - 1) + b[k];
        b[k] = a[k];
        if(l == n + 1){
            k = 1;
        }else{
            k = l;
            b[k] -= x - ku;
        }
        cout << n - k + 1 << endl;
    }
    return 0;
}