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
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    x.push_back(1e9);
    ++n;
    
    vector<int> y(m), l(m), r(m);
    
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> y[i];
        if (l[i] != 1) {
            --m;
            --i;
            continue;
        }
        
    }
    
    r.resize(m);
    
    sort(all(x));
    sort(all(r));
    
    int res = m;
    int it = 0;
    
    for (int i = 0; i < n; ++i) {
        while (it < m && r[it] < x[i]) {
            ++it;
        }
        
        res = min(res, i + m - it);
        
    }
    
    cout << res << endl;
    
    
}