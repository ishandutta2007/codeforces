#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int k = 0;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int v, x;
            cin >> v >> x;
            a[--v] = x - k;
        }
        else if(t == 2) {
            int y;
            cin >> y;
            k +=y;
        }
        else {
            int q;
            cin >> q;
            cout << a[--q] + k << '\n';
        }
    }
}