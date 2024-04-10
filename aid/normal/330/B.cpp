#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<char> p(n);
    int v, u;
    for(int i = 0; i < m; i++) {
        cin >> v >> u;
        p[--v] = true;
        p[--u] = true;
    }
    int r;
    for(int i = 0; i < n; i++)
        if(!p[i]) {
            r = i + 1;
            break;
        }
    cout << n - 1 << '\n';
    for(int i = 1; i <= n; i++)
        if(i != r)
            cout << r << ' ' << i << '\n';
}