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

vector <ll> va;
string s1,s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c[10000][5],f[MAXN],f1[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
vector <ll> v[5];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a1 >> b1 >> c1;
    c[0][0] = 1;
    for(i = 1; i <= 1000; i++)
        for(j = 0; j < 4; j++){
                if(j)c[i][j] = c[i - 1][j - 1];
                c[i][j] += c[i - 1][j];}
       for(j = 1;j < 4; j++)
    {
        for(i = 1; i < j; i++)c[i][j] = 0;
    }
    for(i = 0; i < a1; i++){
        cin >> x;
        a[x] = 1;
    }
    for(i = 0; i < b1; i++){
        cin >> x;
        a[x] = 2;
    }
     for(i = 0; i < c1; i++){
        cin >> x;
        a[x] = 3;
    }
    ll    l = 1, r = 1;
    while(r <= 100000){
        x = a[r];
        b[x]++;
        while(l <= r && l * 2 < r){
            b[a[l]]--;
            l++;
        }
        if(x){
                ll sc = 1;
            for(j = 1; j <= 3; j++){
                    if(j == x)sc *= c[b[j] - 1][j - 1];
                   else
                   sc *= c[b[j]][j];
            }
            ans += sc;
        }
        r++;
    }
    cout << ans << endl;
    return 0;
}