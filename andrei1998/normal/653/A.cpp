#include <iostream>

using namespace std;

int frecv[1005];

int main()
{
    int n;
    cin >> n;

    int val;
    for (int i = 1; i <= n; ++ i) {
        cin >> val;
        frecv[val] = 1;
    }

    for (int i = 1; i <= 1000; ++ i)
        if (frecv[i] && frecv[i + 1] && frecv[i + 2]) {
            cout << "YES\n";
            return 0;
        }

    cout << "NO\n";
    return 0;
}