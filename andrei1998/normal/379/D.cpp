#include <iostream>
#include <string>

#define lint long long int
using namespace std;

bool exists (int n, char b, char e, int x) {
    if (n == 1)
        return ((b == e) && !x);

    if (b == 'A') {
        if (e == 'A')
            return x <= ((n - 1) / 2);
        else if (e == 'B')
            return x <= ((n - 1) / 2);
        else if (e == 'C')
            return x <= (n / 2);
    }
    else if (b == 'B') {
        if (e == 'A')
            return x <= ((n - 2) / 2);
        else if (e == 'B')
            return x <= ((n - 2) / 2);
        else if (e == 'C')
            return x <= ((n - 1) / 2);
    }
    else if (b == 'C') {
        if (e == 'A')
            return x <= ((n - 2) / 2);
        else if (e == 'B')
            return x <= ((n - 2) / 2);
        else if (e == 'C')
            return x <= ((n - 1) / 2);
    }

    cout << "rahat " << endl;
    return -1;
}

string get (int n, char b, char e, int x) {
    string str(n, 'D');
    str[0] = b;
    str[str.size() - 1] = e;

    for (int i = 0; i < n - 1 && x; i++)
        if ((str[i] == 'A' || str[i] == 'D') && (str[i + 1] == 'C' || str[i + 1] == 'D')) {
            str[i] = 'A';
            str[++ i] = 'C';
            x --;
        }

    if (x)
        return "FAILED";
    return str;
}

lint dp[55];
char b[55];
char e[55];

int main()
{
    int k, x, n, m;
    cin >> k >> x >> n >> m;

    for (b[1] = 'A'; b[1] <= 'C'; b[1] ++)
        for (b[2] = 'A'; b[2] <= 'C'; b[2] ++)
            for (e[1] = 'A'; e[1] <= 'C'; e[1] ++)
                for (e[2] = 'A'; e[2] <= 'C'; e[2] ++)
                    for (dp[1] = 0; dp[1] <= n / 2; dp[1] ++)
                        for (dp[2] = 0; dp[2] <= m / 2; dp[2] ++)
                            if (exists(n, b[1], e[1], dp[1]) && exists(m, b[2], e[2], dp[2])){
                                for (int i = 3; i <= k; i++) {
                                    b[i] = b[i - 2];
                                    e[i] = e[i - 1];
                                    dp[i] = dp[i - 1] + dp[i - 2] + (e[i - 2] == 'A') * (b[i - 1] == 'C');
                                }

                                if (dp[k] == x) {
                                    cout << get(n, b[1], e[1], dp[1]) << '\n';
                                    cout << get(m, b[2], e[2], dp[2]) << '\n';

                                    return 0;
                                }
                            }

    cout << "Happy new year!\n";
    return 0;
}