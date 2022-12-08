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
// #define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { // cout << "  "; } // cout << #k << ": " << k << enl;

const int MOD = 998244353;
const ll MODL = 998244353;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

struct NUM {
    ll val = 0;
    bool large = false;
    bool operator<(ll n) {
        if(large) { return false; }
        return val < n;
    }
    void operator+=(NUM n) {
        large |= n.large;
        if(large) {
            val += n.val;
            val %= MODL;
        } else {
            val += n.val;
            if(val >= MODL) {
                val %= MODL;
                large = true;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<NUM> as(n);
        for(NUM &a : as) {
            cin >> a.val;
        }
        vector<vector<int>> nei(n);
        vector<vector<int>> rev(n);
        vector<int> deg(n);
        for(int i = 0; i < m; i ++) {
            int a, b;
            cin >> a >> b; a--; b--;
            nei[a].push_back(b);
            rev[b].push_back(a);
        }
        int st;
        for(int i = 0; i < n; i ++) {
            deg[i] = nei[i].size();
            if(nei[i].empty()) {
                st = i;
            }
        }
        ll lst = 0;
        ll res = 0;
        NUM en;
        en.val = -1e9;
        for(int t = 0; t < n; t ++) {
            if(en < t) {
                lst = t;
                en.val = lst;
                en += as[st];
            } else {
                en += as[st];
            }
            if(en.val != lst || en.large) {
                res = en.val;
            }
            vector<NUM> bs(n);
            for(int i = 0; i < n; i ++) {
                for(int ne : nei[i]) {
                    bs[ne] += as[i];
                }
            }
            as = bs;
        }
        cout << res << "\n";
        continue;
        // cout << "W" << endl;
        // vi ord;
        // queue<int> bfs; bfs.push(st);
        // while(bfs.size()) {
        //     int cur = bfs.back();
        //     bfs.pop();
        //     ord.push_back(cur);
        //     for(int r : rev[cur]) {
        //         deg[r] --;
        //         if(deg[r] == 0) {
        //             bfs.push(r);
        //         }
        //     }
        // }
        // reverse(ord.begin(),ord.end());
        // vector<vector<pl>> segs(n);
        // for(int i = 0; i < n - 1; i ++) {
        //     int x = ord[i];
        //     // cout << "~ " << x << endl;
        //     segs[x].push_back({0,as[x]});
        //     sort(segs[x].begin(),segs[x].end());
        //     ll lst = 0;
        //     ll en = -1e9;
        //     for(pl seg : segs[x]) {
        //         // cout << seg.f << " " << seg.s << endl;
        //         if(seg.f <= en) {
        //             en += seg.s;
        //         } else {
        //             if(en >= 0) {
        //                 // cout << x << " | " << lst << " " << en << endl;
        //                 for(int ne : nei[x]) {
        //                     segs[ne].push_back({lst+1,en-lst+1});
        //                 }
        //             }
        //             lst = seg.f;
        //             en = seg.f + seg.s - 1;
        //         }
        //     }
        //     if(en >= 0) {
        //         // cout << x << " | " << lst << " " << en << endl;
        //         for(int ne : nei[x]) {
        //             segs[ne].push_back({lst+1,en-lst+1});
        //         }
        //     }
        // }
        // ll res = 0;
        // int x = ord[n-1];
        // segs[x].push_back({0,as[x]});
        // sort(segs[x].begin(),segs[x].end());
        // ll lst = 0;
        // ll en = -1e9;
        // for(pl seg : segs[x]) {
        //     // cout << seg.f <<  " - " << seg.s << endl;
        //     if(seg.f <= en) {
        //         en += seg.s;
        //     } else {
        //         res = en;
        //         lst = seg.f;
        //         en = seg.f + seg.s - 1;
        //     }
        // }
        // res = en;
        // cout << (res+1)%MODL << "\n";
    }
    return 0;
}


/*
1
3 2
1 1 1
1 2
2 3
*/

/*
1
5 5
1 0 0 0 0
1 2
2 3
3 4
4 5
1 5
*/
/*
1
3 2
1 2 1
1 2
2 3
*/

/*
1
5 10
998244352 998244352 998244352 998244352 998244352
1 2
2 3
3 4
4 5
1 3
1 4
1 5
2 4
2 5
3 5
*/