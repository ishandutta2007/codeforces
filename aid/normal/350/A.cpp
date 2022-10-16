#include <iostream>

using namespace std;

const int INF = 1000;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int maxa = 0, mina = INF;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        maxa = max(maxa, a);
        mina = min(mina, a);
    }
    int ans = max(2 * mina, maxa);
    for(int i = 0; i < m; i++) {
        int b;
        cin >> b;
        if(b <= ans) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
}