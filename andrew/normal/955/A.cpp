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
    cin >> a1 >> b1;
    ll H, D, C, N;
    cin >> H >> D >> C >> N;
    double ans = 1e9;
    while(1){
        ll kol = H / N;
        double stoim = C;
        if(a1 >= 20)stoim = C - C * 0.2;
        if(H % N)kol++;
        double k = kol;
        ans = min(ans, double (k * stoim));
        H += D;
        //cout << a1 << " " << b1 << " " << k * stoim << " " << stoim << endl;
        b1++;
        if(b1 == 60 && a1 == 23)break;
        if(b1 == 60){
            b1 = 0;
            a1++;
        }

    }
    cout << fixed  << setprecision(5) << ans << endl;
    return 0;
}