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
        int n;
        cin >> n;
        vector<int> xs(n);
        vector<int> nxt(n);
        for(int &x : xs) {
            cin >> x;
        }
        deque<int> mx = {n+1};
        deque<int> mn = {n+1};
        for(int i = n - 1; i >= 0; i --) {
            int x = xs[i];
            while(mx.size() > 1 && xs[mx.front()] < x) {
                mx.pop_front();
            }
            int up = mx.front();
            mx.push_front(i);
            
            while(mn.size() > 1 && xs[mn.front()] > x) {
                mn.pop_front();
            }
            int lw = mn.front();
            mn.push_front(i);
            // cout << i << ". " << x << " | " << (lw) << " " << up << endl;
            if(lw < up) {
                int l = 1, r = mn.size()-2;
                while(l < r) {
                    int mid = (l+r+1)/2;
                    if(mn[mid] < up) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                nxt[i] = mn[l];
            } else {
                int l = 1, r = mx.size()-2;
                while(l < r) {
                    int mid = (l+r+1)/2;
                    if(mx[mid] < lw) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                nxt[i] = mx[l];
            }
            
            // cout << nxt[i] << endl;
        }
        int cnt = 0;
        int cur = 0;
        while(cur != n-1) {
            cur = nxt[cur];
            cnt ++;
        }
        cout << cnt << "\n";
    }

    return 0;
}


/*
1
5
2 1 5 3 4

*/