#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e5 + 100;
const int inf = -1e9;
const ll M = 300000;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll zp[MAXN], zapros;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int sa, sb, l, r, last, ans = 0;
    last = sa = sb = l = 0;
    r = n - 1;
    int step = 0;
    while(l <= r){
        ans++;
        if(!step){
            int temp_sum = 0;
            while(l <= r){
                temp_sum += a[l];
                l++;
                if(temp_sum > last)break;
            }
            sa += temp_sum;
            last = temp_sum;
        }else{
            int temp_sum = 0;
            while(l <= r){
                temp_sum += a[r];
                r--;
                if(temp_sum > last)break;
            }
            sb += temp_sum;
            last = temp_sum;
        }
        step ^= 1;
    }
    cout << ans << " " << sa << " " << sb << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}