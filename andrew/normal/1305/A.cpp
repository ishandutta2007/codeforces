#include <bits/stdc++.h>
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("no-stack-protector")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pdd pair<ld, ld>
#define ft first
#define sd second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N = 100100;
const int M = 10;
const int oo = 2e9;
const ll OO = 1e18;
const int md = int(1e9) + 7;
const int K = 60;
const ld E = 1e-9;
int nm[N], nm1[N], a[N], b[N], n;

bool cmp1(int x, int y){
    return a[x] < a[y];
}

bool cmp2(int x, int y){
    return b[x] < b[y];
}

int main() {
#ifdef _LOCAL
    freopen("in.txt","r",stdin); // freopen("output.txt","w",stdout);
#else
//    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif

    int tt; cin >> tt;

    for (; tt; tt--){

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; nm[i] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i]; nm1[i] = i;
        }

        sort(nm, nm + n, cmp1);
        sort(nm1, nm1 + n, cmp2);

        for (int i = 0; i < n; i++)
            cout << a[nm[i]] << " "; cout << '\n';
        for (int i = 0; i < n; i++)
            cout << b[nm1[i]] << " "; cout << '\n';
    }

    return 0;
}