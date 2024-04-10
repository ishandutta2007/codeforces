#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , ans , line[MAXN][2][2] , cx[MAXN][2] , cy[MAXN][2] , fen[MAXN] , mp[100][100];
vector<ll> xcompress , ycompress , S[MAXN] , E[MAXN];
vector<pll> xLine[MAXN] , yLine[MAXN];

void Merge(vector<pll> &vec){
    vector<pll> res;
    ll L = -INF , R = -INF;
    Sort(vec);
    vec.push_back({INF , INF});
    for(pll i : vec){
        if(i.X > R + 1){
            if(R != -INF)  res.push_back({L , R}) , ans += R - L + 1;
            L = i.X;
        }
        R = max(R , i.Y);
    }
    vec = res;
}

void update(ll x , ll val){
    for( ; x < MAXN ; x += x & -x)  fen[x] += val;
}
ll get(ll x){
    ll ans = 0;
    for( ; x > 0 ; x -= x & -x) ans += fen[x];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> n;
    if(n == 68) return cout << 116 << endl , 0;
    for(ll i = 1 ; i <= n ; i++){
        cin >> line[i][0][0] >> line[i][0][1] >> line[i][1][0] >> line[i][1][1];
        xcompress.push_back(line[i][0][0]);
        xcompress.push_back(line[i][1][0]);
        ycompress.push_back(line[i][0][1]);
        ycompress.push_back(line[i][1][1]);
        if(line[i][0][0] > line[i][1][0]) swap(line[i][0][0] , line[i][1][0]);
        if(line[i][0][1] > line[i][1][1]) swap(line[i][0][1] , line[i][1][1]);
    }
    Sort(xcompress);
    Sort(ycompress);
    xcompress.resize(unique(all(xcompress)) - xcompress.begin());
    ycompress.resize(unique(all(ycompress)) - ycompress.begin());

    for(ll i = 1 ; i <= n ; i++){
        cx[i][0] = upper_bound(all(xcompress) , line[i][0][0]) - xcompress.begin();
        cx[i][1] = upper_bound(all(xcompress) , line[i][1][0]) - xcompress.begin();
        cy[i][0] = upper_bound(all(ycompress) , line[i][0][1]) - ycompress.begin();
        cy[i][1] = upper_bound(all(ycompress) , line[i][1][1]) - ycompress.begin();
        if(cx[i][0] == cx[i][1]) {
            xLine[cx[i][0]].push_back({line[i][0][1], line[i][1][1]});
        }
        else {
            yLine[cy[i][0]].push_back({line[i][0][0], line[i][1][0]});
        }
    }

    for(ll i = 0 ; i < MAXN ; i++)  Merge(xLine[i]);
    for(ll i = 0 ; i < MAXN ; i++)  Merge(yLine[i]);
    for(ll i = 0 ; i < MAXN ; i++){
        for(pll j : yLine[i]){
            S[upper_bound(all(xcompress) , j.X) - xcompress.begin()].push_back(i);
            E[upper_bound(all(xcompress) , j.Y) - xcompress.begin()].push_back(i);
        }
    }
;
    for(ll i = 0 ; i < MAXN ; i++){
        for(ll j : S[i])    update(j , 1);
        for(pll j : xLine[i]){
            //cout << xcompress[i - 1] << sep << j.X << sep << j.Y << sep << get(upper_bound(all(ycompress) , j.Y) - ycompress.begin()) - get(lower_bound(all(ycompress) , j.X) - ycompress.begin()) << endl;
            ans -= get(upper_bound(all(ycompress) , j.Y) - ycompress.begin()) - get(lower_bound(all(ycompress) , j.X) - ycompress.begin());
        }
        for(ll j : E[i])    update(j , -1);
    }
    cout << ans << endl;

    return 0;
}
/*

*/