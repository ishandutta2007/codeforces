#include <bits/stdc++.h>

#define fi first
#define map unordered_map
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
map <ll, vector <ll> > mp;
char cc;
pll a[MAXN];
ll ans[MAXN];
ll b[MAXN], c[MAXN],a1,b1,c1,i,j,n,m,k,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> x;
        s.insert(x);
        mp[x].p_b(i);
    }
    while(m--){
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
        c[a1]++;
        c[b1]++;
    }
    k = n;
    set <ll> :: iterator it = s.end();
    for(; it != s.begin(); ){
            --it;
        va = mp[*it];
        for(i = 0; i < va.size(); ++i){
            x = va[i];
            for(j = 0; j < v[x].size(); ++j)c[v[x][j]]--;
        }
        k -= va.size();
        for(i = 0; i < va.size(); ++i){
            x = va[i];
            ans[x] = k - c[x];
        }
    }
    for(i = 1; i <= n; i++)cout << ans[i] << " ";
    return 0;
}