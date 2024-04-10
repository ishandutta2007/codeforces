#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    int p = 0, n = 1;
    vector<int> ans;
    while(p <= m) {
        if(p == m)
            ans.push_back(n);
        n++;
        int x = n;
        while(!(x % 5)) {
            x /= 5;
            p++;
        }
    }
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}