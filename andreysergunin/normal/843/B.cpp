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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;

mt19937 rr(random_device{}());

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

vector<pair<int, int>> ans;

pair<int, int> request(int n) {
    int x, y;
    cout << "? " << n << endl;
    cin >> x >> y;
    return {x, y};
}


int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
    cout.tie(0);

    int n, x, st;
    cin >> n >> st >> x;
    ans.push_back(request(st));
    if (ans[0].first >= x) {
        cout << "! " << ans[0].first << endl;
        return 0;
    }

    for (int i = 0; i < 1000; ++i) {
        int pos = (rr() + rr()) % n + 1;
        if (pos <= 0)
            pos += n;
        ans.push_back(request(pos));
    }

    sort(all(ans));
    int k = 0;
    for ( ; k < sz(ans) && ans[k].first < x; ++k);
    --k;
    if (ans[k].first == x) {
        cout << "! " << ans[k].first << endl;
        return 0;
    }
    
    int cur = ans[k].second;
    for (; ; ) {
        if (cur == -1) {
            cout << "! " << -1 << endl;
            return 0;
        }

        pii p = request(cur);
        if (p.first >= x) {
            cout << "! " << p.first << endl;
            return 0;
        }
        
        cur = p.second;
    }

    return 0;
}