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
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s1;
    n = s1.size();
    for(i = 0; i < n; i++){s.insert(s1[i]);b[s1[i] - 'a']++;}
    if(s.size() == 1 or s.size() > 4)vout("no");
    if(s.size() == 4)vout("yes");
    if(s.size() == 2){
        ll mn = 1e18;
        for(i = 0; i < 26; i++)if(b[i])mn = min(mn, b[i]);
        //cout << mn << endl;
        if(mn > 1)vout("Yes");
        vout("no");
    }
    ll mx = 0;
    for(i = 0; i < 26; i++)mx = max(mx, b[i]);
    //cout << mx << endl;
    if(mx > 1)vout("yes");
    vout("no");
    return 0;
}