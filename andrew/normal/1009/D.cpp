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
vector <pll> r;
void stop(){
    vout("Impossible");
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    if(m + 1 < n)stop();
    for(int i = 2; i <= n; i++){
        m--;
        r.p_b(m_p(1, i));
    }
    for(int i = 2; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(!m)break;
            if(__gcd(i, j) == 1){
                r.p_b(m_p(i, j));
                m--;
            }
        }
        if(!m)break;
    }
    if(m > 0)stop();
    cout << "Possible\n";
    for(int i = 0; i < r.size(); i++)cout << r[i].fi << " " << r[i].se << endl;
    return 0;
}