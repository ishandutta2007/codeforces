#include <bits/stdc++.h>

#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()
#define x kkee
#define y kk_e

using namespace std;
typedef long long ll;


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
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,k;
double R;
double x,y,y1,x1;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> R >> x1 >> y1 >> x >> y;
    if(x1 == x && y1 == y){
       double  re = R / 2.0;
        cout << fixed << setprecision(7) << x1 << " " << y1 + re << " " << re << endl;
        exit(0);
    }
    double D = sqrt(sqr(x - x1) + sqr(y - y1));
    if(R - D <= 1e-6){
        cout << fixed << setprecision(7) << x1 << " " << y1 << " " << R << endl;
        exit(0);
    }
    double x2 = x1 + R / D * (x1 - x), y2 = y1 + R / D * (y1 - y);
    double x3 = (x + x2) / 2.0, y3 = (y + y2) / 2.0;
    double re = sqrt(sqr(x - x3) + sqr(y - y3));
    cout << fixed << setprecision(7) << x3 << " " << y3 << " " << re << endl;
    return 0;
}