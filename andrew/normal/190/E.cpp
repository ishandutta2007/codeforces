#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ll int

using namespace std;
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

vector <ll> v[MAXN],va[MAXN];
string s1,s2,s3;
set <ll> s;
char cc;
set <ll> :: iterator it;
ll r,a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
void dfs(ll x){
    s.erase(x);
    b[x] = r;
    va[r].p_b(x);
    ll i,nn = v[x].size();
    for(i = 1; i < nn; i++){
        ll l = v[x][i - 1] + 1,r = v[x][i] - 1;
        it = s.lower_bound(l);
        while(it!=s.end() && *it <= r){
            dfs(*it);
            it = s.lower_bound(l);
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    while(m--){
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
    }
    for(i = 1; i <= n; i++){
        v[i].p_b(0);
        v[i].p_b(n + 1);
        sort(all(v[i]));
        s.insert(i);
    }
    for(i = 1; i <= n; i++)if(!b[i]){
        r++;
        dfs(i);
    }
    cout << r << endl;
    for(i = 1; i <= r; i++){
        cout << va[i].size();
        sort(all(va[i]));
        for(j = 0 ; j < va[i].size(); j++)cout << " " << va[i][j];
        cout << endl;
    }
    return 0;
}