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
ll sc1;
ll a[MAXN],b,c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll d;
ll p[MAXN];
bool check(ll x){
    for(i = 1; i <= n; i++)a[i] = p[i];
    ll le = 1 + x, ri = n - x;
    ll l1 = 1, r1 = n, time = x + 1;
    while(le < ri){
        sc = b;
        while(sc && l1 <= n){
            if(abs(le - l1) > time * d)return 0;
            ll kol = min(sc, a[l1]);
            sc -= kol;
            a[l1] -= kol;
            if(a[l1] == 0)l1++;
        }
        //if(x == 0)cout << le << " " << ri << endl;
        if(sc)return 0;
        sc = b;
        while(sc && r1 > 0){
            if(abs(ri - r1) > time * d)return 0;
            ll kol = min(sc, a[r1]);
            sc -= kol;
            a[r1] -= kol;
            if(!a[r1])r1--;
        }
        if(sc)return 0;
        le++, ri--;
        time++;
    }
    if(le == ri){
        sc = b;
        while(sc && l1 <= n){
            if(abs(le - l1) > time * d)return 0;
            ll kol = min(sc, a[l1]);
            sc -= kol;
            a[l1] -= kol;
            if(a[l1] == 0)l1++;
        }
        if(sc)return 0;
    }
    return 1;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> d >> b;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 1; i <= n; i++)p[i] = a[i];
    ll l = 0, r = n / 2;
    while(l < r){
        ll c = (l + r) / 2;
        //cout << l << " " << r << " " << c << endl;
        if(check(c))r = c; else l = c + 1;
    }
    //cout << check(1) << endl;
    vout(l);
    return 0;
}