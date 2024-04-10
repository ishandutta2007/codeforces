#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

const int mxN = 1e5+5;
const int mxP = 18;
int super[mxN][mxP];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> prime(mxN,mxN);
    for(ll i = 2; i < mxN; i ++) {
        if(prime[i] == mxN) {
            prime[i] = i;
            for(ll j = i*i; j < mxN; j += i) {
                prime[j] = min(prime[j],(int)i);
            }
        }
    }
    int n, q;
    cin >> n >> q;
    vector<int> xs(n);
    for(int &x : xs) {
        cin >> x;
    }
    vector<int> last(mxN,n);
    int mn = n;
    for(int i = n - 1; i >= 0; i --) {
        int x = xs[i];
        while(x > 1) {
            int p = prime[x];
            mn = min(mn,last[p]);
            last[p] = i;
            while(x%p == 0) {
                x /= p;
            }
        }
        super[i][0] = mn;
    }
    super[n][0] = n;
    for(int p = 1; p < mxP; p ++) {
        for(int i = 0; i <= n; i ++) {
            super[i][p] = super[super[i][p-1]][p-1];
        }
    }
    for(int qi = 0; qi < q; qi ++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        int p2 = 1<<(mxP-1);
        int cnt = 1;
        for(int p = mxP-1; p >= 0; p --) {
            if(super[a][p] <= b) {
                a = super[a][p];
                cnt += p2;
            }
            p2 /= 2;
        }
        cout << cnt << "\n";
    }
    return 0;
}