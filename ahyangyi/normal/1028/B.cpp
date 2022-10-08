#include <iostream>

using namespace std;
int main()
{
    int n, m;

    cin >> n >> m;

    int s = (n + 3) / 4;
    for (int i = 0; i < s; ++i)
        cout << 5;
    cout << endl;
    for (int i = 0; i < s; ++i)
        cout << 4 + (i + 1 == s);
    cout << endl;

    return 0;
}