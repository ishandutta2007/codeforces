#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <algorithm>


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    stack <int> a;
    vector <int> temp(m);
    for (int i = 0; i < m; i++) cin >> temp[i];
    for (int i = m - 1; i >= 0; i--) a.push(temp[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a.empty()) {
            cout << ans;
            return 0;
        }
        if (a.top() >= c[i]) {
            a.pop();
            ans++;
        }
    }
    cout << ans;
    return 0;
}