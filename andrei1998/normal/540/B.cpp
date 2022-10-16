#include <iostream>
#include <algorithm>

using namespace std;

int v[1005];
int ans[1005];

int main()
{
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sum = x - sum;

    if (n - k > sum) {
        cout << "-1\n";
        return 0;
    }

    for (int i = k + 1; i <= n; i++) {
        if (n - i <= sum - y) {
            v[i] = y;
            sum -= y;
        }
        else {
            v[i] = 1;
            sum--;
        }

        ans[i - k] = v[i];
    }

    nth_element(v + 1, v + (n + 1) /2, v + n + 1);
    if (v[(n + 1) / 2] < y) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n - k; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}