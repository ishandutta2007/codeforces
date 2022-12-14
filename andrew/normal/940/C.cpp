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
    cin.tie(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    cin >> s1;
    ll ke;
    for(i = 0 ; i < n; i++)a[s1[i] - 'a' ] = 1;
    for(i = 0; i < 26; i++)if(a[i])sc ++;
    ke = 1e18;
    for(j = 25; j >= 0; j--){
        b[j] = ke;
        if(a[j])ke = j;
    }
    m = min(n,k);
    s2 = s1;
    while(s2.size() > k)s2.erase(s2.size() - 1);
    while(s2.size() < k)s2 += char(ke + 'a');
    if(s2 > s1)vout(s2);
    for(j = k - 1; j >= 0; j--){
        c = s2[j] - 'a';
        if(b[c] != 1e18){
            s2[j] = char('a' + b[c]);
            break;
        }
        s2[j] = char(ke + 'a');
    }
    vout(s2);
    return 0;
}