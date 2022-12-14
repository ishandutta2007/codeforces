#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ll int
#define ple pair <ll, pll>

using namespace std;
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

vector <pll> v[MAXN];
vector <ll> va;
string s1,s2,s3;
set <ple> st;
set <ll> s;
char cc[MAXN];
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for(i = 1; i <= n; i++){
        cin >> s1;
        a[i] = s1.size();
    }
    sort(a + 1, a + n + 1);
    cin >> s1;
    m = s1.size();
    ll ans1 = 1e18, ans2 = 0;
    for(i = 1; i <= n; i++){
        sc++;
        if(a[i] == m)ans1 = min(ans1, sc), ans2 = max(ans2, sc);
        if(i % k == 0)sc += 5;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}