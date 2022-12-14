/*

LAUNCH GOOSE, WORKERS

















*/
#include <bits/stdc++.h>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))
#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl "\n"
#define pll pair <ll,ll>
#define vl vector <ll>

typedef long long ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=1000000;
const double eps = 1e-9;
const ll mod = 1e9 + 7;
using namespace std;

ll binpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n&1) ans*=a;
        a*=a;
        n >>= 1;
    }
    return ans;
}
ll n, m;
char a[1000][1000];
vector <ll> v[100];
set <ll> s[60], s1[60];
int main()
{
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            if (a[i][j] == '#'){
                v[j].push_back(i);
            }
        }
    }
    vector <ll> vi;
    for (int i = 1; i <= n; ++i){
        ll f = 0;
        ll ans = 0;
        vi.clear();
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '#'){
                vi.push_back(j);
            }
        }
        ll k = vi.size();
        for (int i = 0; i < k - 1; ++i){

            if (v[vi[i]].size() != v[vi[i + 1]].size()){
                cout << "No" << endl;
                return 0;
            } else {
                if (v[vi[i]] != v[vi[i + 1]]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}