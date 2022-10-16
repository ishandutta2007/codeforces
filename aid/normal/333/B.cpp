#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<char> r(n, true), c(n, true);
    r[0] = false;
    r[n - 1] = false;
    c[0] = false;
    c[n - 1] = false;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        r[x - 1] = false;
        c[y - 1] = false;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(r[i])
            ans++;
        if(c[i])
            ans++;
    }
    if(n % 2 && r[n / 2] && c[n / 2])
        ans--;
    cout << ans << '\n';
}