#include <bits/stdc++.h>

#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

ll binpow(ll a,ll n)
{
    ll res = 1;
    while(n)
    {
        if(n % 2)res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}

template <typename T>
T sqr(T x)
{
    return x * x;
}

template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}

ll log(ll a,ll b){
    ll res = 0;
    while(a){
        a /= b;
        res++;
    }
    return res;
}

const ll MAXN = 1123456;
vector <ll> v[MAXN];
set <pll> st;
vector <pll> ans;
stringstream ss;
set <ll> s;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,x,k;
ll p[MAXN];
ll r;
ll get(ll x){
    if(p[x]!=x)p[x] = get(p[x]);
    return p[x];
}
void dfs(ll x){
    if(b[x])return;
    b[x] = r;
    ll i,nn=v[x].size();
    for(i=0;i<nn;i++)dfs(v[x][i]);
    return;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s1 >> s2;
    for(i=0;i<n;i++){
        a1 = s1[i] - 'a' + 1;
        b1 = s2[i] - 'a' + 1;
        a[a1] = 1;
        a[b1] = 1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
    }
    for(i = 1; i <= 26;i++)if(!b[i] && a[i]){
        r++;
        dfs(i);
    }
    for(i=1;i<=26;i++)p[i]=i;
        for(j=1;j<=26;j++)
        for(ll i1=1;i1<=26;i1++)if(b[j]==b[i1] && a[j]){
                //cout << i1 << " "
            if(get(j)!=get(i1)){
                p[get(j)]=get(i1);
                ans.p_b(m_p(j,i1));
            }
        }
     cout << ans.size() << endl;
     for(i=0;i<ans.size();i++){
        char cc= char(ans[i].fi + 'a' - 1);
        cout << cc << " ";
        cc = char(ans[i].se + 'a' - 1);
        cout << cc << endl;
     }
    return 0;
}