#include <iostream>

#define lint long long int
using namespace std;

const int NMAX = 200005;
int v[NMAX];

int s_part[NMAX];
int s_part2[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, k, x;
    cin >> n >> k >> x;

    lint mult = 1;
    while (k --)
        mult *= x;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    for (int i = 1; i <= n; ++ i)
        s_part[i] = s_part[i - 1] | v[i];
    for (int i = n; i; -- i)
        s_part2[i] = s_part2[i + 1] | v[i];

    lint ans = -1;
    for (int i = 1; i <= n; ++ i) {
        if ((s_part[i - 1] | (v[i] * mult) | s_part2[i + 1]) > ans)
            ans = (s_part[i - 1] | (v[i] * mult) | s_part2[i + 1]);
    }

    cout << ans << '\n';
    return 0;
}