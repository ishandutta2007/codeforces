#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int first;
    cin >> first;

    while (first % 2 == 0)
        first >>= 1;
    while (first % 3 == 0)
        first /= 3;

    n --;

    int current;
    while (n --) {
        cin >> current;

        while (current % 2 == 0)
            current >>= 1;
        while (current % 3 == 0)
            current /= 3;

        if (current != first) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}