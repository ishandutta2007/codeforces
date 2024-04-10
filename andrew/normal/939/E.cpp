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
ll stn;
ll pref[MAXN];
ll get(ll l,ll r){
    return pref[r] - pref[l - 1];
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    while(n--){
        cin >> x;
        if(x == 1){
            cin >> a1;
            stn++;
            a[stn] = a1;
            pref[stn] = pref[stn - 1] + a1;
        }else {
            ll l = 0,r = stn - 1;
            for(j = 0;j < 100; j++){
                if(l >= r)break;
                ll c1 = l + (r - l + 1) / 3, c2 = r - (r - l + 1) / 3;
                if(c1 == c2 && c2 == r)c1--;else
                if(c1 == c2)c2++;
                double kol1 = c1 + 1,su1 = a[stn];
                if(c1 != 0)su1 += get(1 , c1);

                double kol2 = c2 + 1,su2 = a[stn];
                if(c2 != 0)su2 += get(1 , c2);
                double sc1 = a[stn] - (su1 / kol1);
                double sc2 = a[stn] - (su2 / kol2);
                //cout << c1 << " " << sc1 << endl;
                //cout << c2 << " " << sc2 << endl;
                if(sc1 - sc2 <= 1e-9)l = c1 + 1; else r = c2 - 1;
            }
            //cout << l << endl;
                double kol2 = l + 1,su2 = a[stn];
                if(l != 0)su2 += get(1 , l);
                double sc1 = a[stn] - (su2 / kol2);
                cout << fixed  << setprecision(7) << sc1 << endl;
        }
    }
    return 0;
}