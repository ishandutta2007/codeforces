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
char cc;
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;

void update(ll x){
    for(int i = x; i <= n; i += i & -i)a[i]++;
}

ll get(ll x){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i)res += a[i];
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> x;
        update(x);
        ans += get(n) - get(x);
    }
    if((n + ans + 1) % 2)vout("Petr");
    vout("Um_nik");
    return 0;
}