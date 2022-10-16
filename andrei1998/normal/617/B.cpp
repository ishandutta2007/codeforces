#include <iostream>

using namespace std;

int v[105];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    long long int ans = 1;

    int j;
    bool ok = false;
    for (int i = 1; i <= n; i = j) {
        j = i + 1;
        if (v[i] == 1) {
            ok = true;
            for (; j <= n; ++ j)
                if (v[j] == 1)
                    break;

            if (j == n + 1)
                break;
            if (i != j)
                ans = ans * (j - i);
        }
    }

    if (ok)
        cout << ans << '\n';
    else
        cout << "0\n";
    return 0;
}