#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> hotel(n);
    for(int i = 0; i < n; i++)
        cin >> hotel[i];
    vector<int> p(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        if(p[i] >= 0)
            c[p[i]]++;
    }
    int ans = 0, ansv = -1;
    for(int i = 0; i < n; i++)
        if(hotel[i]) {
            int v = i, k = 0;
            while(c[v] <= 1 && v >= 0) {
                v = p[v];
                k++;
            }
            if(k > ans) {
                ans = k;
                ansv = i;
            }
        }
    cout << ans << '\n';
    vector<int> path;
    int v = ansv;
    while(c[v] <= 1 && v >= 0) {
        path.push_back(v + 1);
        v = p[v];
    }
    for(int i = (int)path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';
    cout << '\n';
}