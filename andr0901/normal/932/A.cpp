#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;
    string b = a;
    for (int i = a.size() - 1; i >= 0; i--) b += a[i];
    cout << b;
    return 0;
}