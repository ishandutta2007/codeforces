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
        int n, m;
        cin >> n >> m;
        vector<ll> as(n);
        vector<ll> bs(n);
        vector<ll> pre(n+1);
        ll sum = 0;
        int idx = 0;
        for(ll &a : as) {
            cin >> a; sum += a;
        }
        ll sumb = 0;
        for(ll &a : bs) {
            cin >> a;
            sumb += a;
        }
        ll csum = 0;
        for(int i = 0; i < n; i ++) {
            as[i] -= bs[i];
            csum += as[i];
            pre[++idx] = csum;
        }
        vector<pi> segs(m);
        vector<vector<int>> ls(n);
        vector<vector<int>> rs(n);
        for(int i = 0; i < m; i ++) {
            int l, r;
            cin >> l >> r; l--; r--;
            segs[i] = {l,r};
            ls[l].push_back(i);
            rs[r].push_back(i);
        }
        if(sum != sumb) {
            cout << "NO\n";
            continue;
        }
        multiset<int> unupd;
        for(int i = 0; i < n; i ++) {
            unupd.insert(i);
        }
        deque<int> ss;
        for(int i = 0; i < m; i ++) {
            if(pre[segs[i].f] == pre[segs[i].s+1] && pre[segs[i].f] == 0) {
                ss.push_back(i);
            }
        }
        while(ss.size()) {
            int cur = ss.back();
            ss.pop_back();
            // cout << "  " << cur << endl;
            auto it = unupd.lower_bound(segs[cur].f);
            while(it != unupd.end() && *it <= segs[cur].s) {
                // cout << *it << endl;
                as[*it] = 0;
                pre[*it] = 0;
                for(int i : ls[*it]) {
                    if(pre[segs[i].s+1] == 0) {
                        ss.push_front(i);
                    }
                }
                for(int i : rs[*it]) {
                    if(pre[segs[i].f] == 0) {
                        ss.push_front(i);
                    }
                }
                auto tmp = it;
                it ++;
                unupd.erase(tmp);
            }
        }
        bool fail = false;
        for(int a : as) {
            if(a != 0) { fail = true; break; }
        }
        cout << (fail ? "NO\n":"YES\n");
    }
    return 0;
}

/*
1
5 3
-1 1 0 -1 1
0 0 0 0 0
1 2
4 5
2 4
*/