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

const int INF = 1e9;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> lf(n), rg(n);

    int last = -INF;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            last = i;
        }
        lf[i] = i - last;
    }

    last = INF;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            last = i;
        }
        rg[i] = last - i;
    }

    for (int i = 0; i < n; ++i) {
        cout << min(lf[i], rg[i]) << " ";
    }
    cout << endl;
    return 0;
}