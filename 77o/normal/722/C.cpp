#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <random>
#include <map>
#include <stack>
#include <set>
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 1e5 + 5;

ll a[N];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    set<int> cuts;
    multiset<ll, greater<ll>> kek;
    cuts.insert(0);
    cuts.insert(n + 1);
    kek.insert(a[n]);
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        auto it1 = cuts.lower_bound(pos);
        auto it2 = it1--;
        int r = *it2;
        int l = *it1;
        kek.erase(kek.find(a[r - 1] - a[l]));
        kek.insert(a[r - 1] - a[pos]);
        kek.insert(a[pos - 1] - a[l]);
        cuts.insert(pos);
        cout << *kek.begin() << '\n';
    }
    return 0;
}