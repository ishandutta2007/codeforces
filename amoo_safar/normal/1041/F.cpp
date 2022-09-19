#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;

ll a[MAXN];
ll b[MAXN];

map<ll, ll> ma;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m,x1,x2;
    cin >> n >> x1;
    ll v,z1,f1,z2,f2;
    for(int i =0;i<n;i++) cin >> a[i];
    cin >> m >> x2;
    for(int i =0;i<m;i++) cin >> b[i];
    ll t = 1, ans = 2;
    while(t <= (ll)1e9){
        ma.clear();
        for(int i = 0; i < n;i++) ma[a[i] % (2 * t)]++;
        for(int i = 0; i < m;i++) ma[(b[i] + t) % (2 * t)]++;
        for(auto da : ma){
            ans = max(ans, da.S);
        }
        t *= 2;
    }
    cout << ans;
    return 0;

}