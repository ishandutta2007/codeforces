#include <iostream>
#include <vector>

using namespace std;

vector<int> a[3];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;
        a[t].push_back(i);
    }
    int ans = min(a[0].size(), min(a[1].size(), a[2].size()));
    cout << ans << '\n';
    for(int i = 0; i < ans; i++)
        cout << a[0][i] + 1 << ' ' << a[1][i] + 1 << ' ' << a[2][i] + 1 << '\n';
    return 0;
}