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
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;

void dfs(ll x, ll pr){
    ll i, nn = v[x].size();
    bool fl = 0;
    for(i = 0; i < nn; ++i)if(v[x][i] != pr){
        fl = 1;
        dfs(v[x][i], x);
    }
    if(!fl)va.p_b(x);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    m = n - 1;
    while(m--){
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
        a[a1]++;
        a[b1]++;
    }
    ll sc = 0, mxj = 0;
    for(i = 1; i <= n; i++)if(a[i] > 2){
        mxj = i;
        sc++;
        if(sc > 1)vout("No");
    }
    if(sc == 0)mxj = 1;
    cout << "Yes\n";
    dfs(mxj, 0);
    cout << va.size() << endl;
    for(i = 0; i < va.size(); ++i)cout << mxj << " " << va[i] << endl;
    return 0;
}