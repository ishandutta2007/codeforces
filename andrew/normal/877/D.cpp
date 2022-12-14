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
char cc;
ll c,a1,b1,c1,i,j,n,m,k,sc,x;
set <ll> stolb[1001], stroka[1001];
queue <pll> q;
ll f[MAXN];
ll b[1001][1001];
ll a[1001][1001];
ll prefstl[1001][1001];
ll prefstr[1001][1001];
ll getstr(ll i, ll l, ll r){
    return prefstr[i][r]  - prefstr[i][l - 1];
}
ll getstl(ll j, ll l, ll r){
    return prefstl[r][j] - prefstl[l - 1][j];
}
void add(ll y, ll x, ll pp){
    b[y][x] = pp + 1;
    stolb[x].erase(y);
    stroka[y].erase(x);
    q.push({y,x});
}
void addst(ll y, ll x, ll pp){
    set <ll> :: iterator it = stroka[y].lower_bound(x);
    ll r = x + k;
    while(!stroka[y].empty() && it != stroka[y].end() && *it <= r){
        ll xe = *it;
        if(getstr(y, x, xe))break;
        add(y, xe, pp);
        it = stroka[y].lower_bound(x);
        //cout << y << " " << x << " " << xe << " " << l << endl;
    }
    it = stroka[y].lower_bound(x);
    ll l = x - k;
    while(!stroka[y].empty()){
        if(it == stroka[y].begin())break;
        --it;
        ll xe = *it;
        if(xe < l)break;
        if(getstr(y, xe, x))break;
        add(y, xe, pp);
        it = stroka[y].lower_bound(x);
    }
}
void adde(ll y, ll x, ll pp){
    set <ll> :: iterator it = stolb[x].lower_bound(y);
    ll r = y + k;
    while(!stolb[x].empty() && it != stolb[x].end() && *it <= r){
        ll xe = *it;
        if(getstl(x, y, xe))break;
        add(xe, x, pp);
        it = stolb[x].lower_bound(y);
    }
    it = stolb[x].lower_bound(y);
    ll l = y - k;
    while(!stolb[x].empty()){
        if(it == stolb[x].begin())break;
        --it;
        ll xe = *it;
        if(xe < l)break;
        if(getstl(x, xe, y))break;
        add(xe, x, pp);
        it = stolb[x].lower_bound(y);
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            a[i][j] = 1;
            cin >> cc;
            if(cc == '.'){
                a[i][j] = 0;
                stolb[j].insert(i);
                stroka[i].insert(j);
            }
            prefstr[i][j] = prefstr[i][j - 1] + a[i][j];
            prefstl[i][j] = prefstl[i - 1][j] + a[i][j];
        }
    }
    ll x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;
    if(x == x1 && y == y1)vout(0);
    add(x, y, -1);
    while(!q.empty()){
        pll xe = q.front();
        q.pop();
        x = xe.fi, y = xe.se;
        addst(x, y, b[x][y]);
        adde(x, y, b[x][y]);
    }
    if(!b[x1][y1])vout(-1);
    vout(b[x1][y1]);
    return 0;
}