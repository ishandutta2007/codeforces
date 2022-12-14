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

vector <ll> v[MAXN],v1[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll stn;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s1;
    n = s1.size();
    //long double ke = 1.0 / (n);
    ans = 0;
    for(i = 0; i < n; i++){
        x = s1[i] - 'a';
        v[x].p_b(i);
        v1[x].p_b(i);
    }
    //cout << v[9].size() << endl;
    for(i = 0; i < 26; i++)if(v[i].size()){
        for(j = 0; j < n; j++)c[j] = 0;
        j = 1;
        ll nn = v[i].size();
        while(j < n){
                s.clear();
            for(ll i1 = 0; i1 < nn; i1++){
                v[i][i1]++;
                if(v[i][i1] == n)v[i][i1] = 0;
            }
            for(ll i1 = 0; i1 < nn; i1++){
                b[s1[v[i][i1]] - 'a']++;
            }
            for(ll i1 = 0; i1 < nn; i1++){
                x = v[i][i1];
                if(b[s1[x] - 'a'] == 1)c[j]++;
                b[s1[x] - 'a'] = 0;
            }
            j++;
        }
        sc = 0;
        for(j = 0;j < n; j++)sc = max(sc, c[j]);
        ans += sc;
    }
    //cout << c[3] << " " << n << endl;
   // for(i = 1; i < n; i++)ans = max(c[i], ans);
    double ke = n;
    cout << fixed << setprecision(7) << ans / ke << endl;
    return 0;
}