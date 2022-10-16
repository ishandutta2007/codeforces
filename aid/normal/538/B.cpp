#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> ans;
    while(n) {
        int x = n, y = 0, p = 1;
        while(x) {
            if(x % 10)
                y += p;
            x /= 10;
            p *= 10;
        }
        n -= y;
        ans.push_back(y);
    }
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}