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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> as(n+2);
        ll sum = 0;
        multiset<ll> vs;
        for(ll &a : as) {
            cin >> a;
            sum += a;
            vs.insert(a);
        }
        bool fnd = false;
        for(ll i = 0; i < n + 2; i ++) {
            ll lft = sum-2*as[i];
            if(vs.count(lft) >= (as[i] == lft ? 2 : 1)) {
                bool done = false;
                vector<ll> res;
                for(ll j = 0; j < n + 2; j ++) {
                    if(i == j) { continue; }
                    if((!done) && (as[j] == lft)) { done = true; continue; }
                    res.push_back(as[j]);
                }
                fnd = true;
                for(ll r : res) {
                    cout << r << " ";
                }
                cout << "\n";
                break;
            }
        }
        if(fnd) { continue; }
        cout << "-1\n";
    }
    return 0;
}