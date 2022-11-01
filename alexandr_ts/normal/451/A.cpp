#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (!(min(n, m) % 2))
        cout << "Malvika";
    else
        cout << "Akshat";
    return 0;
}