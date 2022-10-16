#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int a[MAXN], nxt[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    nxt[n - 1] = n;
    for(int i = n - 2; i >= 0; i--)
        nxt[i] = (a[i] == a[i + 1]? nxt[i + 1] : i + 1);
    for(int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        if(a[l] != x)
            cout << l + 1 << '\n';
        else if(nxt[l] < r)
            cout << nxt[l] + 1 << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}