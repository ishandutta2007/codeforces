#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
                
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> l(q + 1, n), r(q + 1, 0);

    int pos0 = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = max(r[a[i]], i);
        } else {
            pos0 = i;
        }
    }

    set<int> setik;
    for (int i = 0; i < n; ++i) {
        setik.insert(i);
    }

    vector<int> res(n, 1);  
    bool flag = false;

    for (int i = q; i >= 1; --i) {
        if (l[i] > r[i]) {
            if (i == q) {
                flag = true;
                if (pos0 == -1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
                
            continue;
        } 

        auto it = setik.lower_bound(l[i]);

        while (it != setik.end() && *it <= r[i]) {
            res[*it] = i;
            setik.erase(it);
            it = setik.lower_bound(l[i]);
        }  
    }

    if (flag) {
        res[pos0] = q;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            continue;
        }
        if (a[i] != res[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }


    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}