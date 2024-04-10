#include <iostream>
#include <cstring>

using namespace std;

int n, m;
char mat[1005][1005];

int main()
{
    cin >> n >> m;

    cin.get();

    for (int i = 1; i <= n; ++ i) {
        cin.get(mat[i] + 1, 1005);
        cin.get();
    }

    int ans = 0;
    int sum = 0;
    int sum_last = 0;
    for (int j = 1; j <= m; ++ j) {
        sum = 0;
        for (int i = 1; i <= n; ++ i)
            if (mat[i][j] == 'B')
                ++ sum;

        if (sum > 0 && sum_last == 0)
            ++ ans;
        sum_last = sum;
    }

    cout << ans << '\n';
    return 0;
}