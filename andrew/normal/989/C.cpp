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
set <ll> s[MAXN];
char cc;
ll a,b,d,c,a1,b1,c1,i,j,n,m,k,sc,x;
char ans[101][101];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a >> b >> c >> d;
    n = m = 50;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)ans[i][j] = 'A';
    a--;
    for(i = 40; i <= 50; i++)for(j = 1; j <= m; j++)ans[i][j] = 'B';
    b--;
    ll k = 41, j = 2;
    while(a--){
        j += 2;
        if(j > m){
            j = 2;
            k += 2;
        }
        ans[k][j] = 'A';
    }
    for(i = 3; i <= n; i++)for(j = 1; j <= m; j++){
        if(j % 2 == 0 && i % 2 == 1 && b)ans[i][j] = 'B', b--;else
        if(j % 2 == 0 && i % 2 == 1 && c)ans[i][j] = 'C',c--;else
        if(j % 2 == 0 && i % 2 == 1 && d)ans[i][j] = 'D',d--;
    }
    cout << n << " " << m << endl;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++)cout << ans[i][j]; cout << endl;}
    return 0;
}