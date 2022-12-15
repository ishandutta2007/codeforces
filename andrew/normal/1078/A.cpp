#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

pair <ld, ld> tch(ld A, ld B, ld C, ld A1, ld B1, ld C1){
    ld x = -(C * B1 - C1 * B1) / (A * B1 - A1 * B);
    ld y = -(A * C1 - A1 * C) / (A * B1 - A1 * B);
    return {x, y};
}

ld r(ld x, ld y, ld x1, ld y1){
    return sqrt(sqr(x - x1) + sqr(y - y1));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ld a, b, c;
    cin >> a >> b >> c;
    ld x1, y1, x, y;
    cin >> x >> y >> x1 >> y1;

    ld ans = abs(x - x1) + abs(y - y1);

    if(b != 0){
        ld xe = x, ye = -(c + a * x) / b;

        ld xe1 = x1, ye1 = -(c + a * x1) / b;
        ans = min(ans, r(x, y, xe, ye) + r(xe, ye, xe1, ye1) + r(xe1, ye1, x1, y1));

        if(a != 0){
            ld xe1 = (-c - b * y1) / a, ye1 = y1;
            ans = min(ans, r(x, y, xe, ye) + r(xe, ye, xe1, ye1) + r(xe1, ye1, x1, y1));
        }

    }

    if(a != 0){
        ld xe = (-c - b * y) / a, ye = y;


        ld xe1 = (-c - b * y1) / a, ye1 = y1;
            ans = min(ans, r(x, y, xe, ye) + r(xe, ye, xe1, ye1) + r(xe1, ye1, x1, y1));

        if(b != 0){
            ld xe1 = x1, ye1 = -(c + a * x1) / b;
            ans = min(ans, r(x, y, xe, ye) + r(xe, ye, xe1, ye1) + r(xe1, ye1, x1, y1));
        }
    }
    cout << fixed << setprecision(9) << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}