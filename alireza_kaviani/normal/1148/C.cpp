/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

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
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

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
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , a[MAXN];
vector<pll> ans;
set<pll> st;

void move(ll x , ll y){
    ans.push_back({x , y});
    st.erase({a[x] , x});
    st.erase({a[y] , y});
    swap(a[x] , a[y]);
    st.insert({a[x] , x});
    st.insert({a[y] , y});
}

int main() {
    fast_io;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
        st.insert({a[i] , i});
    }

    for(ll i = 2 ; i < n ; i++){
        pll p = *st.upper_bound({i , -INF});
        if(p.Y <= n / 2){
            move(p.Y , n);
        }
        else{
            move(p.Y , 1);
        }
        p = *st.upper_bound({i , -INF});
        if(abs(p.Y - i) >= n / 2){
            move(p.Y , i);
            continue;
        }
        move(p.Y , n + 1 - p.Y);
        p = *st.upper_bound({i , -INF});
        move(p.Y , i);
    }

    if(a[1] > a[n]) move(1 , n);
    cout << ans.size() << endl;
    for(ll i = 0 ; i < ans.size() ; i++)    cout << ans[i].X << sep << ans[i].Y << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/