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

vector <pll> v, a;
vector <ll> va;
string s1,s2,s3;
set <pll> s;
map <ll, ll> mp;
char cc;
vector <ll> ku, ans;
ll st[MAXN], d[MAXN];
ll b[MAXN], c[MAXN],a1,b1,c1,i,j,n,m,k,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i = 0; i < n; i++)ku.p_b(0);
    for(i = 0; i < m; i++){
        cin >> a1 >> b1 >> c1;
        a1--;
        b1--;
        st[i] = a1;
        d[i] = b1;
        ku[b1] = m + 1;
        if(!(b1 - a1 < c1)){
            a.p_b(m_p(c1, i));
        }
    }
    ans = ku;
    sort(all(a));
    ll mx = 0;
    set <pll> :: iterator it;
    //cout << a[1].se  << endl;
    for(i = 1; i <= a.size(); ++i){
        va = ku;
        sc = 0;
        mp.clear();
        s.clear();
        for(j = 0; j < n; ++j){
            for(ll i1 = 0; i1 < i; ++i1)if(st[a[i1].se] == j)s.insert(m_p(d[a[i1].se], a[i1].se));
            if(!ku[j]){
                if(s.size() > 0){
                    it = s.begin();
                    va[j] = it -> se + 1;
                    ++mp[it -> se];
                }
            }
           // cout << a[0].se << " " << mp[a[0].se] << " " << endl;
            for(ll i1 = 0; i1 < i; ++i1)if(mp[a[i1].se] == a[i1].fi && s.find(m_p(d[a[i1].se], a[i1].se)) != s.end())s.erase(m_p(d[a[i1].se], a[i1].se)), sc++;
            for(ll i1 = 0; i1 < i; ++i1)if(mp[a[i1].se] + d[a[i1].se] - j < a[i1].fi)s.erase(m_p(d[a[i1].se], a[i1].se));
        }
        //cout << sc << endl;
        //cout << endl;
        if(sc > mx){
            mx = sc;
            ans = va;
        }
    }
    if(mx != m)vout(-1);
    for(i = 0; i < ans.size(); ++i)cout << ans[i] << " ";
    return 0;
}