#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second
#define vvi vector<vi>
#define vvl vector<vl>

#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;

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
        map<int,int> cnt;
        for(int &x : xs) {
            cin >> x;
            cnt[x] ++;
        }
        if(n&1) {
            cout << "NO\n";
            continue;
        }
        bool fail = false;
        for(pi c : cnt) {
            if(c.s > n/2) {
                fail = true;
                cout << "NO\n";
                break;
            } else if(c.s == n/2) {
                int big = -1;
                bool ff = false;
                for(int i = 0; i < n; i ++) {
                    if(xs[i] != c.f) {
                        int nb = xs[i] > c.f;
                        if(big == -1) {
                            big = nb;
                        } else if(big != nb) {
                            ff = true;
                        }
                    }
                }
                if(ff) {
                    cout << "NO\n";
                    fail = true;
                    break;
                }
                int idx = 0;
                cout << "YES\n";
                for(int i = 0; i < n; i ++) {
                    if(i&1) {
                        cout << c.f << " ";
                    } else {
                        while(xs[idx] == c.f) { idx ++; }
                        cout << xs[idx] << " ";
                        idx ++;
                    }
                }
                cout << "\n";
                fail = true;
                break;
            }
        }
        if(fail) {
            continue;
        }
        vector<int> res(n);
        sort(xs.begin(),xs.end());
        cout << "YES\n";
        for(int i = 0; i < n; i += 2) {
            res[i] = xs[i/2];
        }
        for(int i = 1; i < n; i += 2) {
            res[i] = xs[i/2+n/2];
        }
        for(int r : res) {
            cout << r << " ";
        }
        cout << "\n";
    }

    return 0;
}