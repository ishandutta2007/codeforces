#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t --) {
        int n, r;
        cin >> n >> r;

        int sum = 0;
        for (int i = 1; i < n; ++ i) {
            int val;
            cin >> val;
            -- val;

            sum += val;

            if (sum >= n)
                sum -= n;
        }

        cout << (r + n - sum) % n + 1 << '\n';
    }

    return 0;
}