#include <iostream>
#include <algorithm>

using namespace std;

int x[4];
int y[4];

int main()
{
    cin >> x[1] >> y[1];
    cin >> x[2] >> y[2];
    cin >> x[3] >> y[3];

    if (x[1] == x[2] && x[2] == x[3]) {
        cout << "1\n";
        return 0;
    }
    else if (y[1] == y[2] && y[2] == y[3]) {
        cout << "1\n";
        return 0;
    }

    for (int i = 1; i <= 3; ++ i)
        for (int j = i + 1; j <= 3; ++ j) {
            //Incercam cu punctele i si j coliniare

            if (x[i] == x[j]) {
                if (min(y[i], y[j]) >= y[6 - i - j] || y[6 - i - j] >= max(y[i], y[j])) {
                    cout << "2\n";
                    return 0;
                }
            }
            else if (y[i] == y[j]) {
                if (min(x[i], x[j]) >= x[6 - i - j] || x[6 - i - j] >= max(x[i], x[j])) {
                    cout << "2\n";
                    return 0;
                }
            }
        }

    cout << "3\n";
    return 0;
}