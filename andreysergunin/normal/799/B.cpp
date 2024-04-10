#include <stdio.h>
#include <iostream>
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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n;
    cin >> n;

    set<int> s[3];

    vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i < n; ++i) {
        --a[i]; --b[i];
        s[a[i]].insert(p[i]);
        s[b[i]].insert(p[i]);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        if (!s[x].empty()) {
            int ans = *s[x].begin();
            cout << ans << " ";
            for (int i = 0; i < 3; ++i) {
                s[i].erase(ans);
            }
            
        } else {
            cout << -1 << " ";
        } 
    }
    cout << endl;
}