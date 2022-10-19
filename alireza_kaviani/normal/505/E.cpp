#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , k , p , H[MAXN] , A[MAXN] , cnt[MAXN] , beats[MAXN] , r[MAXN];

ll check(ll x){
    fill(cnt , cnt + MAXN , 0);
    fill(beats ,beats + MAXN , 0);
    fill(r , r + MAXN , 0);

    ll sum = 0;
    for(ll i = 0 ; i < n ; i++){
        ll h = H[i] + A[i] * m;
        beats[i] = (h - x + p - 1) / p;
        r[i] = (h - x) % p;
        if(beats[i] <= 0){
            beats[i] = 0;
            r[i] = 0;
        }
        sum += beats[i];
    }
    if(sum > m * k) return 0;

    for(ll i = 0 ; i < n ; i++){
        ll lastH = H[i] , lastDay = 0;
        for(ll j = 0 ; j < beats[i] ; j++){
            ll day = (p - lastH % p + A[i] - 1) / A[i] + lastDay , newH = day * A[i] + H[i];
            if(j == 0){
                if(lastH >= r[i]){
                    day = lastDay;
                    newH = lastH;
                }
                else{
                    day = (r[i] - lastH + A[i] - 1) / A[i];
                    newH = day * A[i] + H[i];
                }
            }
            else if(lastH >= (j + 1) * p){
                day = lastDay;
                newH = lastH;
            }
            cnt[day]++;
            lastH = newH;
            lastDay = day;
            if(day >= m)    return 0;
        }
    }

    for(ll i = 0 ; i < m ; i++){
        if(cnt[i] > k){
            cnt[i + 1] += cnt[i] - k;
            cnt[i] = k;
        }
    }
    return (cnt[m] == 0);
}

int main() {
    fast_io;

    cin >> n >> m >> k >> p;
    for(ll i = 0 ; i < n ; i++) cin >> H[i] >> A[i];

    ll l = 0 , r = 1e15;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        if(check(mid))  r = mid;
        else    l = mid;
    }
    cout << r << endl;

    return 0;
}
/*

*/