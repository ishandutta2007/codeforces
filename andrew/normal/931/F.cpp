#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
map <ll, ll> mp;
set <ll> s[MAXN];
char cc;
ll  a1, b1, c1, i, j, n, m, k, sc, x, ans;
ll p[MAXN], N;

void update(ll x, ll val){
    for(int i = x; i <= N; i += i & -i)p[i] = max(p[i], val);
}

ll get(ll x){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i)res = max(res, p[i]);
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> m >> n;
    N = m + 1;
    vector <ll> a(n + 5), b(n + 1);
    for(i = 1; i <= m; i++){
        cin >> a1 >> b1;
        a[a1]++;
        a[b1 + 1]--;
    }
    for(int i = 1; i <= n; i++){
        sc += a[i];
        b[i] = sc + 1;
    }
    vector <ll> c(n + 1);
    for(int i = 1; i <= n; i++){
        //cout << i << " " << b[i] << " " << N << endl;
        ll x = get(b[i]) + 1;
        c[i] = x;
        update(b[i], x);
    }
    //cout << 228 << endl;
    for(int i = 0; i <= N; i++)p[i] = 0;
    for(int i = n; i > 0; i--){
        ll x = get(b[i]);
        ans = max(ans, c[i] + x);
        update(b[i], x + 1);
    }
    cout << ans << "\n";
    return 0;
}