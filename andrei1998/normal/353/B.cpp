#include <iostream>

using namespace std;

int freq[105];
int a[2 * 105];
int ans[2 * 105];

int main()
{
    int n;
    cin >> n;
    n *= 2;

    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        ++ freq[a[i]];
    }

    int cntt[3] = {0};
    for (int i = 10; i <= 99; ++ i)
        if (freq[i] >= 2) {
            freq[i] = 2;
            int type = 1;
            for (int j = 1; j <= n && freq[i]; ++ j)
                if (a[j] == i) {
                    ans[j] = type;
                    cntt[type] ++;
                    type ^= 3;
                    freq[i] --;
                }
        }

    int type = 1;
    for (int i = 10; i <= 99; ++ i)
        if (freq[i] == 1) {
            for (int j = 1; j <= n; ++ j)
                if (a[j] == i) {
                    ans[j] = type;
                    cntt[type] ++;
                    type ^= 3;
                    break;
                }
        }

    for (int i = 1; i <= n; ++ i)
        if (!ans[i]) {
            ans[i] = type;
            type ^= 3;
        }

    cout << cntt[1] * cntt[2] << '\n';
    for (int i = 1; i <= n; ++ i)
        cout << ans[i] << " \n"[i == n];
    return 0;
}