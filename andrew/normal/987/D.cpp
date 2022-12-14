#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
vector <ll> s[100001];
char cc;
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
queue <ll> q;

void add(ll j, ll val){
    if(b[j] != 1e18)return;
    b[j] = val;
    q.push(j);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k >> x;
    for(i = 1; i <= n; i++)cin >> a[i];
    while(m--){
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
    }
    for(i = 1; i <= k; i++){
        for(j = 1; j <= n; j++){
                b[j] = 1e18;
                if(a[j] == i)q.push(j), b[j] = 0;
        }
        while(!q.empty()){
            ll j = q.front();
            q.pop();
            ll nn = v[j].size(), val = b[j] + 1;
            for(int i = 0; i < nn; i++)add(v[j][i], val);
        }
        for(j = 1; j <= n; j++)s[j].p_b(b[j]);
    }
    for(i = 1; i <= n; i++){
        sc = 0;
        sort(all(s[i]));
        for(j = 0; j < x; j++)sc += s[i][j];
        cout << sc << " ";
    }
    return 0;
}