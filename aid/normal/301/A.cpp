#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 105, INF = 1000 * 1000 * 1000 + 5;
int a[2 * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int k = 0;
    for(int i = 0; i < 2 * n - 1; i++) {
        cin >> a[i];
        if(a[i] < 0)
            k++;
    }
    if(n & 1 || (!(n & 1) && !(k & 1))) {
        int ans = 0;
        for(int i = 0; i < 2 * n - 1; i++)
            ans += abs(a[i]);
        cout << ans << '\n';
    }
    else {
        int ans = 0, mina = INF;
        for(int i = 0; i < 2 * n - 1; i++) {
            ans += abs(a[i]);
            mina = min(mina, int(abs(a[i])));
        }
        cout << ans - 2 * mina << '\n';
    }
    return 0;
}