#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define long long long
#define M 100100

long n, a[M];

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif
    int m;
    long ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0, x, y; i < m; ++i){
        cin >> x >> y;
        ans += min(a[x], a[y]);
    }
    cout << ans << "\n";
    return 0;
}