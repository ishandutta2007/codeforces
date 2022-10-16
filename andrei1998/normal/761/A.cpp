#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (b < a)
        swap(a, b);

    if (a == 0 && b == 0) {
        cout << "NO\n";
        return 0;
    }
    if (b == a + 1 || b == a)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}