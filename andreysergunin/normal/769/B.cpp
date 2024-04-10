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
    // freopen("input.txt", "r", stdin)p;
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    if (a[0] == 0 || sum < n - 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = {a[i], i};
    }
    sort(p.begin() + 1, p.end());
    reverse(p.begin() + 1, p.end());

    cout << n - 1 << endl;
    
    int j = 0;
    for (int i = 1; i < n; ++i) {
        for (; p[j].first == 0; ++j);
        cout << p[j].second + 1 << " " << p[i].second + 1 << endl;
        --p[j].first;
    }
}