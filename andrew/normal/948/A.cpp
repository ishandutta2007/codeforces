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
string s1[MAXN],s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
void add(ll y, ll x){
    if(y < 0 or y >= n or x < 0 or x >= m or s1[y][x] == 'S')return;
    if(s1[y][x] == 'W')vout("No");
    s1[y][x] = 'D';
    return;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i = 0; i < n; i++)cin >> s1[i];
    for(i = 0; i < n; i++)for(j = 0; j < m; j++)if(s1[i][j] == 'S'){
        add(i + 1, j);
        add(i - 1, j);
        add(i, j + 1);
        add(i, j - 1);
    }
    cout << "Yes" << endl;
    for(i = 0; i < n; i++)cout << s1[i] << endl;
    return 0;
}