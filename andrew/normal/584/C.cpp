#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, t;
    cin >> n >> t;

    string a, b;
    cin >> a >> b;

    string c;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++)if(char('a' + j) != a[i] && char('a' + j) != b[i]){
            c += char('a' + j);
            break;
        }
    }

    ll ra, rb;
    ra = t - n, rb = t - n;

    for(int i = 0; i < n; i++)if(a[i] == b[i] && ra < 0){
        ra++;
        rb++;
        c[i] = a[i];
    }

    for(int i = 0; i < n; i++)if(a[i] != b[i] && ra < 0){
        ra++;
        c[i] = a[i];
    }

    for(int i = 0; i < n; i++)if(c[i] != a[i] && a[i] != b[i] && rb < 0){
        rb++;
        c[i] = b[i];
    }

    if(ra < 0 || rb < 0)vout(-1);

    cout << c << "\n";

    return 0;
}