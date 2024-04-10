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
void add(ll x){
    s3 = s1.substr(n - x, x);
    s1.erase(n - x, x);
    reverse(all(s3));
    s1 = s3 + s1;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    cin >> s1 >> s2;
    for(i = 0; i < n; i++)a[s1[i] - 'a']++;
    for(i = 0; i < n; i++){
        a[s2[i] - 'a']--;
        if(a[s2[i] - 'a'] < 0)vout(-1);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)if(s1[j - 1] == s2[i - 1])break;
        if(j + 1 <= n){
            va.p_b(n - j);
            add(n - j);
        }
        va.p_b(1);
        add(1);
        va.p_b(n);
        add(n);
    }
    cout << va.size() << endl;
    for(i = 0; i < va.size(); i++)cout << va[i] << " ";
    cout << endl;
    return 0;
}