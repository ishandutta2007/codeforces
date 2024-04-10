#include <iostream>

using namespace std;

int put10[8];

int get_dig (int n, int d) {
    return (n / put10[d]) % 10;
}

int main()
{
    put10[0] = 1;
    for (int i = 1; i < 8; i++)
        put10[i] = 10 * put10[i - 1];

    int n = 0;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < 7; i++)
        if (get_dig(n, i) > ans)
            ans = get_dig(n, i);

    cout << ans << '\n';

    int curent = 0;
    while (n) {
        curent = 0;

        for (int i = 0; i < 7; i++)
            if (get_dig(n, i) > 0) {
                curent += put10[i];
                n -= put10[i];
            }

        cout << curent << ' ';
    }

    cout << '\n';

    return 0;
}