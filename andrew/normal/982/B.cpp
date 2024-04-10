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
string s2,s3;
map <ll, ll> mp;
set <pll> s, s1;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> a[i];
        s.insert(m_p(a[i], i));
    }
    set <pll> :: iterator it;
    for(i = 1; i <= 2 * n; ++i){
        cin >> cc;
        if(cc == '0'){
            it = s.begin();
            cout << it->se << " ";
            pll xe = *it;
            s.erase(it);
            s1.insert(xe);
        }else{
            it = s1.end();
            --it;
            cout << it->se << " ";
            s1.erase(it);
        }
    }
    return 0;
}