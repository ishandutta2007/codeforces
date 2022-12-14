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
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s1;
    n  = s1.size();
    for(i = 1; i <= n; i++){
        cc = s1[i - 1];
        ll a1 = 0;
        if(cc == 'A')a1 = 1;
        if(cc == 'B')a1 = 2;
        if(cc == 'C')a1 = 3;
        if(a1 == 0)continue;
        s[i - 1].insert(a1);
        s[i].insert(a1);
        s[i + 1].insert(a1);
    }
    for(i = 1; i <= n; i++)if(s[i].size() == 3)vout("Yes");
    vout("No");
    return 0;
}