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

    int n;
    cin >> n;
    vector<ll> ms(n);
    for(ll &m : ms) { cin >> m; }
    vector<ll> L(n);
    vector<ll> R(n);
    deque<pl> hs; hs.push_back({0,-1});
    ll cur_sum = 0;
    for(int i = 0; i < n; i ++) {
        ll cur = ms[i];
        while(hs.size() && hs.back().f >= cur) {
            pi b = hs.back();
            hs.pop_back();
            cur_sum -= (b.f * (b.s-hs.back().s));
        }
        cur_sum += cur * (i - hs.back().s);
        hs.push_back({cur,i});
        L[i] = cur_sum;
    }
    hs.clear();
    hs.push_back({0,n});
    cur_sum = 0;
    for(int i = n-1; i >= 0; i --) {
        ll cur = ms[i];
        while(hs.size() && hs.back().f >= cur) {
            pi b = hs.back();
            hs.pop_back();
            cur_sum -= (b.f * (hs.back().s-b.s));
        }
        cur_sum += cur * (hs.back().s-i);
        hs.push_back({cur,i});
        R[i] = cur_sum;
    }
    ll mx = 0;
    ll best = 0;
    for(int i = 0; i < n; i ++) {
        ll cur = L[i] + R[i] - ms[i];
        // cout << L[i] << " " << R[i] << " " << ms[i] << "\n";
        if(cur > mx) {
            mx = cur;
            best = i;
        }
    }
    vector<int> res(n);
    ll mn = 1e9;
    for(int i = best; i < n; i ++) {
        mn = min(mn,ms[i]);
        res[i] = mn;
    }
    mn = 1e9;
    for(int i = best; i >= 0; i --) {
        mn = min(mn,ms[i]);
        res[i] = mn;
    }
    for(int r: res) {
        cout << r << " ";
    }
    return 0;
}