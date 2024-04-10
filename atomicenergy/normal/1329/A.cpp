using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int cur = n+1;
    vector<int> ans(m);
    for (int i = m-1; ~i; i--) {
        if (i + 1 + v[i] - 1 >= n+1) {
            cout << -1 << endl;
            return 0;
        }
        ans[i] = max(i + 1, cur - v[i]);
        cur = ans[i];
    }
    if (ans[0] != 1) cout << -1 << endl;
    else
        for (int i = 0; i < m; i++) 
            cout << ans[i] << " ";



}