#include <iostream>

using namespace std;

int v[505];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    v[0] = v[n + 1] = k;
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        while (v[i] + v[i + 1] < k) {
            ++ v[i + 1];
            ++ ans;
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; ++ i)
        cout << v[i] << " \n"[i == n];

    return 0;
}