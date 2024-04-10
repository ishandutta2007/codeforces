#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
vector<int> a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int m;
        cin >> m;
        a[i].resize(m);
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for(int i = 0; i < k; i++)
        if(a[i][0] == 1) {
            int p = 0;
            while(p < (int)a[i].size() && a[i][p] == p + 1)
                p++;
            cout << (n - p + 1) - k + (n - p + 1) - 1 << '\n';
            return 0;
        }
    return 0;
}