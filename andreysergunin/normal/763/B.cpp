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
mt19937 rr(random_device{}());


int main() {
    // ifstream cin("input.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> col(n);
    for (int i = 0; i < n; ++i)  {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        col[i] = 2 * (x1 & 1) + (y1 & 1);
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; ++i)
        cout << col[i] + 1 << "\n";
    return 0;
}