#include <bits/stdc++.h>
using namespace std;

int nbs[600 * 1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        nbs[v]++;
    }

    for(int v = 1;v < x;v++) {
        if(nbs[v] % (v + 1) != 0) {
            cout << "No" << endl;
            return 0;
        }
        nbs[v + 1] += nbs[v] / (v + 1);
        nbs[v] = 0;
    }

    cout << "Yes" << endl;
    return 0;
}