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
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll dp[MAXN][3][3];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    b[1] = 1;
    b[2] = 1;
    if(n < 3)vout(0);
    ans = 1e18;
    for(i = 0; i < n; i++)cin >> a[i];
    for(ll i1 = -1; i1 < 2; i1++)
        for(ll j1 = -1; j1 < 2; j1++){

        for(i = 0; i < n; i++)b[i] = a[i];
        b[0] += i1;
        b[1] += j1;
        ll k = b[1] - b[0];
        ll sc = 0;
        for(i = 2; i < n; i++){
                bool fl = 0;
            for(j = -1; j < 2; j++)if(b[i] + j - k == b[i - 1]){fl = 1;break;}
            if(!fl){
                sc = 1e18;
                break;
            }
            b[i] += j;
        }
        for(i = 0; i < n; i++)if(b[i] != a[i])sc++;
        ans = min(ans, sc);
    }
    if(ans == 1e18)ans = -1;
    vout(ans);
    return 0;
}