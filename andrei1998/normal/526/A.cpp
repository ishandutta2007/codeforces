#include <iostream>
#include <cstring>

using namespace std;

char sir[105];

int main()
{
    int n = 0;
    cin >> n;

    cin.get();
    cin.get(sir + 1, 105);

    bool ok = false;

    for (int i = 1; i <= n && !ok; i++)
        if (sir[i] == '*')
            for (int j = i + 1; 4 * j - 3 * i <= n; j++)
                if (sir[j] == '*' && sir[2 * j - 1 * i] == '*' && sir[3 * j - 2 * i] == '*' && sir[4 * j - 3 * i] == '*') {
                    ok = true;
                    break;
                }

    if (!ok)
        cout << "no\n";
    else
        cout << "yes\n";

    return 0;
}