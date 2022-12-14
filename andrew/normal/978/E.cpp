#include <bits/stdc++.h>

#define fi first
#define map unordered_map
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
ll a[MAXN],b[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    ll l = 0, r = m;
    for(i = 0; i < n; i++)cin >> a[i];
    while(l < r){
        ll c = (l + r) >> 1;
        x = c;
        bool fl = 0;
        for(i = 0; i < n; i++){
            x += a[i];
            if(x > m){
                r = c - 1;
                fl = 1;
                break;
            }
            if(x < 0){
                l = c + 1;
                fl = 1;
                break;
            }
        }
        if(!fl){
            r = c;
        }
    }
    ll l1 = l;
    l = 0, r = m;
    while(l < r){
         ll c = (l + r) >> 1;
        x = c;
        bool fl = 0;
        for(i = 0; i < n; i++){
            x += a[i];
            if(x > m){
                r = c - 1;
                fl = 1;
                break;
            }
            if(x < 0){
                l = c + 1;
                fl = 1;
                break;
            }
        }
        if(!fl)l = c + 1;
    }
    bool fl = 0;
    x = l;
    for(i = 0; i < n; i++){
        x += a[i];
        if(x > m || x < 0)fl = 1;
    }
    if(fl)l--;
    vout(max(l - l1 + 1, 0ll));
    return 0;
}