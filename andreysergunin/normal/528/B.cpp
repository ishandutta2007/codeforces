#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector< pair<int, int> > seg;
    for (int i = 0; i < n; i++) {
        int x, w;
        cin >> x >> w;
        seg.push_back(make_pair(x + w, x - w));
    }
    sort(seg.begin(), seg.end());
    int ans = 0;
    int last = -2 * 1e9;
    for (int i = 0; i < seg.size(); i++) {
        if (last > seg[i].second)
            continue;
        ans++;
        last = seg[i].first;
    }
    cout << ans << endl;
    return 0;
}