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
bool check(ll x){
    ll k = sqrt(x);
    while(sqr(k) < x)k++;
    while(sqr(k) > x)k--;
    if(sqr(k) == x)return 1;
    return 0;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> m;
    ll md = 1e18;
    for(i = 2; i <= 1e6; i++){
        k = i * i;
        while(1){
            if(md / k < i)break;
            k *= i;
            if(check(k))continue;
            s.insert(k);
        }
    }
    set <ll> :: iterator it = s.begin();
    for(; it != s.end(); ++it)va.p_b(*it);
    while(m--){
        ll l, r;
        cin >> l >> r;
        ll it1 = lower_bound(all(va), l) - va.begin();
        ll itt = upper_bound(all(va), r) - va.begin();
        ans = 0;
        ans = itt - it1;
        ll le = sqrt(l);
        while(le * le < l)le++;
        ll ri = sqrt(r);
        while(ri * ri < r)ri++;
        while(ri * ri > r)ri--;
        ans += ri - le + 1;
        cout << ans << "\n";
    }
    return 0;
}