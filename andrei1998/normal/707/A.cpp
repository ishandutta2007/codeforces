#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    char ch;

    bool hascolor = false;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cin >> ch;
            if (ch != 'W' && ch != 'B' && ch != 'G')
                hascolor = true;
        }
    }

    if (hascolor)
        cout << "#Color\n";
    else
        cout << "#Black&White\n";
    return 0;
}