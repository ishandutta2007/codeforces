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
string s1,s2[100001],s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
map <string , ll > mp;
map <string , ll > mp1;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k >> m;
    for(i = 1; i <= n; i++){
        cin >> s2[i];
        mp1[s2[i]] = i;
    }
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 1; i <= k; i++){
        b[i] = 1e18;
        cin >> x;
        while(x--){
            cin >> sc;
            s1 = s2[sc];
            mp[s1] = i;
            b[i] = min(b[i], a[mp1[s1]]);
        }
    }
    b[0] = 1e18;
    while(m--){
        cin >> s1;
        ans += min(b[mp[s1]], a[mp1[s1]]);
    }
    cout << ans << endl;
    return 0;
}