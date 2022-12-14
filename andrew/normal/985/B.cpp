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
map <ll, ll> mp;
set <ll> s;
char cc;
ll a[2001][2001];
ll b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin >> cc;
            a[i][j] = cc - '0';
            b[j] += a[i][j];
        }
    }
    for(i = 1; i <= n; i++){
        bool fl = 0;
        for(j = 1; j <= m; j++)if(a[i][j] && b[j] == 1)fl = 1;
        if(!fl)vout("YES");
    }
    vout("NO");
    return 0;
}