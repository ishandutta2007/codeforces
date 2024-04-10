#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

const int P = 998244353;

const int MAXN = 3030;

int arr[MAXN];

vector<vector<int>> res;

void add(vector<int> a, vector<pii> to_add) {
    vector<int> cur;
    for (int i : a) {
        --arr[i];
        cur.push_back(i);
        assert(arr[i] >= 0);
    }
    for (auto [i, x] : to_add) {
        if (arr[i] > x) {
            --arr[i];
            cur.push_back(i);
        }
    }

    res.push_back(cur);
}

void solve(vector<int> id, vector<pii> to_add = {}) {
    if (sz(id) == 0) {
        return;
    }

    // for (int i : id) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto [i, j] : to_add) {
    //     cout << i << " " << j << endl;
    // }
    // cout << endl;

    vector<int> ps;
    int n = sz(id);

    for (int i : id) {
        if (arr[i] == n) {
            ps.push_back(i);
        }
    }
    if (sz(ps) == 0) {
        int x = id.back();

        to_add.push_back({x, 1});
        id.pop_back();
        solve(id, to_add);
        
        if (arr[x] > 0) {
            to_add.pop_back();
            add({x}, to_add);
            // assert(arr[x] == 0); 
        }


    } else {
        int x = ps.back();

        ps.pop_back();
        if (sz(ps) > 0) {
            add(ps, to_add);
        }  
        to_add.push_back({x, 0});
        
        for (int i = 0; i < sz(id); ++i) {
            if (id[i] == x) {
                swap(id[i], id.back());
                id.pop_back();
                break;
            }
        }
        solve(id, to_add); 

        if (arr[x] > 0) {
            to_add.pop_back();
            add({x}, to_add);
            // assert(arr[x] == 0); 
        }
    }


}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> id(n);
    iota(all(id), 0);

    solve(id);

    cout << sz(res) << endl;
    for (auto vct : res) {
        string s(n, '0');
        for (int pos : vct) {
            s[pos] = '1';
        }
        cout << s << endl;
    }

    for (int i = 0; i < n; ++i) {
        cerr << arr[i] << " ";
    }
    cerr << endl;


#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}