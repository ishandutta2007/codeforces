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
stringstream ss;
set <ll> s;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> m;
    while(m--){
        cin >> x;
        bool fl = 0;
        for(i = 1;i <= 200000; i++){
               if(sqr(i) <= x)continue;
            k = sqr(i) / (sqr(i) - x);
            a1 = sqrt(k);
            while(a1 * a1 < k)a1++;
            while(a1 * a1 > k)a1--;
            b1 = sqr(i / a1);
            if(b1 == sqr(i) - x){
                fl = 1;
                cout << i << " " << a1 << endl;
                break;
            }
        }
        if(!fl)cout << -1 << endl;
    }
    return 0;
}