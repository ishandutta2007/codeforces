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
ll N;
void kek(ll tl, ll tr, ll a, ll b, ll gl){
    if(tl == tr)return;
    ll tm = (tl + tr) >> 1;
    kek(tl, tm, a, b, gl - 1);
    kek(tm + 1, tr, a, b, gl - 1);
    if(tl <=  a && b <= tr){
        if(tl == 1 && tr == N)vout("Final!");
        vout(gl);
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, a, b;
    cin >> n >> a >> b;
    if(a > b)swap(a, b);
    N = n;
    ll x = n, sc = 0;
    while(x){
        sc++;
        x >>= 1;
    }
    kek(1, n, a, b, sc - 1);
    return 0;
}