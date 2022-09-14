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
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 1001000;
int f[MAXN];
vector<int> g[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 
        
    for (int i = 0; i <= 9; ++i) {
        f[i] = i;
        g[f[i]].push_back(i);
    }       


    for (int i = 10; i < MAXN; ++i) {
        int nxt = 1;
        for (int tmp = i; tmp > 0; tmp /= 10) {
            if (tmp % 10 != 0) {
                nxt *= tmp % 10;
            }
        }
        f[i] = f[nxt];
        g[f[i]].push_back(i);
    }


    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        ++r;



        int res = lower_bound(all(g[k]), r) - lower_bound(all(g[k]), l);
        cout << res << endl;
    }
    return 0;
}