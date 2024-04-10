#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    cin >> str;

    int n = 0;
    n = str.size();

    str = " " + str;

    int nr;
    for (int i = 1; i <= n; ++ i)
        if (str[i] != '0')
            for (int j = i + 1; j <= n; ++ j)
                for (int k = j + 1; k <= n; ++ k) {
                    nr = 100 * (str[i] - '0') + 10 * (str[j] - '0') + str[k] - '0';
                    if (nr % 8 == 0)
                        goto done;
                }

    for (int i = 1; i <= n; ++ i)
        if (str[i] != '0')
            for (int j = i + 1; j <= n; ++ j) {
                nr = 10 * (str[i] - '0') + (str[j] - '0');
                if (nr % 8 == 0)
                    goto done;
            }

    for (int i = 1; i <= n; ++ i)
        if (str[i] == '8' || str[i] == '0') {
            nr = str[i] - '0';
            goto done;
        }

    cout << "NO\n";
    return 0;

    done:;
    cout << "YES\n";
    cout << nr << endl;


    return 0;
}