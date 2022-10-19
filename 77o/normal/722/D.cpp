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

bool push(int v, set<int, greater<int>>& a) {
    if (v == 1) {
        return false;
    }
    if (!a.count(v / 2)) {
        a.erase(v);
        a.insert(v / 2);
        return true;
    }
    bool ok = push(v / 2, a);
    if (ok) {
        a.erase(v);
        a.insert(v / 2);
    }
    return ok;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    set<int, greater<int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    while (true) {
        int v = *a.begin();
        if (!push(v, a)) {
            break;
        }
    }
    for (int i : a) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}