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
ll c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    ll a, b;
    if(k + 1 <= n){
        cout << k + 1 << " " << 1 << endl;
        return 0;
    }
    k -= n - 1;
    ll l = 1, r = n;
    while(l < r){
        ll c = (l + r) / 2;
        a = (c - 1) * (m - 1) + 1;
        //cout << l << " " << r << " " << c << " " << a << endl;
        if(a > k)r = c; else l = c + 1;
    }
    a = (l - 1) * (m - 1) + 1;
    if(a > k)l--;
   // cout << (l - 1) * (m - 1) + 1 << " " << k << " " << l << endl;
    cout << n - l + 1 << " ";
    b = k - ((l - 1) * (m - 1) + 1);
    if(l % 2 == 1){
        cout << 2 + b;
    }else cout << m - b;
    cout << endl;
    return 0;
}