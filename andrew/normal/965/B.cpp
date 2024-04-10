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
char cc[101][101];
ll a[1001][1001];
ll b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; j++)cin >> cc[i][j];
    for(i = 1; i <= n; i++){
            sc = 0;
        for(j = 1; j <= k; j++)if(cc[i][j] == '#')sc++;
        ll l = 1, r = k;
        while(r <= n){
            if(!sc)for(j = l; j <= r; j++)a[i][j]++;
            if(cc[i][l] == '#')sc--;
            if(r == n)break;
            l++;
            r++;
            if(cc[i][r] == '#')sc++;
        }
    }

    for(j = 1; j <= n; j++){
           sc = 0;
        for(i = 1; i <= k; i++)if(cc[i][j] == '#')sc++;
        ll l = 1, r = k;
        while(r <= n){
            if(!sc && k > 1)for(i = l; i <= r; i++)a[i][j]++;
            if(cc[l][j] == '#')sc--;
            if(r == n)break;
            l++;
            r++;
            if(cc[r][j] == '#')sc++;
        }

    }

    ll mx = -1;
    for(i = 1; i <= n; i++)for(j = 1; j <= n; j++)mx = max(mx, a[i][j]);
    for(i = 1; i <= n; i++)for(j = 1; j <= n; j++)if(a[i][j] == mx){
        cout << i << " " << j << endl;
        return 0;
    }
    return 0;
}