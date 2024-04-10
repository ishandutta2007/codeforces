#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int minimum = 1e9 + 15;
    int which;
    int cnt = 0;

    for (int i = 1; i <= n; ++ i) {
        int val;
        cin >> val;

        if (val < minimum) {
            minimum = val;
            which = i;
            cnt = 1;
        }
        else if (val == minimum)
            ++ cnt;
    }

    if (cnt > 1)
        cout << "Still Rozdil\n";
    else
        cout << which << '\n';
    return 0;
}