#include <iostream>
#include <cstring>

using namespace std;

char sir[100005];
char sir2[105];

int main()
{
    int n, m;
    cin.get(sir + 1, 100005); cin.get(); n = strlen(sir + 1);
    cin.get(sir2 + 1, 105); cin.get(); m = strlen(sir2 + 1);

    int ans = 0;
    for (int i = 1; i <= n && i + m - 1 <= n; ++ i) {
        int j;
        for (j = 1; j <= m; ++ j)
            if (sir2[j] != sir[i + j - 1])
                break;

        if (j == m + 1) {
            ++ ans;
            i += m;
            -- i;
        }
    }

    cout << ans << '\n';
    return 0;
}