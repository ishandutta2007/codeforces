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
ll a[MAXN],b[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll c[101][101];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n;
   cin >> s1;
   for(i = 1; i < n; i++){
        a1 = s1[i - 1] - 'A';
        b1 = s1[i] - 'A';
        c[a1][b1]++;
   }
   ll mx = -1e18, mxy, mxx;
   for(i = 0; i < 26; i++)
   for(j = 0; j < 26; j++)if(c[i][j] > mx){
    mx = c[i][j];
    mxx = i, mxy = j;
   }
   cout << char(mxx + 'A') << char(mxy + 'A') << endl;
    return 0;
}